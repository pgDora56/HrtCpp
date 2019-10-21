#include <stdio.h>
#include <stdlib.h>
#include "Board.h"

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


void Board::print_status_visual()
{
 int i,j;
 char letters[] = {'A', 'B', 'C'};

  // Write Tower
 for(i=0;i<=plate_total;i++)
 {
  for(j=0;j<3;j++)
  {
   poles[j].print_status_visual(i,plate_total);
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


