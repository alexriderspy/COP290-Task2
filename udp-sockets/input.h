#pragma once

#include <vector>
#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>

namespace input_device {

enum {
  up = 0,
  down,
  left,
  right,
  x,
  c,
  space,
  enter,
  
  start,
  select,
  count,
};

}  // namespace input_device

class InputManager {

  bool edge_key_[2][input_device::count];
  bool press_key_[2][input_device::count];

 public:
  InputManager() noexcept {}

  inline void update() noexcept {
    unsigned int num_devices_ = 2;
    bool new_press_key[num_devices_][input_device::count];
    for (unsigned int i = 0; i < num_devices_; ++i) {
      for (unsigned int j = 0; j < input_device::count; ++j) {
        new_press_key[i][j] = false;
      }
    }

    const Uint8 *state = SDL_GetKeyboardState(nullptr);

    new_press_key[0][input_device::up] =
      state[SDL_SCANCODE_UP] == SDL_PRESSED
      || state[SDL_SCANCODE_I] == SDL_PRESSED;
    new_press_key[0][input_device::down] =
      state[SDL_SCANCODE_DOWN] == SDL_PRESSED
      || state[SDL_SCANCODE_K] == SDL_PRESSED;
    new_press_key[0][input_device::left] =
      state[SDL_SCANCODE_LEFT] == SDL_PRESSED
      || state[SDL_SCANCODE_J] == SDL_PRESSED;
    new_press_key[0][input_device::right] =
      state[SDL_SCANCODE_RIGHT] == SDL_PRESSED
      || state[SDL_SCANCODE_L] == SDL_PRESSED;

    new_press_key[1][input_device::up] = state[SDL_SCANCODE_W] == SDL_PRESSED;
    new_press_key[1][input_device::down] = state[SDL_SCANCODE_S] == SDL_PRESSED;
    new_press_key[1][input_device::left] = state[SDL_SCANCODE_A] == SDL_PRESSED;
    new_press_key[1][input_device::right] = state[SDL_SCANCODE_D] == SDL_PRESSED;


    new_press_key[0][input_device::space] = state[SDL_SCANCODE_SPACE] == SDL_PRESSED;
    new_press_key[0][input_device::enter] = state[SDL_SCANCODE_RETURN] == SDL_PRESSED;
    new_press_key[0][input_device::x] = state[SDL_SCANCODE_X] == SDL_PRESSED;
    new_press_key[1][input_device::space] = state[SDL_SCANCODE_SPACE] == SDL_PRESSED;
    new_press_key[1][input_device::enter] = state[SDL_SCANCODE_RETURN] == SDL_PRESSED;
    new_press_key[1][input_device::x] = state[SDL_SCANCODE_X] == SDL_PRESSED;


    for (unsigned int i = 0; i < num_devices_; ++i) {
      for (unsigned int j = 0; j < input_device::count; ++j) {
        edge_key_[i][j] = !press_key_[i][j] && new_press_key[i][j];
        press_key_[i][j] = new_press_key[i][j];
      }
    }
    unsigned char tobesent[input_device::count+1];
    tobesent[0]='I';
    for(int i = 1; i < input_device::count+1; i++){
      if(press_key_[0][i]){
        tobesent[i] = '1';
      }
      else{
        tobesent[i] = '0';
      }
    }
  }

  inline bool edge_key_p(const unsigned char player_type,
                         const unsigned char button) const noexcept {
    return edge_key_[player_type][button];
  }

  inline bool press_key_p(const unsigned char player_type,
                          const unsigned char button) const noexcept {
    return press_key_[player_type][button];
  }

  ~InputManager() noexcept {}
};
