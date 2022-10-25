# define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<time.h>
//��֤����ִ��ʱ��
//int main() {
//	clock_t start = clock();
//	int n = 0;
//	for (int i = 0; i < 10000; i++) {
//		n--;
//	}
//	clock_t end = clock();
//	printf("%lf\n", (double)(end - start) / CLOCKS_PER_SEC);  //��λΪ��
//	printf("%lf\n", (double)(end - start));  //��λΪ����
//	return 0;
//}

//��ʧ������
//����һ�����飬��СΪN��������0 - N��ȱ��һ�����֣����ҳ�
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
//ʱ�临�Ӷȣ�2^0 + 2^1 + 2^2 + ��������������+ 2^(n-1)  �ȱ�������� 2��1 - 2^n) / (1 -2) 
//ʱ�临�Ӷ�O(2^n) --- ����n=10����2^10 = 1024
//�ݹ��쳲��������м��㵽2^40�����ԣ�1w�ڣ����5s����2^50�η��͵úܾ��ˣ���ģΪ1000w�ڣ�5000s��

//��ת����
void rotate2(int* nums, int numsSize, int k) {
    int tmp[7] = { 0 };
    int j = 0;
    for (int i = numsSize - k; i < numsSize; i++) {
        tmp[j] = nums[i];
        j++;
    }
    //�ٰ�nums�����ǰn-k��Ԫ�ط���
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