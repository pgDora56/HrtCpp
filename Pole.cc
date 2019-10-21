#include <stdio.h>
#include <stdlib.h>
#include "Pole.h"

Pole::Pole(){
  plate_size = -1;
 }
Pole::Pole(int max)
 {
  plates = new Plate[max];
  plate_size = 0;
 }

 Pole::Pole(int max, int initial_plate)
 {
  plates = new Plate[max];
  plate_size = initial_plate;
  for(int i = 0; i < initial_plate; i++)
  {
   plates[i] = Plate(max-i);
  }
 }

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


void Pole::print_status_visual(int h, int maxi)
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


