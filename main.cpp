#include <iostream>
#include <vector>
#include <algorithm>
#include "reload.h"

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  int len = range_end - range_begin;
  if (len < 2) {
    return;
  }
  vector<typename RandomIt::value_type> elements(range_begin, range_end);
  vector<typename RandomIt::value_type> tmp;
  int half = len / 3;
  MergeSort(elements.begin(), elements.begin() + half);
  MergeSort(elements.begin() + half, elements.begin() + half * 2);
  MergeSort(elements.begin() + half * 2, elements.begin() + len);
  merge(
      elements.begin(), elements.begin() + half,
      elements.begin() + half, elements.begin() + half * 2,
      back_inserter(tmp)
  );
  merge(
      elements.begin() + half * 2, elements.begin() + len,
      tmp.begin(), tmp.end(),
      range_begin
  );
}

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
//  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}