#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const int MAX_N = 1004;
int N, arr1[MAX_N], temp[MAX_N];
void input() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr1[i]);
	}
}

void mergeSort(int* arr, int st, int en)
{
	if (st >= en) return;
	int m = (st + en) / 2;
	mergeSort(arr, st, m);
	mergeSort(arr, m + 1, en);
	int i = st, j = m + 1;
	for (int k = st; k <= en; k++){
		if (j > en) temp[k] = arr[i++];
		else if (i > m) temp[k] = arr[j++];
		else if (arr[i] <= arr[j]) temp[k] = arr[i++];
		else temp[k] = arr[j++];
	}
	for (int k = st; k <= en; k++) arr[k] = temp[k];
	for (int k = 0; k < N; k++){
		printf("%d ", arr[k]);
	}
	printf("\n");
}

int main()
{
	//freopen("input.txt", "r", stdin);
	input();
	mergeSort(arr1, 0, N - 1);
	return 0;
}