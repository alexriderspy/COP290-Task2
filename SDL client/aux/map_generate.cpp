#include <iostream>
#include <fstream>

using namespace std;

int main(){
	fstream fin;
	fin.open("maze_LHC.txt");
	string line="";
	string map = "{";
	getline(fin,line);
	int len = (int)line.size();
	for(int i=0;i<len;++i){
		if(line[i]=='0'){
			map+="0,";
		}else if(line[i] == '1'){
			map+="1,"; //hostel front
		}else if(line[i]=='2'){
			map+="3,";
		}else if(line[i] =='3'){
			map +="1,";
		}
	}
	
	while(getline(fin,line)){
		for(int i=0;i<len;++i){
			if(line[i]=='0'){
				map+="0,";
			}else if(line[i] == '1'){
				map+="1,"; //hostel front
			}else if(line[i]=='2'){
				map+="3,";
			}else if(line[i] =='3'){
				map +="1,";
			}
		}
		
	}
	map.pop_back();
	map+="}";
	cout<<map;
	fin.close();
	
}
