package project;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;
import java.util.StringTokenizer;

public class huffmanEncoding {
	static int size =0;
	static void swap(elem[] arr,int i, int j ) {
		elem temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	 static class elem1{
		int fre=0;
		elem left = null, right=null;
		char ch;
		String code;
		elem(char ch, int fre){
			this.ch = ch;
			this.fre = fre;
		}
		
	}
	static void assign(elem element ,String[] x, String alpha) {
		if(element.ch != '1') {
			x[(int)element.ch - (int)'a'] = alpha;
			return;
		}
		assign(element.left, x, alpha+"0");
		assign(element.right, x, alpha+"1");
		
	}
	
	static void insert(elem[] arr,elem ele) {
		arr[size] = ele;
		int u = size;
		size++;
		while(u>0) {
			if(arr[(u-1)/2].fre > arr[u].fre) {
				swap(arr, (u-1)/2, u);
				u = (u-1)/2;
			}
			else break;
		}
		sanitycheck(arr);
		
	}
	static void sanitycheck(elem[] arr) {
		for(int z=0; z<size;z++) {
			if(arr[z].fre<arr[0].fre) {
				System.out.println("Code is Worthless");
			}
		}
	}
	static elem getmin(elem[] arr) {
		elem ret = arr[0];
		size--;
		arr[0] = arr[size];
		heapify(arr,0);
		sanitycheck(arr);
		return ret;
	}
	static void print(elem a) {
		if(a == null) {
			return;
		}
		print(a.left);
		System.out.print(" : L  C "+a.fre +"  R:");
		print(a.right);
	}
	static void heapify(elem[] arr, int k) {
		int smallest = k;
		int left = 2*k+1;
		int right = 2*k+2;
		if(left< size && arr[left].fre < arr[smallest].fre) {
			smallest = left;
		}
		if(right< size && arr[right].fre < arr[smallest].fre) {
			smallest = right;
		}
		if(smallest != k) {
			swap(arr,smallest,k);
			heapify(arr,smallest);
		}
		
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Reader.init(System.in);
		String sc = Reader.next();
		elem[] arr = new elem[26];
		char[] chara = sc.toCharArray();
		int[] frequency = new int[26];
		for(char a:chara) {
			frequency[(int)a - (int)'a']++;
		}
		
		System.out.println();
		int a=0;
		while(a<26) {
			elem t = new elem((char)(a +(int)'a'), frequency[a]);
			insert(arr,t);
			a++;
		}
		while(size>1) {
			elem  y1 = getmin(arr);
			elem y2= getmin(arr);
			elem n = new elem('1', y1.fre + y2.fre);
			n.right = y2;
			n.left = y1;
			
			insert(arr,n);	
			//print(n);
			//System.out.println();
			
		}
		String[] xx = new String[26];
		assign(arr[0],xx,"");
		for(String gh : xx) {
			System.out.println(gh);
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
