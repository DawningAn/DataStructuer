# define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<time.h>
//验证具体执行时间
//int main() {
//	clock_t start = clock();
//	int n = 0;
//	for (int i = 0; i < 10000; i++) {
//		n--;
//	}
//	clock_t end = clock();
//	printf("%lf\n", (double)(end - start) / CLOCKS_PER_SEC);  //单位为秒
//	printf("%lf\n", (double)(end - start));  //单位为毫秒
//	return 0;
//}

//消失的数字
//给定一个数组，大小为N，其中在0 - N中缺少一个数字，试找出
//int findNum(int* arr, int N) {
//	int tmp = 0;
//	for (int i = 0; i < N+1; i++) {
//		tmp ^= i;
//	}
//	for (int i = 0; i < N; i++) {
//		tmp ^= arr[i];
//	}
//	return tmp;
//}
//int main() {
//	int arr[9] = { 0,1,2,3,8,9,4,6,5 };
//	int ret = findNum(arr, sizeof(arr) / sizeof(arr[0]));
//	printf("%d\n", ret);
//	return 0;
//}

//long long Fib(int n) {
//	if (n <= 2) {
//		return 1;
//	}
//	return Fib(n - 1) + Fib(n - 2);
//}
//int main() {
//	int N = 10;
//	printf("%lld\n",Fib(N));
//	return 0;
//}
//时间复杂度：2^0 + 2^1 + 2^2 + ·······+ 2^(n-1)  等比数列求和 2（1 - 2^n) / (1 -2) 
//时间复杂度O(2^n) --- 这里n=10就是2^10 = 1024
//递归的斐波那契数列计算到2^40还可以（1w亿，大概5s），2^50次方就得很久了（规模为1000w亿，5000s）

//轮转数组
void rotate2(int* nums, int numsSize, int k) {
    int tmp[7] = { 0 };
    int j = 0;
    for (int i = numsSize - k; i < numsSize; i++) {
        tmp[j] = nums[i];
        j++;
    }
    //再把nums数组的前n-k个元素放入
    for (int i = 0; i < numsSize - k; i++) {
        tmp[j] = nums[i];
        j++;
    }
    for (int i = 0; i < numsSize; i++) {
        nums[i] = tmp[i];
    }
}

void reverse(int* start, int* end) {
    while (start <= end) {
        int tmp = *end;
        *end = *start;
        *start = tmp;
        start++;
        end--;
    }
}
void rotate3(int* nums, int numsSize, int k) {
    k %= numsSize;
    reverse(nums + numsSize - k, nums + numsSize - 1);
    reverse(nums, nums + numsSize - k - 1);
    reverse(nums, nums + numsSize - 1);
}
int main() {
    int arr[7] = { 1, 2, 3, 4, 5, 6, 7 };
    int k = 3;
    int len = sizeof(arr) / sizeof(arr[0]); 
    rotate2(arr, len, k);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}