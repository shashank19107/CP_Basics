//package project;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.*;

//import project.SegmentTree.treeNode;

public class SegTreeBrackets {
	static class treeNode{
		int l,r,bracks, mid;
		int open, closed;
		treeNode right, left;
		treeNode(int l, int[] arr){
			this.l = l;
			this.r = l; 
			this.mid = l;
			bracks = 0;
			open = 0;
			closed = 0;
			//this.min = arr[l];
			if(arr[l]=='(') {
				open=1;
			}
			else {
				closed = 1;
				
			}
		}
		treeNode(String arr, int l, int r){
			if(l==r) {
				this.l = l;
				this.r = l; 
				this.mid = l;
				bracks = 0;
				open = 0;
				closed = 0;
				//this.min = arr[l];
				if(arr.charAt(l)=='(') {
					open=1;
				}
				else {
					closed = 1;
					
				}
			}
			else {
				this.l = l;
				 this.r = r;
				 this.mid = (l+r)/2;
				 this.left = new treeNode(arr, l, mid);
			// System.out.println("From "+l+" to "+mid+ " B "+this.left.bracks+" O "+this.left.open+" C "+this.left.closed);
				 this.right = new treeNode(arr, mid+1, r);
				// System.out.println("From "+(mid+1)+" to "+r+ " B "+this.right.bracks+" O "+this.right.open+" C "+this.right.closed);
				// this.min = Math.min(this.left.min, this.right.min);
				 this.bracks = this.left.bracks + this.right.bracks ;
				 if(this.left.open >= this.right.closed) {
					 this.bracks += this.right.closed;
					 this.open = this.left.open + this.right.open - this.right.closed;
					 this.closed = this.left.closed ;
					 //this.left.open -= this.right.closed;
					 //this.right.closed -= this.right.closed;
				 }
				 else {
					 this.bracks +=this.left.open;
					 this.open =  this.right.open;
					 this.closed = this.left.closed + this.right.closed - this.left.open;
					 //this.right.closed -= this.left.open;
					 //this.left.open -= this.left.open;
				 }
				 //this.open = this.left.open + this.right.open;
				// this.closed = this.left.closed + this.right.closed;
				// System.out.println("From F "+(l)+" to "+r+ " B "+this.bracks+" O "+this.open+" C "+this.closed);
					
			
			}
		}
	}

	static int[] getmin(treeNode root, int l, int r) {
		if(l == root.l && r== root.r) {
			//System.out.println("returning 1 l "+root.l+" R "+root.r+" B "+root.bracks+" O "+root.open+" C "+root.closed);
			return new int[] {root.bracks, root.open , root.closed};
		}
		if(l>root.mid) {
			
				return getmin(root.right , l, r );
			
			//return getmin(root.right, root.r+1, r)
		}
		else {
			if(r<=root.mid) {
				return getmin(root.left, l , r);
			}
			//return Math.min(getmin(root.left, l, root.mid),getmin(root.right, root.mid+1, r));
			int[] lef = getmin(root.left, l, root.mid);
			int[] rig = getmin(root.right, root.mid+1, r);
			if(lef[1]>=rig[2]) {
				//System.out.println("returning 2 l "+l+" R "+r+" B "+(lef[0]+rig[0]+rig[2])+" O "+(lef[1]-rig[2]+rig[1])+" C "+(lef[2]));
				return new int[] {lef[0]+rig[0]+rig[2], lef[1]-rig[2]+rig[1], lef[2]};
			}
			//System.out.println("returning 3 l "+l+" R "+r+" B "+(lef[0]+rig[0]+lef[1])+" O "+(rig[1])+" C "+(lef[2]+rig[2]-lef[1]));
			return new int[] {lef[0]+rig[0]+lef[1], rig[1],lef[2]+rig[2]-lef[1]};
		
		}
		
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Reader.init(System.in);
//		int n = Reader.nextInt();
//		int m = Reader.nextInt();
//		int arr[] = new int[n];
//		for(int i =0; i<n;i++) {
//			arr[i] = Reader.nextInt();
//			
//		}
		String s = Reader.next();
		//char[] arr= s.toCharArray();
		int m = Reader.nextInt();
		treeNode root = new treeNode(s, 0, s.length()-1);
		Queue<treeNode> q = new LinkedList<treeNode>();
		q.add(root);
//		while(!q.isEmpty()) {
//			treeNode k = q.poll();
//			//System.out.println(k.l +" "+k.r+ " "+ k.bracks+" "+k.closed+" "+k.open);
//			if(k.l==k.r)
//				continue;
//			q.add(k.left);
//			q.add(k.right);
//		}
		for(int i = 0; i<m;i++) {
			int l = Reader.nextInt()-1;
			int r = Reader.nextInt()-1;
			System.out.println(getmin(root, l, r)[0]*2);
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
