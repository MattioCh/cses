

using namespace std;
#include <iostream>;

void heapify(int arr[], int N, int index)
{
    int largest = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    if (left < N && arr[left] > arr[largest])
    {
        largest = left;o
    }

    if (right < N && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, N, largest);
    }
}

void build_heap(int arr[], int N)
{
    int last_non_leaf_node = (N / 2) - 1;
    for (int i = last_non_leaf_node; i >= 0; i--)
    {
        heapify(arr, N, i);
    }
}

void print_heap(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int N = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < N; i++)
    {
        // cout << arr[i];
    }
    build_heap(arr, N);
    print_heap(arr, N);
}
