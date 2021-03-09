import java.util.Scanner;

public class Bakery {
	
	static int n=0;
	static int k=0;
	
	public static long g(int i,int curr_b,int prev,long dp[][][],int arr[]) {
		if(i==n+1 && curr_b==k) {
			return 0;
		}
		if(i>n && curr_b<k) {
			return Integer.MAX_VALUE;
		}
		if(curr_b>k) {
			return Integer.MAX_VALUE;
		}
		if(dp[i][curr_b][prev]!=-1) {
			return dp[i][curr_b][prev];
		}
		int extra=0;
		for(int j=i-1;j>=prev && j>0;j--) {
			int a=arr[i]-arr[j];
			int b=arr[j]-arr[prev];
			extra+=Math.min(a, b);
		}
		long first=Integer.MAX_VALUE;
		if(curr_b<k) {
			first=extra+g(i+1,curr_b+1,i,dp,arr);
		}
		long second=Integer.MAX_VALUE;
		if(curr_b==k) {
			second=arr[i]-arr[prev]+g(i+1,curr_b,prev,dp,arr);
		}else {
			second=g(i+1,curr_b,prev,dp,arr);
		}
		long ans=Math.min(first, second);
		dp[i][curr_b][prev]=ans;
		return ans;
			
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s=new Scanner(System.in);
		n=s.nextInt();
		k=s.nextInt();
		int arr[]=new int[n+1];
		arr[0]=0;
		for(int i=1;i<=n;i++) {
			arr[i]=s.nextInt();
		}
		long dp[][][]=new long[n+1][k+1][n+1];
		for(int i=0;i<n+1;i++) {
			for(int j=0;j<k+1;j++) {
				for(int z=0;z<n+1;z++) {
					dp[i][j][z]=-1;
				}
			}
		}
	
		System.out.println(g(1,0,0,dp,arr));
		s.close();
		

	}

}
