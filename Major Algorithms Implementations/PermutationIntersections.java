import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.*;

public class PermutationIntersections {
    public static void swap(int arr[], int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public static void print(int arr[]){
        for(int i:arr){
            System.out.print(i+" ");

        }
        System.out.println();
    }
    public static void print(int arr[][]){
        for(int i[]:arr){
            System.out.print(i[0]+" "+i[1]+" -> ");

        }
        System.out.println();
    }
    public static long mergersort(int a[], int t[], int l, int r){
        long inv_count =0;
        int mid;
        if(r<=l){
            return inv_count;
        }
        mid = (l+r)/2;
        inv_count+= mergersort(a,t,l,mid);
        inv_count+= mergersort(a,t,mid+1,r);
        inv_count+= merge(a,t, l, mid, r);
        return inv_count;

    }
    public static long merge(int a[], int t[], int l, int m, int r ){
        long ans=0;
        int i = l;
        int j = m+1;
        int k=l;
        while(i<=m && j<= r){
            if(a[i]< a[j]){
                t[k] = a[i];
                i++;

            }
            else{
                t[k] = a[j];
                ans += (m-i+1);
                j++;
            }
            k++;
        }
        for(;i<=m;i++,k++){
            t[k] = a[i];
        }
        for(;j<=r;j++,k++){
            t[k] = a[j];
        }
        //copying elements back
        for(i = l;i<=r;i++){
            a[i] = t[i];
        }
        return ans;
    }
    public static void main(String[] args) throws IOException{
        Reader.init(System.in);
        int t= Reader.nextInt();
        while(t-->0){
            int n = Reader.nextInt();
            int A[] = new int[n+1];
            int B[] = new int[n+1];
            int posi[][] = new int[n+1][2];
            for(int i=1;i<=n;i++){
                A[i] = Reader.nextInt();
                posi[A[i]][0] = i;
            }
            for(int i=1;i<=n;i++){
                B[i] = Reader.nextInt();
                posi[B[i]][1] = i;
            }
            // Arranging A in increasing order using in-place sorting
            for(int i=1;i<=n;i++){
                int indexA = posi[i][0];
                int indexB = posi[i][1];
                int swapIndexA = i;
                int swapIndexB = posi[A[i]][1];
                posi[A[i]][0] = indexA;
                posi[i][0]=i;
                posi[B[indexB]][1] = swapIndexB;
                posi[B[swapIndexB]][1] = indexB;
                swap(A, indexA, i);
                swap(B, indexB, swapIndexB);
//                print(A);
//                print(B);
//                print(posi);

            }
            //Now we just have to find the number of inversions in array B
            System.out.println(mergersort(B, new int[n+1],1, n));


        }
    }
}
class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    /** call this method to initialize reader for InputStream */
    static void init(InputStream input) {
        reader = new BufferedReader(
                new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
    }

    static public BufferedReader getInstance(){
        return reader;
    }

    /** get next word */
    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {
            //TODO add check for eof if necessary
            tokenizer = new StringTokenizer(
                    reader.readLine() );
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }
}