#include <thread>
#include <iostream>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <future>

#include "WorkQueue.h"

void worker(std::atomic<bool> &shouldCancel)
{
    while (!shouldCancel.load())
    {
        std::cout << "running...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // デバッグ用途でのみこれを使うようにする
    }

    std::cout << "stopped.\n";
}

std::mutex mtx;  // スコープ内で利用するデータをロックするための鍵
int counter = 0; // 共有データ

void worker2()
{
    std::lock_guard<std::mutex> lock(mtx);
    counter++; // counterはこのスレッド専有
    std::cout << counter << "\n";
} // ここで必ず unlock される（専有が解除）

void worker3()
{
    std::unique_lock<std::mutex> lock(mtx);

    if (counter >= 10)
    {
        lock.unlock();
        counter = 0;
    }
    else
    {
        counter++;
        std::cout << counter << "\n";
    }
} // unlock

std::mutex mtx2; // mutexへの紐づけはプログラマ次第
std::condition_variable cv;
std::queue<int> q;
void worker4_producer()
{
    {
        std::lock_guard<std::mutex> lock(mtx2); // 条件待ちの間はアンロックされているので（このスレッドではmtx2を使ってqをロックしてある）、
        q.push(42);                             // pushが安全に可能
    }
    cv.notify_one();

    // ここでq.pushを試みるとロックがかかっている
}
void worker4()
{
    std::unique_lock<std::mutex> lock(mtx2); // 条件待ちしてる際は、アンロックされる↑
    cv.wait(lock, []
            { return !q.empty(); }); // cv.waitでこのスレッドを条件式が満たされるまで眠らせることができる (この場合は、qが空ではなくなったときにwait()から抜け出す)
    // wait中はこのスレッドでは、mtx2はunlockされる

    // 条件待ちが終わったので、mtx2（q）がロックされる

    // wait() が終わったら、下の処理が走る
    // ...
}

int worker5(std::int32_t x, std::int32_t y)
{
    return x + y;
}
void run_worker5()
{
    // mutexの実装がいらない
    std::future<std::int32_t> w = std::async(std::launch::async, worker5, 1, 2); // 定義した時点で、worker5タスクを実行
    std::cout << w.get() << "\n";                                                // w.get() で完了待ち（一度だけ呼べる）
}

// std::jthread t(worker); // std::stop_tokenが自動的に割り当てられる
// std::this_thread::sleep_for(std::chrono::seconds(2));

// ThreadStudy::ThreadWorkers::WorkerTree w;
// w.Start();
// std::this_thread::sleep_for(std::chrono::seconds(2));

// std::cout << "Stop test\n";

// w.Stop();
int main()
{
    ThreadStudy::ThreadWorkers::Task<int> task1(worker5, 1, 2);
    task1.Run();
    std::cout << task1.getResult() << "\n";

    ThreadStudy::ThreadWorkers::Task<void> task2(worker);
    task2.Run();
    task2.getResult();

    // ここで、jthredが破棄され、stop_tokenが有効化される
} // ここで、join()が自動付与され、安全にスレッドが終了する
