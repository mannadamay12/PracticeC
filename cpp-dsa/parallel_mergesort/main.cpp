#include<iostream>
#include "sort/mergesort.hpp"
#include "sort/parallelMS.hpp"

int main(int argc, char *argv[]){
    const int SIZE = 1000000;
    std::vector<int> nums(SIZE);
    std::vector<int> nums1(SIZE);
    for(int i = 0; i<SIZE; i++){
        nums[i] = rand()%1000000;
        nums1[i] = rand()%1000000;

    }
    MergeSort *ms = new MergeSort(&nums);
    auto start = std::chrono::high_resolution_clock::now();
    ms->sort();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end-start;
    std::cout << "Time taken by mergesort: " << elapsed.count() << " seconds" << std::endl;
    delete ms;

    ParallelMergeSort *pms = new ParallelMergeSort(&nums);
    start = std::chrono::high_resolution_clock::now();
    pms->sort();
    end = std::chrono::high_resolution_clock::now();
    elapsed = end-start;
    std::cout << "Time taken by parallel mergesort: " << elapsed.count() << " seconds" << std::endl;
    delete pms;
}