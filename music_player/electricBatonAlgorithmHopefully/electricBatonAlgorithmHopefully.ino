vector<int> step1(vector<double> accel, vector<double> times){
    vector<int> changeTimesI ={};
    for(int i = 0; i<accel.size()-1; i++){
	    if(accel[i]>0 && accel[i+1] <0){ // if current >0 and next<0
		    changeTimesI.push_back(i); // add time to changeTimes
        }
    }
    return changeTimesI;
}

vector<double> step2Slice(vector<double> accel, int s, int e){ //s=start index, e=end index
     // Starting and Ending iterators
    auto start = accel.begin() + s;
    auto end = accel.begin() + e + 1;

    // To store the sliced vector
    vector<double> result(e - s + 1);

    // Copy vector using copy function()
    copy(start, end, result.begin());

    // Return the final sliced vector
    return result;
}

int step2Max(vector<double> slice){
    double max = 0.00;
    int maxIndex = 0;
    for(int i =2; i<slice.size(); i++){
        double val = slice[i];
        if(val>max){
            max = val;
            maxIndex = i;
        }
    }
    return maxIndex;
}
vector<int> step2(vector<double> accel, vector<double> times, vector<int>changeTimesI){
    vector<int> indexesOfMaxes ={};
    for(int i = 0; i<changeTimesI.size()-1;i++){
        vector<double> slice = step2Slice(accel, changeTimesI[i], changeTimesI[i+1]);
        int maxIndexForSlice = step2Max(slice);
        indexesOfMaxes.push_back(maxIndexForSlice+changeTimesI[i]);
    }
    return indexesOfMaxes;
}


vector<double> step3(vector<int> indexesOfMaxes, vector<double> times){
    vector<double> maxTimes = {};
    for(int i = 0; i<indexesOfMaxes.size(); i++){
        int index = indexesOfMaxes[i];
        maxTimes.push_back(times[index]);
    }
    vector<double> intervals = {};
    for (int i = 0; i<maxTimes.size()-1; i++){
        double interval = maxTimes[i+1] - maxTimes[i];
        intervals.push_back(interval);
    }
    return intervals;
}

double step4(vector<double> intervals){
    double sum = 0;
    for(int i = 0; i<intervals.size();i++){
        sum+=intervals[i];
    }
    double avg = sum/intervals.size();
    return avg;
}

double step5(double avg){
    return 60/avg;
}