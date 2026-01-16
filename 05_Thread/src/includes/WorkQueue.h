#pragma once

#include <iostream>
#include <array>
#include <cstdint>
#include <functional>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <future>

#ifndef WORKQUEUE_H
#define WORKQUEUE_H

namespace ThreadStudy::ThreadWorkers
{
    template <typename T>
    class Task
    {
    private:
        std::function<T()> worker;
        std::future<T> workSpace;
        std::atomic<bool> shouldCancel = false;

    public:
        template <typename F, typename... Args>
        Task(F&& func, Args&&... args)
        {
            using FunctionType = std::decay_t<F>;

            // Check if the function supports cancellation (i.e., takes atomic<bool>& as first arg)
            if constexpr (std::is_invocable_v<FunctionType, std::atomic<bool>&, Args...>) {
                worker = [this, f = std::forward<F>(func), args_tuple = std::make_tuple(std::forward<Args>(args)...)]() mutable -> T {
                    return std::apply([&](auto&&... a){ return f(std::ref(this->shouldCancel), a...); }, std::move(args_tuple));
                };
            } else { // Function does not support cancellation
                worker = [f = std::forward<F>(func), args_tuple = std::make_tuple(std::forward<Args>(args)...)]() mutable -> T {
                    return std::apply(f, std::move(args_tuple));
                };
            }
        }

        void Run()
        {
            workSpace = std::async(std::launch::async, worker);
        }

        void Cancel()
        {
            shouldCancel.store(true);
        }

        auto getResult()
        {
            if constexpr (std::is_void_v<T>)
            {
                workSpace.get();
            }
            else
            {
                return workSpace.get();
            }
        }
    };

    // 1. jthreadでWorkerTreeを起動する
    class WorkerTree
    {
    private:
        /**
         * サービススレッドのキャンセル検知用のトークン
         */
        std::stop_token serviceToken;
        /**
         * サービスのスレッド
         */
        std::unique_ptr<std::jthread> serviceThread;

        /**
         * タスクのキューのロックの鍵
         */
        std::mutex queueLockKey;
        /**
         * タスクのキュー
         */
        std::queue<int> taskQueue;
        /**
         * タスクのキューの条件変数
         */
        std::condition_variable taskQueueCondition;

        /**
         * 走らせるタスクの量を調整するサービス関数
         */
        void Service(std::stop_token st);

    public:
        WorkerTree() {}

        /**
         * 実行するタスクの量を自動調整するサービスを起動し、変数に登録する関数
         */
        void Start();
        /**
         * 実行するタスクの量を自動調整するサービスの停止をリクエストする関数
         */
        void Stop();
    };
}

#endif // WORKQUEUE_H
