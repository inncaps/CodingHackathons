#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6+10, MAXNM = 105, MAXC = 26;
string s, p;
int q, last[ MAXC ][ MAXN ];

//Generate last matrix, where last[ ch ][ i ] is equal to the rightmost index of s in the range [0-i]
//where the char ch + 'a' appears, or -1 in the case that there is not such a char in the range
void get_last(){
	for( int k = 0; k < MAXC; ++k ) last[ k ][ 0 ] = -1;
	last[ s[0] - 'a' ][ 0 ] = 0;
	for( int i = 1; i < s.size(); ++i ){
		for( int k = 0; k < MAXC; ++k ){
			last[ k ][ i ] = last[ k ][ i-1 ];
		}
		last[ s[i] - 'a' ][ i ] = i;
	}
}

//Search for p characters backwards in s using last matrix
//The time complexity for each search is O( |p| ) 
int find(){
	int cnt = 0;
	int p_sz = p.size();
	for( int i = s.size()-1; i >= 0 && cnt < p_sz; --i ){
		i = last[ p[ p_sz - cnt - 1 ]-'a' ][ i ];
		if( i >= 0 ) ++cnt;
	}
	return cnt;
}

int main(){

	cin >> s >> q;
	get_last();
	while( q-- ){
		cin >> p;
		cout << find() << '\n';
	}

	return 0;
}