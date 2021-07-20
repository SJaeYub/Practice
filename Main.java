package baek2667;

import java.util.*;

public class Main {
	static int n;
	static int [][] map;
	static boolean[][] visited;
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	static ArrayList<Integer> result;
	static int cnt;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		map = new int[n][n];
		visited = new boolean[n][n];
		String temp = new String();
		result = new ArrayList<>();
		
		for(int i = 0; i < n; i++) {
			temp = sc.next();
			for(int j = 0; j < n; j++) {
				map[i][j] = temp.charAt(j) - '0';
			}
		}
		
//		for(int i = 0; i < n; i++) {
//			for(int j = 0; j < n; j++) {
//				System.out.println(map[i][j]);
//			}
//		}
	
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(map[i][j] == 1 && !visited[i][j]) {
					cnt = 1;
					dfs(i,j);
					result.add(cnt);					
				}
			}
		}
		
		Collections.sort(result);
		System.out.println(result.size());
		for(int i : result) {
			System.out.println(i);
		}
		
	}
	
	public static int dfs(int a, int b) {
		visited[a][b] = true;
		
		for(int i = 0; i < 4; i++) {
			int mx = a + dx[i];
			int my = b + dy[i];
			
			if(mx >= 0 && my >= 0 && mx < n && my < n) {
				if(map[mx][my] == 1 && !visited[mx][my]) {
					cnt++;
					dfs(mx, my);
				}
			}
		}
		
		return cnt;
	}

}
