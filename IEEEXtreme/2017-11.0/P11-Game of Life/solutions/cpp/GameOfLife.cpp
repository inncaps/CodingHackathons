#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30;
int n, m, c, cur;
char board[2][MAXN][MAXN];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
map< string, int > visited;

int get_neighbours( int i, int j ){
	int ni, nj, ans = 0;
	for( int k = 0; k < 8; ++k ){
		ni = (i + n + dx[k]) % n;
		nj = (j + m + dy[k]) % m;
		if( board[ cur ][ ni ][ nj ] == '*' ) ++ans;
	}
	return ans;
}

int main(){
	cin >> n >> m >> c;

	int mask_id = 0;
	string mask = "";
	for( int i = 0; i < n; ++i ){
		for( int j = 0; j < m; ++j ){
			cin >> board[ 0 ][ i ][ j ];
			mask.push_back( board[ 0 ][ i ][ j ] );
		}
	}
	visited[ mask ] = mask_id++;

	//simulate c iterations till detect cycle or end
	//turn flag to true if a cycle is find and reduce c to c modulo size of the cycle
	bool flag = false;
	while( c-- ){
		string mask = "";
		for( int i = 0; i < n; ++i ){
			for( int j = 0; j < m; ++j ){
				int nb = get_neighbours( i, j );
				board[ cur^1 ][ i ][ j ] = board[ cur ][ i ][ j ];
				if( board[ cur ][ i ][ j ] == '*' ){
					if( nb < 2 || nb > 3  ) board[ cur^1 ][ i ][ j ] = '-';
				}
				else{
					if( nb == 3 ) board[ cur^1 ][ i ][ j ] = '*';
				}
				mask.push_back( board[ cur^1 ][ i ][ j ] );
			}
		}
		if( !flag && visited.count( mask ) ){
			int st = visited[ mask ];
			int sz = mask_id - st;
			c = c % sz;
			flag = true;
		}
		visited[ mask ] = mask_id++;
		cur ^= 1;
	}


	for( int i = 0; i < n; ++i ){
		for( int j = 0; j < m; ++j ){
			cout << board[ cur ][ i ][ j ];
		}
		cout << '\n';
	}

	return 0;
}