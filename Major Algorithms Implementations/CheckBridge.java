package project;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;


public class CheckBridge {
	public  static boolean canvisit(HashMap<Integer,ArrayList<Integer>>	graph, int i, int j,int n) {
		int[] canvisit = new int[n];
		visit(graph,i,canvisit) ;
		if(canvisit[j-1]==0) {
			return true;
			
		}
		return false;
		
	}
	public static void visit(HashMap<Integer,ArrayList<Integer>>	graph, int i,int[] canvisit) {
		if(canvisit[i-1]==1) {
			return;
		}
		canvisit[i-1]=1;
		for(Integer o : graph.get(i)) {
			visit(graph, o,canvisit);
		}
	}
	

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Reader.init(System.in);
		HashMap<Integer,ArrayList<Integer>>	graph = new HashMap<Integer,ArrayList<Integer>>();
		int n = Reader.nextInt();
		for(int i =1;i<= n;i++) {
			graph.put(i, new ArrayList<Integer>());
		}
		int m = Reader.nextInt(); 
		for(int i =0;i<m;i++) {
			int a1 = Reader.nextInt();
			int a2 = Reader.nextInt();
			graph.get(a1).add(a2);
			graph.get(a2).add(a1);
			
		}
		//System.out.println("Graph  " + graph.toString());
		
		Integer source = Reader.nextInt();
		Integer target = Reader.nextInt();
		graph.get(source).remove(target);
		graph.get(target).remove(source);
		
		//System.out.println("Graph now : "+ graph.toString());
		if(canvisit(graph,source,target,n)) {
			System.out.println(1);
		}
		else {
			System.out.println(0);
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
