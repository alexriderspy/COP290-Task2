#include <iostream>
#include <fstream>

using namespace std;

int main(){
	fstream fin;
	fin.open("maze_lib.txt");
	string line="";
	string map = "{";	
	while(getline(fin,line)){
		for(int i=0;i<32;++i){
			if(line[i]=='#'){
				map+="2,";
			}else if(line[i] == '0'){
				map+="0,"; 
			}else if(line[i]=='2'){
				map+="3,";
			}else if(line[i] =='1'){
				map +="4,";
			}else if(line[i] == '6'){
				map+="6,";
			}else if(line[i]=='3'){
				map+="1,";
			}
		}
		
	}
	map.pop_back();
	map+="}";
	cout<<map;
	fin.close();
	
}
