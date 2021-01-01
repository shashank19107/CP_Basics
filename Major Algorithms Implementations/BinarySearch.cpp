#include <iostream>
#include <array>
using namespace std;

int searchbeg(int arr[], int k, int n){
    int beg =0;
    int end = n-1;
    int d = -1;
    while(beg<end){
        int mid = (beg+end)/2;
        if(arr[mid]<k){
            beg = mid+1;
            continue;
        }
        else if(arr[mid]==k){
            d = mid;
        }
        end = mid;
    }
    return d;
}

int searchend(int arr[], int k, int n){
    int beg =0;
    int end = n-1;
    
    while(beg<end){
        int mid = end - ((end-beg)/2);
        if(arr[mid]>k){
            end = mid-1;
            continue;
        }
        else {
            beg = mid;
        }
        
    }
    return end;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n, k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0; i<n;i++){
	        cin>>arr[i];
	        
	    }
	    int r1 = searchbeg(arr, k,n);
	    if(r1==-1){
	        cout<<"-1"<<endl;
	    }
	    else{
	        cout<<r1<<" "<<searchend(arr, k,n)<<endl;
	    }
	    
	    
	}
	return 0;
}
