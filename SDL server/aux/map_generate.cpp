#include <iostream>
#include <fstream>

using namespace std;

int main(){
	fstream fin;
	fin.open("matrixLHC.txt");
	string line="";
	string map = "{";
	getline(fin,line);
	int len = (int)line.size();
	for(int i=0;i<len;++i){
		if(line[i]=='#'){
			map+="1,";
		}else if(line[i] == 'L'){
			map+="2,";
		}else if(line[i]==' '){
			map+="0,";
		}
	}
	
	while(getline(fin,line)){
		for(int i=0;i<len;++i){
			if(line[i]=='#'){
				map+="1,";
			}else if(line[i] == 'L'){
				map+="2,";
			}else if(line[i] == ' '){
				map+="0,";
			}
		}
		
	}
	map.pop_back();
	map+="}";
	cout<<map;
	fin.close();
	
}
