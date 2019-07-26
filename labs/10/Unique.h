class Unique {
public:
	static bool unique(int* A, int n);
private:
	static void merge(int arr[], int left, int mid, int right, int length);
	static void mergeSort(int arr[], int left, int right, int length);
};