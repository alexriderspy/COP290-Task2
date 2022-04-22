#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

namespace image {
    enum {
        p1 = 0,
        p2,
        bg,
        enemy,
        fullbg,
        crown,
        coin,
        up,
        down,
        left,
        right,
        a,
        s,
        w,
        d,
        count,
    };
}  

class ImageManager {
  std::vector<SDL_Surface *> all_images;
  SDL_Renderer *renderer_;

  inline void load(const char *path, const unsigned char image_type){
    SDL_Surface *image = IMG_Load(path);
    if (!image) {
      std::cerr << "error: " << IMG_GetError() << '\n';
      exit(EXIT_FAILURE);
    }
    all_images[image_type] = image;
  }

 public:
  ImageManager(SDL_Renderer *renderer) noexcept : renderer_(renderer) {
    all_images.reserve(image::count);

    const int flag = IMG_INIT_PNG;
    if ((IMG_Init(flag) & flag) != flag) {
      std::cerr << "error: " << IMG_GetError() << '\n';
      exit(EXIT_FAILURE);
    }

    load("./data/cow.png", image::p1);
    load("./data/qq.png", image::p2);
    load("./data/9.png", image::bg);
    load("./data/enemy.png", image::enemy);
    load("./data/r2.png", image::fullbg);
    load("./data/crown.png", image::crown);
    load("./data/r.png", image::coin);
    load("./data/down.png", image::down);
    load("./data/up.png", image::up);
    load("./data/left.png", image::left);
    load("./data/right.png", image::right);
    load("./data/a.png", image::a);
    load("./data/s.png", image::s);
    load("./data/w.png", image::w);
    load("./data/d.png", image::d);
  }

  inline SDL_Texture *get(const unsigned char image_type) const{
    return SDL_CreateTextureFromSurface(renderer_, all_images[image_type]);
  }

  inline void render_copy(SDL_Texture &texture, const SDL_Rect &src, const SDL_Rect &dst) const {
    SDL_RenderCopy(renderer_, &texture, &src, &dst);
  }

  ~ImageManager(){ 
      atexit(IMG_Quit); 
    }
};
