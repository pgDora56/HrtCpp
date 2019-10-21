#include <stdio.h> 
#include <stdlib.h>
#include "03-hanoi02.h"


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

void Pole::print_status(int h, int maxi)
{
 // printf("> %d %d -> %d", h, maxi, plates[maxi-h].value);
 int i,j;
 if(plate_size<maxi-h+1){
  for(j=0;j<maxi;j++)
  {
   printf(" ");
  }
  printf("|");
  for(j=0;j<maxi;j++)
  {
   printf(" ");
  }
 }
 else{
   int plate = plates[maxi-h].value;
   for(j=0;j<=maxi-plate;j++)
   {
    printf(" ");
   }
   for(j=0;j<2*plate-1;j++)
   {
    printf("X");
   }
   for(j=0;j<=maxi-plate;j++)
   {
    printf(" ");
   }
  }
}

int Pole::get_plate_size(){
 return plate_size;
}

void Board::print_status()
{
 int i,j;
 char letters[] = {'A', 'B', 'C'};

  // Write Tower
 for(i=0;i<=plate_total;i++)
 {
  for(j=0;j<3;j++)
  {
   poles[j].print_status(i,plate_total);
  }
   printf("\n");
 }

 // Write Footer
 for(i=0;i<3;i++){
  for(j=0;j<plate_total;j++)
  {
   printf("-");
  }
  printf("+");
  for(j=0;j<plate_total;j++)
  {
   printf("-");
  }
 }
 printf("\n");

 for(i=0;i<3;i++)
 {
  for(j=0;j<plate_total;j++)
  {
   printf(" ");
  }
  printf("%c", letters[i]);
  for(j=0;j<plate_total;j++)
  {
   printf(" ");
  }
 }
 printf("\n");
}

/**
 * Move plate - pole to pole
 */
void Board::move(int x, int y)
{
 poles[y].add(poles[x].pop());
 printf("\n\n\n");
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

