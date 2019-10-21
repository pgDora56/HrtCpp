#include <stdlib.h>
#include "Board.h"

int main(int argc, char *argv[])
{
 int n = atoi(argv[1]);
 Board board;
 board = Board(n);
 board.print_status();
 board.move(0,2,board.plate_total);
 return 0;
}


