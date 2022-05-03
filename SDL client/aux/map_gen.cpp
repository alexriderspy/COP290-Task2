#include<iostream>
#include<fstream>
#include <vector>
using namespace std;

int main(){
	ifstream fio;
	fio.open("matrix.txt");
	string line;
	vector<vector<int>> v;
	vector<int>v1;
	while(fio){
		getline(fio,line);
		cout<<line<<'\n';
		v1 = vector<int>();
		for(int i=0;i<line.length();++i){
			v1.push_back(line[i]=='#'?1:0);
		}
		if((int)v1.size()<60){
			for(int i=0;i<60-(int)v1.size();++i) v1.push_back(0);
		}
		v.push_back(v1);
	}
	for(int i=0;i<(int)v.size();++i){
		for(int j=0;j<60;++j){
			cout<<v[i][j]<<",";
		}
		cout<<'\n';
	}
	cout<<v.size()<<' '<<v[0].size()<<'\n';
}