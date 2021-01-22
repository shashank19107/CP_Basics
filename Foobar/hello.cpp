#include <iostream>
#include <array>
using namespace std;

int lookfor(int arr[], int left, int right){
	if(left>=right){
		return right;
	}
	int mid = left + ((right -left)/2);
	if(arr[mid]>arr[mid+1]){
		return lookfor(arr, left, mid);
	}
	
		return lookfor(arr, mid+1, right);
	
	
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    //int size=0; 
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n;i++){
	    	cin>>arr[i];
	    }
	    cout<<lookfor(arr,0,n-1  )<<endl;

	    
	    
	}
	return 0;
}