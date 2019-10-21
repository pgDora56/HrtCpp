#include <stdio.h> 
#include <stdlib.h>
#include "03-hanoi01.h"


/**
 * Add plate to pole
 */
void Pole::add(Plate plate)
{
 plates[plate_size] = plate;
 plate_size++;
}

/**
 * Remove top plate and return that
 */
Plate Pole::pop()
{
 if(plate_size <= 0){
  printf("Can't pop!");
 }
 plate_size--;
 Plate tmp = plates[plate_size];
 plates[plate_size] = Plate(0);
 return tmp;
}

void Pole::print_status()
{
 int i;
 for(i=0;i<plate_size;i++)
 {
  printf("%d ",plates[i].value);
 }
}

int Pole::get_plate_size(){
 return plate_size;
}

void Board::print_status()
{
 int i,j;
 char letters[] = {'A', 'B', 'C'};
 for(i = 0; i < 3; i++)
 {
  printf("%c : ", letters[i]);
  poles[i].print_status();
  printf("\n");
 }
 printf("===============\n");
}

/**
 * Move plate - pole to pole
 */
void Board::move(int x, int y)
{
 poles[y].add(poles[x].pop());
 print_status();
}

void Board::move(int before_pole, int after_pole, int move_size)
{
 if(move_size > 1)
 {
  move(before_pole, 3-before_pole-after_pole, move_size-1);
  move(before_pole, after_pole);
  move(3-before_pole-after_pole, after_pole, move_size-1);
 }
 else{
  move(before_pole, after_pole);
 }
}

int main(int argc, char *argv[])
{
 int n = atoi(argv[1]);
 Board board = Board(n);
 board.print_status();
 board.move(0,2,board.plate_total);
 return 0;
}

