#include<iostream>
#include <vector>
/**
 *给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val
 *的元素，并返回移除后数组的新长度
 *
 *解法：双指针法
 */
using namespace std;

int remove_element(int* nums, int size, int val) {
    int slowPtr = 0;
    for(int fastPtr = 0; fastPtr < size; fastPtr++) {
        if (val != nums[fastPtr]) {
            nums[slowPtr++] = nums[fastPtr];
        }
    }
    return slowPtr;
}

int main(int argc,char** argv)
{
  //test
  int arr[] = {1,2,3,4,10,6,7,8,9,10,11,12};
  int count = remove_element(arr, 12,10);
  printf("remove 10 has all:%d count\n",count);
  return 0;
}
