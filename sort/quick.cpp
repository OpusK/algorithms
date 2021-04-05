#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void QuickSort(vector<int> &array, int left, int right);

int main() {
  int inputCnt, newValue;
  cin >> inputCnt;

  vector<int> array;
  for (int i = 0; i < inputCnt; i++) {
    cin >> newValue;
    array.push_back(newValue);
  }
  QuickSort(array, 0, array.size() - 1);

  cout << " Result: ";
  int outputCnt = array.size();
  for (int i = 0; i < outputCnt; i++) {
    cout << array[i] << " ";
  }
  cout << endl;

  return 0;
}

void QuickSort(vector<int> &array, int left, int right) {
  if (left >= right)
    return;

  swap(array[left], array[(left + right) / 2]);
  int pivot_idx = left;

  int pivot = array[pivot_idx];
  int curr_l = left, curr_r = right;

  while (curr_l < curr_r) {
    while (pivot < array[curr_r])
      curr_r--;
    while (curr_l < curr_r && pivot >= array[curr_l])
      curr_l++;
    if (curr_l != curr_r) {
      // cout << "swap : " << array[curr_l] << " " << array[curr_r] << endl;
      swap(array[curr_l], array[curr_r]);
    }
  }
  swap(array[pivot_idx], array[curr_l]);

  QuickSort(array, left, curr_l - 1);
  QuickSort(array, curr_l + 1, right);
}
