/*
The MIT License (MIT)
Copyright (c) 2013 Dylan Jones

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

using namespace std;

class TextureManager
{
   // The textures that are loaded
   static map<string, sf::Texture*> textures;

   // Manually keep track of the order in which textures were loaded, so you can get by index.
   static std::vector<string> order;

   // Constructor that is not used
   TextureManager();
public:
   // Destructor which deletes the textures previously loaded
   ~TextureManager();

   static int getLength();

   // Get texutre by name specified in loadTexture, or return null
   static sf::Texture *getTexture(string name);

   // Get texutre by index in map, or return null
   static sf::Texture *getTexture(int index);

   // Loads the texture and returns a pointer to it
   // If it is already loaded, this function just returns it
   // If it cannot find the file, returns NULL
   static sf::Texture *loadTexture(string name, string path);
};
