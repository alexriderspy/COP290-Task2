#include <iostream>
#include <fstream>

using namespace std;

int main(){
	fstream fin;
	fin.open("maze_main.txt");
	string line="";
	string map = "{";	
	while(getline(fin,line)){
		for(int i=0;i<134;++i){
			if(line[i]=='#'){
				map+="5,";
			}else if(line[i] == '0'){
				map+="4,"; 
			}else if(line[i]=='b'){
				map+="0,";
			}else if(line[i] =='1'){
				map +="4,";
			}else if(line[i] == 'l'){
				map+="7,";
			}else if(line[i]=='r'){
				map+="3,";
			}else if(line[i] == ' '){
				map+="1,";
			}
		}
		
	}
	map.pop_back();
	map+="}";
	cout<<map;
	fin.close();
	
}
