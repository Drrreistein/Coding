
import java.util.*;

public class EulerKreis {
	private static ArrayList<String> edgeList = new ArrayList();
	private static int times = 0;
	
	public static boolean isEulerKreis(int[][] edge) {
		int m = edge.length;

		// vertices<vertex, count>
		Hashtable<Integer, Integer> vertices = new Hashtable<Integer,Integer>();
		
		for(int i=0; i<m; i++) {
			for(int j=0; j<edge[0].length; j++) {
				if(vertices.containsKey(edge[i][j])) {
					int index = vertices.get(edge[i][j]);
					vertices.put(edge[i][j], index+1);
				}else {
					vertices.put(edge[i][j], 1);
				}
			}
		}
		
		ArrayList<int[]> e = new ArrayList<>();
		for(int i=0; i<m; i++) {
			e.add(edge[i]); // convert edge[][] to List with array elements 
		}
		
		int oddVertices = 0;// count how many odd vertices there is
		for(int i : vertices.values()) {// 
			if(vertices.get(i)%2 != 0) {// value 
				oddVertices++;
				backTracking(i+1, "", e);
			}
		}
		if(oddVertices%2 == 0) {
			// if there are even number of odd vertices, must start from odd vertices
			for(int i : vertices.values()) {// 
				if(vertices.get(i)%2 != 0) {// value 
					oddVertices++;
					backTracking(i+1, "", e);
				}
			}
			// if there are no odd vertices, can start from every vertex
			if(oddVertices==0) {
				for(int i =0; i<m; i++) {
					backTracking(i+1, "",e);
				}
			}
			return true;
		}else {return false;}
		
//		
	}
	
	public static void backTracking(int start, String s ,ArrayList<int[]> edge) {
		
		String tmp = s.concat(Integer.toString(start));

		if(edge.size()==0) { // end condition
			times++; // count recursion times
			System.out.println(times+": "+ tmp);
			edgeList.add(tmp);

		}
		else {
			for(int i=0; i<edge.size(); i++) {
				if(start == edge.get(i)[0] || start == edge.get(i)[1]) {
					int newStart = start;
					
					if(start == edge.get(i)[0] ) {
						newStart = edge.get(i)[1];
					}else{
						newStart = edge.get(i)[0];
					}
					
					int[] arr = edge.get(i); // 暂存将被移除的edge的元素
					edge.remove(i); // 移除当前递归的选择
					backTracking(newStart, tmp, edge); // 递归
					edge.add(i, arr);// 手动恢复edge递归前的值
				}
			}
		}
	}

	public static void displayMatrix(int[][] matr) {
		int len = matr.length;
		for(int i=0; i<len; i++) {
			displayArray(matr[i]);
			System.out.print(',');
		}
	}

	public static void displayArray(int[] arr) {
		int len = arr.length;
		System.out.print("[");
		for(int i=0; i<len; i++) {
			System.out.print(arr[i]);
		}
		System.out.print("]");
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		int[][] edge = {{1,2},{1,4},{1,5},{2,3},{2,4},{2,5},{3,4},{4,5}};
		int[][] edge = {{1,2},{1,4},{1,5},{2,3},{2,4},{2,5},{3,4},{4,5},{1,6},{5,7}};
//		int[][] edge = {{1,2},{2,4},{4,6},{1,6},{4,7},{6,7},{1,7},{2,7}};
//		int[][] edge = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{1,7},{2,7},{3,8},{4,8},{5,8},{7,8}};
//		int[][] edge = {{1,2},{1,8},{1,9},{2,3},{2,10},{3,10},{3,4},{4,5},{4,11},{5,6},{5,11},{6,7},{6,12},{7,8},{7,12},{8,9},{9,10},{10,11},{11,12},{9,12}};
//		int[][] edge = {{1,2},{1,4},{2,3},{4,3}};
//		int[][] edge = {{1,5},{1,4},{2,3},{4,2},{3,5}};
//		int[][] edge = {{1,2},{1,4},{1,5},{1,3},{1,6},{1,7}}; // no solution
		
		System.out.println(isEulerKreis(edge));
//		System.out.print(edge.length);
//		displayMatrix(edge);
	}

}
