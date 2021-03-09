import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;


public class ADA_LAb2 {
    public static void main(String[] args) throws  IOException {
        Reader.init(System.in);
        int arr[][] = new int[1001][1001];
        for( int i=0;i<1001;i++){
            for(int j =0; j<1001;j++){
                if(arr[i][j]==0){
                    for(int l = i+1;l<1001 ;l++){
                        arr[l][j] = 1;
                    }
                    for(int l = j+1;l<1001 ;l++){
                        arr[i][l] = 1;
                    }
                    for(int l =1; l+i<1001 && l+j < 1001;l++){
                        arr[i+l][j+l] = 1;
                    }
                }
            }
        }



        int t = Reader.nextInt();
//        for(int i=0;i<15;i++){
//            for(int j=0; j<15 ; j++){
//                System.out.print(arr[i][j]+" ");
//            }
//            System.out.println();
//        }
        while(t-->0){
            int i,j;
            i = Reader.nextInt();
            j = Reader.nextInt();
            if(arr[i][j]==1)
            System.out.println("YES");
            else
                System.out.println("NO");



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

    /** get next word */
    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {
            //TODO add check for eof if necessary
            tokenizer = new StringTokenizer(
                    reader.readLine() );
        }
        return tokenizer.nextToken();
    }
    static String nextLine() throws IOException {
        return reader.readLine();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }
}