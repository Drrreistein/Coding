import java.util.Hashtable;
import java.util.HashMap;

public class test {
	
	public static void hashTest(HashMap<Integer, Integer> ht, int i) {
		if(!ht.isEmpty()) {
			ht.remove(i);
			hashTest(ht, i+1);
			System.out.println(ht);
		}
	}
	
	public static void main(String args[]) {
		
		int[][] edge = {{1,2},{1,4},{1,5},{2,3},{2,4},{2,5},{3,4},{4,5}};

//		Hashtable<Integer, Integer> vertices = new Hashtable<Integer,Integer>();

		HashMap<Integer, Integer> vertices = new HashMap();
		for(int i=0; i<edge.length; i++) {
			for(int j=0; j<edge[0].length; j++) {
				if(vertices.containsKey(edge[i][j])) {
					int index = vertices.get(edge[i][j]);
					vertices.put(edge[i][j], index+1);
				}else {
					vertices.put(edge[i][j], 1);
				}
			}
		}
		
		hashTest(vertices, 1);
	}

}
