#include <string>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>

#define UP 0     //-y
#define DOWN 1   //+y
#define LEFT 2   //-x
#define RIGHT 3  //+x
#define OUTFILE "maze"

#define WHITE fprintf(outfile, "%c%c%c", 255,255,255)
#define BLACK fprintf(outfile, "%c%c%c", 0,0,0)
#define RED   fprintf(outfile, "%c%c%c", 0,0,255)

int numin = 1;     //Number of cells in the maze.
const int xsize = 12;
const int ysize = 12;

void initialize();
void generateMaze();
void savebmp(int xspecial, int yspecial);
void printMaze();
std::string getMaze();

struct cell{
	bool in;  
	bool up;  
	bool left;
	int prevx, prevy; 
};

cell MAZE[xsize][ysize];

// std::string MazeGenerator::generate(){
// 	numin=1;
// 	srand((unsigned int)time(NULL)); //seed random number generator with system time
// 	initialize();      //initialize the maze
// 	generateMaze();        //generate the maze
//     savebmp(0,0);
//     printMaze();
//     //std::cout << getMaze() << std::endl;

//     return getMaze();

// }

int main(){

	srand((unsigned int)time(NULL)); //seed random number generator with system time
	initialize();      //initialize the maze
	generateMaze();        //generate the maze
    
	for(int i=0;i<xsize;++i){
		for(int j=0;j<ysize;++j){
			std::cout<<MAZE[i][j]<<' ';
		}
		std::cout<<'\n';
	}
    savebmp(0,0);
    printMaze();
    //std::cout << getMaze() << std::endl;

    return 0;

}

void initialize(){
	//Initialize the maze!
	for(int x = 0; x < xsize; x++){
		for(int y = 0; y < ysize; y++){
			//The maze cells on the edges of the maze are "in" to provide padding. Otherwise, all maze cells are not in.
            //All maze cells have all walls existing by default, except the perimeter cells.
			MAZE[x][y].in   = (x == 0 || x == xsize-1 || y == 0 || y == ysize-1) ? 1 : 0;	
			MAZE[x][y].up   = (x == 0 || x == xsize-1 || y == 0) ? 0 : 1;
			MAZE[x][y].left = (x == 0 || y == 0 || y == ysize-1) ? 0 : 1;
		}
	}
	return;
}

void generateMaze(){
	int xcur =1, ycur = 1; //start growing from the corner. It could theoretically start growing from anywhere, doesn't matter.
	MAZE[xcur][ycur].in = 1;
	int whichway;
	bool success;
	do{

		if( MAZE[xcur][ycur-1].in && MAZE[xcur][ycur+1].in &&
			   MAZE[xcur-1][ycur].in && MAZE[xcur+1][ycur].in ){
				   //If at a dead end, randomly destroy a wall to make it not a dead end!
			do{
				success=0;
				whichway=rand()%4;
				switch(whichway){
				case UP:
					if(MAZE[xcur][ycur].up&&ycur!=1){
						success=1;
						MAZE[xcur][ycur].up=0;
					}
					break;
				case DOWN:
					if(MAZE[xcur][ycur+1].up&&ycur!=ysize-2){
						success=1;
						MAZE[xcur][ycur+1].up=0;
					}
					break;
				case LEFT:
					if(MAZE[xcur][ycur].left&&xcur!=1){
						success=1;
						MAZE[xcur][ycur].left=0;
					}
					break;
				case RIGHT:
					if(MAZE[xcur+1][ycur].left&&xcur!=xsize-2){
						success=1;
						MAZE[xcur+1][ycur].left=0;
					}
					break;
				}
			} while (!success);
		}



		while (MAZE[xcur][ycur-1].in&&MAZE[xcur][ycur+1].in&&
			   MAZE[xcur-1][ycur].in&&MAZE[xcur+1][ycur].in ){
				   //If all the neighbourhood cells are in, backtrack.
				int xcur2=MAZE[xcur][ycur].prevx;
				ycur=MAZE[xcur][ycur].prevy;
				xcur=xcur2;
		}


		do{
			//Randomly grow the maze if possible.
			success = 0;
			whichway = rand()%4;
			switch(whichway){
			case UP:
				if(!MAZE[xcur][ycur-1].in){
					success=1;
					MAZE[xcur][ycur].up=0;
					MAZE[xcur][ycur-1].prevx=xcur;
					MAZE[xcur][ycur-1].prevy=ycur;
					ycur--;
				}
				break;
			case DOWN:
				if(!MAZE[xcur][ycur+1].in){
					success=1;
					MAZE[xcur][ycur+1].up=0;
					MAZE[xcur][ycur+1].prevx=xcur;
					MAZE[xcur][ycur+1].prevy=ycur;
					ycur++;
				}
				break;
			case LEFT:
				if(!MAZE[xcur-1][ycur].in){
					success=1;
					MAZE[xcur][ycur].left=0;
					MAZE[xcur-1][ycur].prevx=xcur;
					MAZE[xcur-1][ycur].prevy=ycur;
					xcur--;
				}
				break;
			case RIGHT:
				if(!MAZE[xcur+1][ycur].in){
					success=1;
					MAZE[xcur+1][ycur].left=0;
					MAZE[xcur+1][ycur].prevx=xcur;
					MAZE[xcur+1][ycur].prevy=ycur;
					xcur++;
				}
				break;
			}
		} while (!success);
		MAZE[xcur][ycur].in = 1;
		numin++; //Every iteration of this loop, one maze cell is added to the maze.

	} while (numin < (xsize-2)*(ysize-2));

	return;
}

void savebmp(int xspecial, int yspecial){
	//save a bitmap file! the xspecial, yspecial pixel is coloured red.
	FILE * outfile;
	int extrabytes;
    unsigned int paddedsize;
	int x, y, n;
	unsigned int width=(xsize-1)*2-1;
	unsigned int height=(ysize-1)*2-1;

	extrabytes = (4 - ((width * 3) % 4))%4; 

	char filename[200];
	
	sprintf(filename, "%s_%dx%d_n%d.bmp", OUTFILE, xsize, ysize, numin);
	paddedsize = ((width * 3) + extrabytes) * height;

	unsigned int headers[13] = {paddedsize + 54, 0, 54, 40, width, height, 0, 0, paddedsize, 0, 0, 0, 0};

	outfile = fopen(filename, "wb");
	fprintf(outfile, "BM");

	for (n = 0; n <= 5; n++){
	   fprintf(outfile, "%c", headers[n] & 0x000000FF);
	   fprintf(outfile, "%c", (headers[n] & 0x0000FF00) >> 8);
	   fprintf(outfile, "%c", (headers[n] & 0x00FF0000) >> 16);
	   fprintf(outfile, "%c", (headers[n] & (unsigned int) 0xFF000000) >> 24);
	}

	fprintf(outfile, "%c", 1);fprintf(outfile, "%c", 0);
	fprintf(outfile, "%c", 24);fprintf(outfile, "%c", 0);

	for (n = 7; n <= 12; n++){
	   fprintf(outfile, "%c", headers[n] & 0x000000FF);
	   fprintf(outfile, "%c", (headers[n] & 0x0000FF00) >> 8);
	   fprintf(outfile, "%c", (headers[n] & 0x00FF0000) >> 16);
	   fprintf(outfile, "%c", (headers[n] & (unsigned int) 0xFF000000) >> 24);
	}

	//Actual writing of data begins here:
	for(y = 0; y <= height - 1; y++){
		for(x = 0; x <= width - 1; x++){
			if(x%2 == 1 && y%2 == 1){
				if(x/2+1 == xspecial && y/2+1 == yspecial) RED;
				else{
					if(MAZE[x/2+1][y/2+1].in) WHITE; else BLACK;
				}
			}else if(x%2 == 0 && y%2 == 0){
				BLACK;
			}else if(x%2 == 0 && y%2 == 1){
				if(MAZE[x/2+1][y/2+1].left) BLACK; else WHITE;
			}else if(x%2 == 1 && y%2 == 0){
				if(MAZE[x/2+1][y/2+1].up) BLACK; else WHITE;
			}
		}
		if (extrabytes){     // See above - BMP lines must be of lengths divisible by 4.
			for (n = 1; n <= extrabytes; n++){
				fprintf(outfile, "%c", 0);
			}
		}
	}
	printf("file printed: %s\n\n\n", filename); 
	fclose(outfile);

	return;
}

void printMaze(){

	int x, y;
	int width=(xsize-1)*2-1;
	int height=(ysize-1)*2-1;

    for(y = height-1; y >= 0; y--){
		for(x = 0; x <= width - 1; x++){
			if(x%2 == 1 && y%2 == 1){
				
				if(MAZE[x/2+1][y/2+1].in) std::cout << " "; else std::cout << "#";
				
			}else if(x%2 == 0 && y%2 == 0){
				std::cout << "#";
			}else if(x%2 == 0 && y%2 == 1){
				if(MAZE[x/2+1][y/2+1].left) std::cout << "#"; else std::cout << " ";
			}else if(x%2 == 1 && y%2 == 0){
				if(MAZE[x/2+1][y/2+1].up) std::cout << "#"; else std::cout << " ";
			}
            
		}
        std::cout << "\n";
	}

	return;
}

std::string getMaze(){

    std::string out = "";
	int x, y;
	int width=(xsize-1)*2-1;
	int height=(ysize-1)*2-1;

    for(y = height-1; y >= 0; y--){
		for(x = 0; x <= width - 1; x++){
			if(x%2 == 1 && y%2 == 1){
				
				if(MAZE[x/2+1][y/2+1].in) out += " "; else out += "#";
				
			}else if(x%2 == 0 && y%2 == 0){
				out += "#";
			}else if(x%2 == 0 && y%2 == 1){
				if(MAZE[x/2+1][y/2+1].left) out += "#"; else out += " ";
			}else if(x%2 == 1 && y%2 == 0){
				if(MAZE[x/2+1][y/2+1].up) out += "#"; else out += " ";
			}
            
		}        
	}

	return out;
}
