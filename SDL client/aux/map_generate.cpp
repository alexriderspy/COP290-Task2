#include <iostream>
#include <fstream>

using namespace std;

int main(){
	fstream fin;
	fin.open("maze_main.txt");
	string line="";
	string map = "{";
	getline(fin,line);
	int len = (int)line.size();
	for(int i=0;i<len;++i){
		if(line[i]=='b'){
			map+="0,";
		}else if(line[i] == '1'){
			map+="6,";
		}else if(line[i]=='r'){
			map+="3,";
		}else if(line[i]=='#'){
			map+="5,";
		}else if(line[i]=='0'){
			map+="4,";
		}else{
			map+="1,";
		}
	}
	
	while(getline(fin,line)){
		for(int i=0;i<len;++i){
			if(line[i]=='b'){
				map+="0,";
			}else if(line[i] == '1'){
				map+="6,";
			}else if(line[i]=='r'){
				map+="3,";
			}else if(line[i]=='#'){
				map+="5,";
			}else if(line[i]=='0'){
				map+="4,";
			}else{
				map+="1,";
			}
		}
		
	}
	map.pop_back();
	map+="}";
	cout<<map;
	fin.close();
	
}
