#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

typedef vector<vector<int > > Graph;

void DFS_rec(Graph &g, int n, int m,int& total, int& number, int x, int y){


	if(x<0 or y<0 or x>=n or y>=m) return;

	int num=g[x][y];

	if(num==-1) return;

	else if(num!=-1){


		total=total+num;
		number++;
		g[x][y]= -1;
		DFS_rec(g,n,m,total,number,x+1,y+1);
		//cout << number << endl;
		DFS_rec(g,n,m,total,number,x-1,y-1);
		//	cout << number << endl;
		DFS_rec(g,n,m,total,number,x-1,y+1);
		//	cout << number << endl;
		DFS_rec(g,n,m,total,number,x+1,y-1);
		//	cout << number << endl;

	}


}


bool DFS(Graph &g, int n, int m, int bishop){

	int total,number;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){

			if(g[i][j]!=-1){

				total=0;
				number=0;
				DFS_rec(g,n,m,total,number,i,j);
				if((total/number)!=bishop or total%number!=0) return false;

			}

		}
	}
	return true;




}


int  main(){



	int num;

	cin >> num;

	for(int t=1; t<=num; t++){

		int n,m;
		string x;

		int total=0;
		int numero=0;

		cin >> n >> m;

		Graph g (n,vector<int>(m));

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin >> x;
				if(x=="X") g[i][j]=-1;
				else{
					int at=atoi( x.c_str() );
					g[i][j]= at;
					numero++;
					total=total+at;
				}

			}
		}

		if(numero!=0 ){
			int bishop=total/numero;
			if(total%numero!=0) cout << "Case " << t << ": no" << endl;
			else{


				if(DFS(g,n,m,bishop)) cout << "Case " << t << ": yes" << endl;
				else cout << "Case " << t << ": no" << endl;
			}
		}
		else cout << "Case " << t << ": yes" << endl;









	}
}