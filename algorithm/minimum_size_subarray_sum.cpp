#include<iostream>
#include <vector>

/**
 *题目:
 *给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s
 * 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
 *
 * 解法：就是不断的调节子序列的起始位置和终止位置，从而得出我们要想的结果
 */


int minSubArrayLen(std::vector<int>& nums, int s) {
    int result = INT32_MAX;
    int sum = 0; //滑动窗口数值之和
    int i = 0; //滑动窗口起始位置
    int subLength = 0;//滑动窗口的长度
    for (int j = 0; j < nums.size(); j++) {
        sum += nums[j];
        //注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
        while(sum >= s) {
            subLength = (j - i + 1); //取子序列的长度
            result = result < subLength ? result : subLength;
            sum -= nums[i++]; //这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
        }
    }
    //如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
    return result == INT32_MAX ? 0 : result;
}

int main(int argc, char** argv) {
    std::vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(3);
    
    int s = 7;
    int result = minSubArrayLen(nums,7);
    std::cout << "result is:" << result << std::endl;
    
    return 0;
}
