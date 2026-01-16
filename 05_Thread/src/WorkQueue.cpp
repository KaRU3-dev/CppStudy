#include "WorkQueue.h"

namespace ThreadStudy::ThreadWorkers
{
    void WorkerTree::Service(std::stop_token st)
    {
        while (!st.stop_requested())
        {
            if (!taskQueue.empty())
            {
                // Pop ended task
                taskQueue.pop();
                continue;
            }

            // Wait all task queue //TODO: Queue space base controle
            std::unique_lock<std::mutex> lock(queueLockKey);
            taskQueueCondition.wait(lock, [this]
                                    { return taskQueue.empty(); });

            // std::cout << "Queue is empty! Adding data...\n";

            // Add task
            taskQueue.push(23);
            taskQueueCondition.notify_one();

            // Show all task.Queue
            for (int i = 0; i < taskQueue.size(); i++)
            {
                // std::cout << taskQueue.front() << "\n";
            }

            // TODO: If still not run task is available in queue, run task

            // Unlock Queue
            lock.unlock();
        }
    }

    void WorkerTree::Start()
    {
        std::stop_token st;
        serviceToken = st;
        auto thread = std::make_unique<std::jthread>(&WorkerTree::Service, this, std::ref(serviceToken));
        serviceThread = std::move(thread);
        serviceThread->detach();
    }

    void WorkerTree::Stop()
    {
        std::cout << "Stopping...\n";
        serviceThread->request_stop();
        std::cout << "Service stopped.\n";
    }
}
