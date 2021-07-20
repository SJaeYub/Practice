package baek1388;

import java.util.*;

public class Main {
	
	static int n = 0, total = 0, m = 0;
	static boolean[][] visited;
	static char[][] deco;	
	static int[] dx = {1, -1, 0, 0};
	static int[] dy = {0, 0, 1, -1};
	static boolean flag = false;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		deco = new char[n][m];		
		visited = new boolean[n][m];
		String temp = new String();
		
		for(int i = 0; i < n; i++) {
			temp = sc.next();
			for(int j = 0; j < m; j++) {
				deco[i][j] = temp.charAt(j);
			}
		}
		
		
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(!visited[i][j]) {
					System.out.println(i + " " + j);
					total++;
					char init_deco = deco[i][j];
					dfs(i,j, init_deco);
				}
			}
		}
		
		System.out.println(total);

	}
	
	private static int dfs(int a, int b, char d) {
		if(deco[a][b] == d) {
			visited[a][b] = true;
//			System.out.println(a + " " + b);
			for(int i = 0; i< 4; i++) {
				int mx = b;
				int my = a;
				
				if(deco[a][b] == '-') {
					mx = b + dx[i];
				}
				if(deco[a][b] == '|') {
					my = a + dy[i];
				}
				if(mx >= 0 && my >= 0 && mx < m && my < n) {
					if(!visited[my][mx]) {
						dfs(my, mx, deco[a][b]);
					}
				}
			}
			return 0;
		}
		if(deco[a][b] != b) {
			return 0;
		}
		return 0;
	}

}
