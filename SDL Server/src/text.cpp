#include <text.hpp>

#include <string>

Text::Text(std::string text){
	this->text=text;
}

std::string Text::getText(){
	return text;
}

void Text::addText(std::string text){
	this->text+=text;
}

LTexture Text::load(SDL_Color textColor){
	LTexture tex;
	if(!tex.loadFromRenderedText(text,textColor)){
		printf("Failed to load text");
	}
	return tex;
}