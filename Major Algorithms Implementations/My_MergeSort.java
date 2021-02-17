package project;
import java.util.*;
import java.math.*;

public class MS {
	public static int[] merge( int[] beg ,int[] end , int starti , int endi) {
		int i = 0;		
		int arr[] = new int[beg.length  + end.length];
		int j =0,k=0;
		while(j<beg.length && k < end.length) {
			if(beg[j] > end[k]) {
				arr[i] = end [k];
				k++;
			}
			else {
				arr[i] = beg[j];
				j++;
			}
			i++;
		}
		while(j<beg.length) {
			arr[i] = beg[j];
			j++;
			i++;
		}
		while(k<end.length) {
			arr[i] = end[k];
			k++;
			i++;
		}
		return arr;
		
		
	}
	public static int[] sorting(int[] arr, int beg, int end) {
		if (beg >= end) {
			return arr;
		}
		int mid = beg + (end-beg)/2;
		int begarr[] = new int[mid - beg +1];
		int endarr[] = new int [end - mid];
		int u=0;
		for(int i=0 ; i<mid - beg +1;u++,i++) {
			begarr[i] = arr[u];
		}
		for(int i=0 ; i<end - mid;u++,i++) {
			endarr[i] = arr[u];
		}
		begarr = sorting( begarr, 0, begarr.length-1);
		endarr=sorting(endarr, 0,endarr.length-1);
		return merge( begarr , endarr,beg,end);
		
		
		
	}
	

	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	int arr[] = new int[n];
	for(int y =0; y<n;y++) {
		arr[y] = sc.nextInt();
		
	}
	int[] qw=sorting(arr, 0 , arr.length -1);
	long ans =0;
	for(int er = 0 ;er < qw.length ; er += 2) {
		ans += (qw[er+1] - qw[er] );
	}
	System.out.println(ans);
	
	
	}
	
 }

