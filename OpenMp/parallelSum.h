//
// Created by YANG QI on 5/20/22.
//


#include <mutex>
#include <thread>
#include "omp.h"

template<typename T>
class parallelSum {
public:
    struct result{
        T sum;
        double time;
    };

    result res1;
    result res2;
    result res3;

    auto parallel_sum_std(T a[], size_t N, size_t num_threads){
        T globalSum = 0;
        std::thread thread_object[num_threads];

        auto start = std::chrono::steady_clock::now();
//        clock_t start, end;
//        double cpu_time_taken;
//        start = clock();

        for (size_t id = 0; id < num_threads; id++){
           // std::cout<< "The thread number is :" << id <<"\n";

            thread_object[id] = std::thread([&,id]{
                //lambda expression thread function
                T curr_threadSum = 0;
                size_t startPart= id * (N/num_threads);
                size_t endPart = startPart + (N/num_threads);
                for (size_t i = startPart; i < endPart;i++){
                    curr_threadSum += a[i];
                }

              // std::cout<< "The thread sum is :" << curr_threadSum <<"\n";
                globalSum += curr_threadSum;
            });
        }

        for (size_t id = 0; id < num_threads;id++){
            thread_object[id].join();
        }

        //add the left numbers which are unassigned to compute in any thread
        size_t restOfNum = N - (N/num_threads * num_threads);
        if (restOfNum != 0) {
            for (size_t i = N - restOfNum; i < N; i++) {
                globalSum += a[i];
            }
        }
//        end = clock();
//        cpu_time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
//        res1.time = cpu_time_taken;

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;

        res1.sum = globalSum;
        res1.time = elapsed_seconds.count();

        return res1;
    }


    auto parallel_sum_omp1(T a[], size_t N, size_t num_threads){
        std::atomic<T> globalSum(0);
        omp_set_num_threads(num_threads);
        auto start = std::chrono::steady_clock::now();

        #pragma omp parallel
        {
            T curr_threadSum = 0;
            int threadId = omp_get_thread_num();
            size_t threadNum = omp_get_num_threads();
            for (int i = threadId; i < N; i += threadNum){
                curr_threadSum += a[i];
            }
        #pragma omp critical
            globalSum += curr_threadSum;
        }

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;

        res2.sum = globalSum;
        res2.time = elapsed_seconds.count();

        return res2;
    }


    auto parallel_sum_omp_builtin(T a[], size_t N, size_t num_threads){
        omp_set_num_threads(num_threads);
        T globalSum = 0;
        auto start = std::chrono::steady_clock::now();
#pragma omp parallel for reduction(+:globalSum)
        for (size_t i = 0; i < N; i++){
            globalSum += a[i];
        }
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;

        res3.sum = globalSum;
        res3.time = elapsed_seconds.count();

        return res3;
    }

};


