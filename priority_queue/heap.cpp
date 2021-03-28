#include <algorithm>
#include <vector>
#include <iostream>

// 1. 모양 규칙 우선 -> 대소 관계 규칙 적용

using namespace std;

void PushHeap(vector<int>& heap, int newValue);
void PopHeap(vector<int>& heap);

int main() {
  int inputCnt, newValue;
  cin >> inputCnt;

  vector<int> heap;
  for(int i = 0; i < inputCnt; i++) {
    cin >> newValue;
    PushHeap(heap, newValue);
  }
  
  int outputCnt = heap.size();
  for(int i = 0; i < outputCnt; i++) {
    cout << heap[0];
    PopHeap(heap);
  }

  return 0;
}


void PushHeap(vector<int>& heap, int newValue){
  heap.push_back(newValue);
  int idx = heap.size() - 1;
  while(idx > 0 && heap[(idx - 1)/2] < heap[idx]) {
    swap(heap[idx], heap[(idx-1)/2]);
    idx = (idx-1) / 2;
  }
}

void PopHeap(vector<int>& heap) {
  heap[0] = heap.back();
  heap.pop_back();
  int here = 0;
  while(true){
    int left = here * 2 + 1;
    int right = here * 2 + 2;
    if(left >= heap.size()) break;
    int next = here;
    if(heap[next] < heap[left]) next = left;
    if(right < heap.size() && heap[next] < heap[right]) next = right;
    if(next == here) break;
    swap(heap[here], heap[next]);
    here = next;
  }
}

