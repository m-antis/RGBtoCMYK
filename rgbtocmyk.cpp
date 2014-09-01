//  Created by Michael Antis on 3/29/14.
//  Copyright (c) 2014 Michael Antis. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <deque>

using namespace std;

void outOfRange();
void isValid(deque<float>);
float maximum(float, float, float);
void RGBtoCMYK(float, float, float, float &, float &, float &, float &);

const int NUMBER_OF_COLORS = 9;
int main()
{
  // float blue, green, red;
  float black = 0, cyan = 0, magenta = 0, yellow = 0;
  // int count = 0;

  ifstream input;
  input.open("/Users/michael_antis/colors.txt");
  ofstream output;
  output.open("/Users/michael_antis/cmyk.txt");

  if (!input.is_open()) {
    cout << "Error. File not found.";
  }

  if (!output.is_open()) {
    cout << "Error. File not found.";
  }

  deque<float> colors;
  float color;
  while (input >> color) {
    colors.push_back(color);
  }

  for (int i = 0; i < colors.size(); i++) {
    cout << colors[i] << " ";
  }
  // isValid(colors);

  for (int i = 0; i < colors.size() % (NUMBER_OF_COLORS * 2); i++) {

    RGBtoCMYK(colors[i], colors[i + 1], colors[i + 2], cyan, magenta, yellow,
    black);
    output << cyan << " " << magenta << " " << yellow << " " << black << endl;
  }

  input.close();
  output.close();

  return 0;
}

void isValid(deque<float> colors)
{
  // for (int i = 0; i < colors.size(); i++)
  // if (colors[i] < 0 || colors[i] > 255)
  // colors.erase(colors.begin() + i, colors.begin() + (i + 2));
}

float maximum(float red, float green, float blue)
{
  float rgb[] = {red, green, blue};
  float highest = rgb[0];

  for (int i = 1; i < 3; i++) {
    if (rgb[i] > highest)
      highest = rgb[i];
    }
    return highest;
  }

  void RGBtoCMYK(float r, float g, float b, float &c, float &m, float &y,
  float &k)
  {
    float w;

    if (r == 0 && g == 0 && b == 0) {
      c = 0;
      m = 0;
      y = 0;
      k = 1;
    } else {
      w = maximum(r / 255, g / 255, b / 255);
      c = (w - (r / 255)) / w;
      m = (w - (g / 255)) / w;
      y = (w - (b / 255)) / w;
      k = 1.0 - w;
    }
  }
