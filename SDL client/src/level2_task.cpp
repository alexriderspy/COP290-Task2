#include <levels.hpp>

Level2::Level2(){
    hostel = std::vector <bool>(4,false);
    scoops=std::vector <bool>(3,false);
    library= std::vector <bool>(4,false);
    lawn= std::vector <bool>(4,false);
    sac=std::vector <bool>(3,false);

    pos_hostel = std::vector<std::pair<int,int>>(4);
    pos_scoops = std::vector<std::pair<int,int>>(3);
    pos_library = std::vector<std::pair<int,int>>(4);
    pos_lawn = std::vector<std::pair<int,int>>(4);
    pos_sac = std::vector<std::pair<int,int>>(3);

    pos_lawn = {{59,46},{71,46},{59,34},{71,34}};
    pos_sac = {{37,21},{28,31},{28,21}};
    // pos_hostel = {};
    // pos_scoops = {};
    // pos_library = {};

}

bool Level2::checkHostel(Player&dot,LTexture* currentTexture){
    
    if(currentTexture == &gHostelTexture){
        for(int i=0;i<4;++i){
            if(dot.getmPosX()/TILE_SIZE == pos_hostel[i].first && dot.getmPosY()/TILE_SIZE == pos_hostel[i].second){
                hostel[i] = true;
            }
        }
    }

    if(!hostel[0] || !hostel[1] || !hostel[2] || !hostel[3]) return false;
    return true;
}

bool Level2::checkScoops(Player&dot,LTexture* currentTexture){
    if(currentTexture == &gScoopsTexture){
        if(dot.getmPosX()/TILE_SIZE == pos_scoops[0].first && dot.getmPosY()/TILE_SIZE == pos_scoops[0].second){
            scoops[0] = true;
        }
        if(dot.getmPosX()/TILE_SIZE == pos_scoops[1].first && dot.getmPosY()/TILE_SIZE == pos_scoops[1].second){
            scoops[1] = true;
        }
        if(dot.getmPosX()/TILE_SIZE == pos_scoops[2].first && dot.getmPosY()/TILE_SIZE == pos_scoops[2].second){
            scoops[2] = true;
        }
    }

    if(scoops[0] ==false || scoops[1] == false || scoops[2] == false) return false;
    return true;

}

bool Level2::checkLibrary(Player&dot,LTexture* currentTexture){
    
    if(currentTexture == &gLibraryTexture){
        for(int i=0;i<4;++i){
            if(dot.getmPosX()/TILE_SIZE == pos_library[i].first && dot.getmPosY()/TILE_SIZE == pos_library[i].second){
                library[i] = true;
            }
        }
    }

    if(!library[0] || !library[1] || !library[2] || !library[3]) return false;
    return true;
}

bool Level2::checkLawn(Player & dot){
    for(int i=0;i<4;++i){
        if(dot.getmPosX()/TILE_SIZE == pos_lawn[i].first && dot.getmPosY()/TILE_SIZE == pos_lawn[i].second){
            lawn[i]=true;
        }
    }
    
    for(int i=0;i<4;++i){

        if(lawn[i]==false){
            return false;
        }
        
    }
    return true;
}


bool Level2::checkSac(Player&dot){
    
        for(int i=0;i<3;++i){
            if(dot.getmPosX()/TILE_SIZE == pos_sac[i].first && dot.getmPosY()/TILE_SIZE == pos_sac[i].second){
                sac[i] = true;
            }
        }

    if(!sac[0] || !sac[1] || !sac[2] ) return false;
    return true;
}

void Level2::print(){
    std::cout<<"begin\n";
    for(int i=0;i<4;++i){
        std::cout<<hostel[i]<<' ';
    }
    std::cout<<'\n';

    for(int i=0;i<4;++i){
        std::cout<<scoops[i]<<' ';
    }
    std::cout<<'\n';

    for(int i=0;i<4;++i){
        std::cout<<library[i]<<' ';
    }
    std::cout<<'\n';

    for(int i=0;i<4;++i){
        std::cout<<lawn[i]<<' ';
    }
    std::cout<<'\n';

    for(int i=0;i<4;++i){
        std::cout<<sac[i]<<' ';
    }
    std::cout<<'\n';
}