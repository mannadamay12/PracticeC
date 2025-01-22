#include "parallelMS.hpp"

ParallelMergeSort::ParallelMergeSort(std::vector<int> *nums)
    : nums(nums){
}

ParallelMergeSort::~ParallelMergeSort(){}

void ParallelMergeSort::recursiveSort(int left, int right){
    const int THRESHOLD = 5000;
    if(right-left<=THRESHOLD){
        std::sort(nums->begin()+left, nums->begin()+right+1);
        return;
    }

    if(left>=right){
        return;
    }
    int mid = left + (right-left)/2;

    std::thread t1([this, left, mid]{
        this->recursiveSort(left, mid);
    });
    std::thread t2([this, mid, right]{
        this->recursiveSort(mid+1, right);
    });

    t1.join();
    t2.join();

    std::vector<int> result;
    int i = left;
    int j = mid+1;
    while(i<=mid && j<=right){
        if((*nums)[i] < (*nums)[j]){
            result.push_back((*nums)[i]);
            i++;
        }else{
            result.push_back((*nums)[j]);
            j++;
        }
    }
    while(i<=mid){
        result.push_back((*nums)[i]);
        i++;
    }
    while(j<=right){
        result.push_back((*nums)[j]);
        j++;
    }
    for(int k = 0; k<result.size(); k++){
        (*nums)[left+k] = result[k];
    }
    return;
}

void ParallelMergeSort::sort(){
    if((*nums).size() == 0){
        return;
    }
    std::thread t([this]{
        this->recursiveSort(0, (*nums).size());
    });
    t.join();
    // for(int i = 0; i<(*nums).size(); i++){
    //     std::cout << (*nums)[i] << " ";
    // }
}