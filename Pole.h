#ifndef __POLE_H_INCLUDED__
#define ___POLE_H_INCLUDED__

#include "Plate.h"

class Pole{ 
 Plate* plates;
 int plate_size;
 public:
 int value;
 Pole();
 Pole(int max);
 Pole(int max, int initial_plate);
 void add(Plate plate);
 void print_status();
 void print_status_visual(int h, int maxi);
 int get_plate_size();
 Plate pop();
};

#endif
