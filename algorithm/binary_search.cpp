#include<iostream>
#include <vector>
/**
 *有序数组的二分查找算法
 */
using namespace std;

int binary_search(int* nums, int size,int target) {
    int left = 0;
    int right  = size - 1;//定义target在左闭右闭的区间里，[left, right]
    while (left <= right) { //当left==right，区间[left, right]依然有效，所以用 <=
        int middle = left + ((right - left) /2); // 防止溢出 等同于(left + right)/2
        if (nums[middle] > target) {
            right = middle - 1; // target 在左区间，所以[left, middle - 1]
        } else if (nums[middle] < target) {
            left = middle + 1; // target 在右区间，所以[middle + 1, right]
        } else {
            return middle;
        }
    }
    //未找到target
    return -1;
}

int main(int argc,char** argv)
{
  //test
  int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
  int pos = binary_search(arr,12,7);
  printf("target 7 is at:%d \n",pos);
  return 0;
}
