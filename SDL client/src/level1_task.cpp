#include <levels.hpp>

Level1::Level1(){
    lhc_vis = std::vector<bool>(4,false);
    hasEaten = std::vector<bool>(2,false);
    football = std::vector<bool>(4,false);
    pos_football = std::vector<std::pair<int,int>>(4);
    pos_LHC = std::vector<std::pair<int,int>>(4);
    pos_staff_canteen = std::vector<std::pair<int,int>>(2);

    pos_football = {{47,34},{56,34},{47,60},{56,60}};

    pos_LHC = {{0,5},{0,11},{31,11},{31,4}};

    pos_staff_canteen = {{0,7},{16,0}};
}

bool Level1::checkLHC(Player&dot,LTexture* currentTexture){
    
    if(currentTexture == &gLHCTexture){
        for(int i=0;i<4;++i){
            if(dot.getmPosX()/TILE_SIZE == pos_LHC[i].first && dot.getmPosY()/TILE_SIZE == pos_LHC[i].second){
                lhc_vis[i] = true;
            }
        }
    }

    if(!lhc_vis[0] || !lhc_vis[1] || !lhc_vis[2] || !lhc_vis[3]) return false;
    return true;
}

bool Level1::checkStaffCanteen(Player&dot,LTexture* currentTexture){
    if(currentTexture == &gStaffCanteen){
        if(dot.getmPosX()/TILE_SIZE == pos_staff_canteen[0].first && dot.getmPosY()/TILE_SIZE == pos_staff_canteen[0].second){
            hasEaten[0] = true;
        }
        if(dot.getmPosX()/TILE_SIZE == pos_staff_canteen[1].first && dot.getmPosY()/TILE_SIZE == pos_staff_canteen[1].second){
            hasEaten[1] = true;
        }
    }

    if(hasEaten[0] ==false || hasEaten[1] == false) return false;
    return true;

}

bool Level1::checkFootball(Player & dot){
    for(int i=0;i<4;++i){
        if(dot.getmPosX()/TILE_SIZE == pos_football[i].first && dot.getmPosY()/TILE_SIZE == pos_football[i].second){
            football[i]=true;
        }
    }
    
    for(int i=0;i<4;++i){
        if(football[i]==false){
            return false;
        }
        
    }
    return true;
}

void Level1::print(){
    std::cout<<lhc_vis[0]<<' '<<lhc_vis[1]<<' '<<lhc_vis[2]<<' '<<lhc_vis[3]<<'\n';
    std::cout<<hasEaten[0]<<' '<<hasEaten[1]<<'\n';
    std::cout<<football[0]<<' '<<football[1]<<' '<<football[2]<<' '<<football[3]<<'\n';
    
}