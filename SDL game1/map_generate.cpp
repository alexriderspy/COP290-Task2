#include <iostream>
#include <fstream>

using namespace std;

int main(){
	fstream fin;
	fin.open("matrix.txt");
	string line="";
	string map = "{";
	getline(fin,line);
	int len = (int)line.size();
	for(int i=0;i<len;++i){
		if(line[i]=='#'){
			map+="1,";
		}else{
			map+="0,";
		}
		cout<<"what\n";
	}
	while(getline(fin,line)){
		cout<<"lol\n";
		for(int i=0;i<len;++i){
			if(line[i]=='#'){
				map+="1,";
			}else{
				map+="0,";
			}
		}
	}
	map.pop_back();
	map+="}";
	cout<<map;
	fin.close();
	
}