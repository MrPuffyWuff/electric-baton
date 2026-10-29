#include "bits/stdc++.h"
using namespace std;
vector<float> step1(vector<float> accel, vector<float> times){
    vector<float> changeTimes ={}
    for(int i = 0; i<accel.size()-1; i++){
	    if(accel[i]>0 && accel[i+1] <0){ // if current >0 and next<0
		    changeTimes.push_back(times[i]); // add time to changeTimes
        }
    {
    return changeTimes;
}

// C++ program for the above approach

// Function to slice a given vector
// from range X to Y
vector<int> slicing(vector<int>& arr,
                    int X, int Y)
{

    // Starting and Ending iterators
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y + 1;

    // To store the sliced vector
    vector<int> result(Y - X + 1);

    // Copy vector using copy function()
    copy(start, end, result.begin());

    // Return the final sliced vector
    return result;
}

// Function to print the vector ans
void printResult(vector<int>& ans)
{

    // Traverse the vector ans
    for (auto& it : ans) {

        // Print elements
        cout << it << ' ';
    }
}

// Driver Code
int main()
{

    // Given vector
    vector<int> arr = { 1, 3, 4, 2,
                        4, 2, 1 };

    // Given range
    int X = 2, Y = 5;

    // Function Call
    vector<int> ans;
    ans = slicing(arr, X, Y);

    // Print the sliced vector
    printResult(ans);
}
