#include <iostream>
#include <vector>
using namespace std;
vector<int> step1(vector<float> accel, vector<float> times){
    vector<int> changeTimesI ={};
    for(int i = 0; i<accel.size()-1; i++){
	    if(accel[i]>0 && accel[i+1] <0){ // if current >0 and next<0
		    changeTimesI.push_back(i); // add time to changeTimes
        }
    }
    return changeTimesI;
}

vector<int> step2(vector<float> accel, vector<float> times, vector<int>changeTimesI){
    vector<int> indexesOfMaxes ={};
    for(int i = 0; i<changeTimesI.size()-1;i++){
        vector<float> slice = step2Slice(accel, changeTimesI[i], changeTimesI[i+1]);
        int maxIndexForSlice = step2Max(slice);
        indexesOfMaxes.push_back(maxIndexForSlice+changeTimesI[i]);
    }
    return indexesOfMaxes;
}

vector<float> step2Slice(vector<float> accel, int s, int e){ //s=start index, e=end index
     // Starting and Ending iterators
    auto start = accel.begin() + s;
    auto end = accel.begin() + e + 1;

    // To store the sliced vector
    vector<float> result(e - s + 1);

    // Copy vector using copy function()
    copy(start, end, result.begin());

    // Return the final sliced vector
    return result;
}

int step2Max(vector<float> slice){
    float max = 0.00;
    int maxIndex = 0;
    for(int i =2; i<slice.size(); i++){
        float val = slice[i];
        if(val>max){
            max = val;
            maxIndex = i;
        }
    }
    return maxIndex;
}

vector<float> step3(vector<int> indexesOfMaxes, vector<float> times){
    vector<float> maxTimes = {};
    for(int i = 0; i<indexesOfMaxes.size(); i++){
        int index = indexesOfMaxes[i];
        maxTimes.push_back(times[index]);
    }
    vector<float> intervals = {};
    for (int i = 0; i<maxTimes.size()-1; i++){
        float interval = maxTimes[i+1] - maxTimes[i];
        intervals.push_back(interval);
    }
    return intervals;
}

float step4(vector<float> intervals){
    float sum = 0;
    for(int i = 0; i<intervals.size();i++){
        sum+=intervals[i];
    }
    float avg = sum/intervals.size();
    return avg;
}

float step5(float avg){
    return 60/avg;
}




