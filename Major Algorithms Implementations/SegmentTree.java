package project;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.*;

public class SegmentTree {
	static class treeNode{
		int l,r,min, mid;
		treeNode right, left;
		treeNode(int l, int[] arr){
			this.l = l;
			this.r = l; 
			this.mid = l;
			this.min = arr[l];
		}
		treeNode(int[] arr, int l, int r){
			if(l==r) {
				this.l = l;
				this.r = l; 
				this.mid = l;
				this.min = arr[l];
			}
			else {
				this.l = l;
				 this.r = r;
				 this.mid = (l+r)/2;
				 this.left = new treeNode(arr, l, mid);
				 this.right = new treeNode(arr, mid+1, r);
				 this.min = Math.min(this.left.min, this.right.min);
				 
			}
		}
	}

	static int getmin(treeNode root, int l, int r) {
		if(l == root.l && r== root.r) {
			return root.min;
		}
		if(l>root.mid) {
			
				return getmin(root.right , l, r );
			
			//return getmin(root.right, root.r+1, r)
		}
		else {
			if(r<=root.mid) {
				return getmin(root.left, l , r);
			}
			return Math.min(getmin(root.left, l, root.mid),getmin(root.right, root.mid+1, r));
		}
		
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Reader.init(System.in);
		int n = Reader.nextInt();
		int m = Reader.nextInt();
		int arr[] = new int[n];
		for(int i =0; i<n;i++) {
			arr[i] = Reader.nextInt();
			
		}
		treeNode root = new treeNode(arr, 0, n-1);
		for(int i = 0; i<m;i++) {
			int l = Reader.nextInt();
			int r = Reader.nextInt();
			System.out.println(getmin(root, l, r));
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
