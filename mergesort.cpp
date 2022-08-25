#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void mergeSort2(vector<int>&left, vector<int>& right, vector<int>& bars);

void mergesort(vector<int> & arr) {
    if (arr.size() <= 1) return;

    int mid = arr.size() / 2;
    vector<int> left;
    vector<int> right;

    for (size_t j = 0; j < mid;j++)
        left.push_back(arr[j]);
    for (size_t j = 0; j < (arr.size()) - mid; j++)
        right.push_back(arr[mid + j]);

    mergesort(left);
    mergesort(right);
    mergeSort2(left, right, arr);
}
void mergeSort2(vector<int>&left, vector<int>& right, vector<int>& bars)
{
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR)
    {
        if (left[j] < right[k]) {
            bars[i] = left[j];
            j++;
        }
        else {
            bars[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < nL) {
        bars[i] = left[j];
        j++; i++;
    }
    while (k < nR) {
        bars[i] = right[k];
        k++; i++;
    }
}

int main()
{
vector<int> vect;
vect.push_back(10);
    vect.push_back(20);
    vect.push_back(56);
     vect.push_back(57);
      vect.push_back(2);
       vect.push_back(1);
mergesort(vect);
for (int i = 0; i < vect.size(); i++)
      cout << vect[i] << " ";
    return 0;
}
