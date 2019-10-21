#ifdef __BOARD_H_INCLUDED__
#define __BOARD_H_INCLUDED__

#include "Pole.h"

class Board{
 public:
  int plate_total;
  Pole poles[3];

  Board(int plate_size){
   int i;
   plate_total = plate_size;
   poles[0] = Pole(plate_size, plate_size);
   poles[1] = Pole(plate_size);
   poles[2] = Pole(plate_size);
  }
  void move(int x, int y);
  void print_status();
  void print_status_visual();
  void move(int before_pole, int after_pole, int move_size);
};  

#endif
