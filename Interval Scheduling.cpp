#include<iostream>
#include<vector>
#include<iomanip>
#include <windows.h> // WinApi header 
using namespace std;



void bubbleSort(int *endTimes,int *startTimes,char *jobNames, int n){
    bool swapped = true;
    int j = 0;
    int temp;

    while (swapped)
    {
        swapped = false;
        j++;
        for (int i = 0; i < n - j; ++i)
        {
            if (endTimes[i] > endTimes[i + 1])
            {
                temp = endTimes[i];
                endTimes[i] = endTimes[i + 1];
                endTimes[i + 1] = temp;
                
                temp = startTimes[i];
                startTimes[i] = startTimes[i + 1];
                startTimes[i + 1] = temp;
                
                temp = jobNames[i];
                jobNames[i] = jobNames[i + 1];
                jobNames[i + 1] = temp;
                
                swapped = true;
            }
        }
    }
}

void printArray(int *endTimes,int *startTimes,char *jobNames, int n){
	cout << setw(12) <<"Job Names" << "\t" << setw(12) << "Start Times" << "\t" << setw(12)<< "End Times" << endl;
    for (int i = 0; i < n; ++i){
        cout << setw(8)<<jobNames[i] << "\t";
        cout << setw(8)<<startTimes[i] << "\t";
        cout << setw(8)<<endTimes[i] << endl;
	}
}


int main(){
	
	char jobNames[] = {'a','b','c','d','e','f','g','h'};
	int endTimes[] = {6,4,5,8,7,9,10,11};
	int startTimes[] = {0,1,3,3,4,5,6,8};
	
	int sizeOfEndTimes = sizeof(endTimes)/sizeof(endTimes[0]);
	int sizeOfStartTimes = sizeof(startTimes)/sizeof(startTimes[0]);
	int sizeOfJobNames = sizeof(jobNames)/sizeof(jobNames[0]);
	int numberOfElements = 0; //Initiation value
		
	if(sizeOfEndTimes != sizeOfStartTimes || sizeOfJobNames != sizeOfStartTimes){ //Size error
		cout << "Size is wrong" <<'\a'<< endl;
		Beep(440,500);
		Sleep(100);
	}
	else{
		numberOfElements = sizeOfEndTimes;
	}
	
	//Short about the endTime
	bubbleSort(endTimes,startTimes,jobNames,sizeOfEndTimes);
	printArray(endTimes,startTimes,jobNames,sizeOfEndTimes); //Make sure
	
	vector<char> schedulingVector; 
	schedulingVector.push_back(jobNames[0]);
	
	int j = 0 ;
	for(int i = 0 ; i < numberOfElements-1 ; i++){
		if(endTimes[j] <= startTimes[i+1]){
//			cout << "Take that job in vector!" << endl;
			schedulingVector.push_back(jobNames[i+1]);
			j = startTimes[i+1];
//			cout << "J: " << j << endl; 
		}
	}
	
	cout << endl << "Size of vector | Maximum Job Numbers: " << schedulingVector.size() << endl;
 	for(int i=0; i<schedulingVector.size(); ++i)
  		cout << schedulingVector[i] << " - ";
	
	return 0;
}

