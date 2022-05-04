#include <levels.hpp>

Level1::Level1(){
    lhc_vis = std::vector<bool>(4,false);
    hasEaten = std::vector<bool>(2,false);
    football = std::vector<bool>(4,false);
    pos = std::vector<std::pair<int,int>>(4);

    pos[0] = {47,34};
    pos[1] = {56,34};
    pos[2] = {47,60};
    pos[3] = {56,60};
}

bool Level1::checkLHC(Player&dot,LTexture* currentTexture,Coordinates c1,Coordinates c2,Coordinates c3,Coordinates c4){
    
    if(currentTexture == &gLHCTexture){
        if(dot.getmPosX()/TILE_SIZE == c1.x && dot.getmPosY()/TILE_SIZE == c1.y){
            lhc_vis[0] = true;
        }
        if(dot.getmPosX()/TILE_SIZE == c2.x && dot.getmPosY()/TILE_SIZE == c2.y){
            lhc_vis[1] = true;
        }
        if(dot.getmPosX()/TILE_SIZE == c3.x && dot.getmPosY()/TILE_SIZE == c3.y){
            lhc_vis[2] = true;
        }
        if(dot.getmPosX()/TILE_SIZE == c4.x && dot.getmPosY()/TILE_SIZE == c4.y){
            lhc_vis[3] = true;
        }
    }

    if(!lhc_vis[0] || !lhc_vis[1] || !lhc_vis[2] || !lhc_vis[3]) return false;
    return true;
}

bool Level1::checkStaffCanteen(Player&dot,LTexture* currentTexture,Coordinates c1,Coordinates c2){
    if(currentTexture == &gStaffCanteen){
        if(dot.getmPosX()/TILE_SIZE == c1.x && dot.getmPosY()/TILE_SIZE == c1.y){
            hasEaten[0] = true;
        }
        if(dot.getmPosX()/TILE_SIZE == c2.x && dot.getmPosY()/TILE_SIZE == c2.y){
            hasEaten[1] = true;
        }
    }

    if(hasEaten[0] ==false || hasEaten[1] == false) return false;
    return true;

}

bool Level1::checkFootball(Player & dot){
    for(int i=0;i<4;++i){
        if(dot.getmPosX()/TILE_SIZE == pos[i].first && dot.getmPosY()/TILE_SIZE == pos[i].second){
            football[i]=true;
        }
    }
    
    for(int i=0;i<4;++i){
        if(dot.getmPosX()/TILE_SIZE == pos[i].first && dot.getmPosY()/TILE_SIZE == pos[i].second){
            if(football[i]==false){
                return false;
            }
        }
    }
    return true;
}

void Level1::print(){
    std::cout<<lhc_vis[0]<<' '<<lhc_vis[1]<<' '<<lhc_vis[2]<<' '<<lhc_vis[3]<<'\n';
    std::cout<<hasEaten[0]<<' '<<hasEaten[1]<<'\n';
    std::cout<<football[0]<<' '<<football[1]<<' '<<football[2]<<' '<<football[3]<<'\n';
    
}