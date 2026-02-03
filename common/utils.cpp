// copied from somewhere on github (the Unlicense)
#include <fstream>

bool is_letter(char c) {
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char lowercase(char c) {
	return c + ('a' - 'A');
}

char uppercase(char c) {
	return c - ('a' - 'A');
}

bool is_digit(char c) {
	return (c >= '0' && c <= '9');
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
	return (a / gcd(a, b)) * b;
}

long long file_size(std::fstream& file) {
	file.seekg(0, std::ios::end);
	long long size = file.tellg();
	file.seekg(0, std::ios::beg);
	return size;
}

static void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort_iterative(int arr[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - 1 - i; ++j) {
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

static void bubble_sort_recursive_helper(int arr[], int n) {
	if (n <= 1)
		return;
	for (int i = 0; i < n - 1; ++i) {
		if (arr[i] > arr[i + 1])
			swap(&arr[i], &arr[i + 1]);
	}
	bubble_sort_recursive_helper(arr, n - 1);
}

void bubble_sort_recursive(int arr[], int n) {
	bubble_sort_recursive_helper(arr, n);
}

void selection_sort_iterative(int arr[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		int min_idx = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		swap(&arr[i], &arr[min_idx]);
	}
}

static void selection_sort_recursive_helper(int arr[], int start, int n) {
	if (start >= n - 1)
		return;
	int min_idx = start;
	for (int j = start + 1; j < n; ++j) {
		if (arr[j] < arr[min_idx])
			min_idx = j;
	}
	swap(&arr[start], &arr[min_idx]);
	selection_sort_recursive_helper(arr, start + 1, n);
}

void selection_sort_recursive(int arr[], int n) {
	selection_sort_recursive_helper(arr, 0, n);
}

void insertion_sort_iterative(int arr[], int n) {
	for (int i = 1; i < n; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void insertion_sort_recursive(int arr[], int n) {
	if (n <= 1)
		return;
	insertion_sort_recursive(arr, n - 1);
	int key = arr[n - 1];
	int j = n - 2;
	while (j >= 0 && arr[j] > key) {
		arr[j + 1] = arr[j];
		j--;
	}
	arr[j + 1] = key;
}

static int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j < high; ++j) {
		if (arr[j] <= pivot) {
			++i;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}

void quick_sort_recursive(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quick_sort_recursive(arr, low, pi - 1);
		quick_sort_recursive(arr, pi + 1, high);
	}
}

void merge_inplace(int arr[], int l, int m, int r) {
	int i = l;
	int j = m + 1;
	if (arr[m] <= arr[j])
		return;

	while (i <= m && j <= r) {
		if (arr[i] <= arr[j]) {
			i++;
		} else {
			int value = arr[j];
			int idx = j;
			while (idx > i) {
				arr[idx] = arr[idx - 1];
				idx--;
			}
			arr[i] = value;
			i++;
			m++;
			j++;
		}
	}
}

void merge_sort_inplace(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		merge_sort_inplace(arr, l, m);
		merge_sort_inplace(arr, m + 1, r);
		merge_inplace(arr, l, m, r);
	}
}

void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; ++i)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; ++j)
		R[j] = arr[m + 1 + j];

	int i = 0, j = 0, k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}

	while (i < n1)
		arr[k++] = L[i++];
	while (j < n2)
		arr[k++] = R[j++];

	delete[] L;
	delete[] R;
}

void merge_sort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
