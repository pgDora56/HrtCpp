class Plate{
 public:
  int value;
  Plate()
  {
   value = 0;
  }
  Plate(int val)
  {
   value = val;
  }
};

class Pole{ 
 Plate* plates;
 int plate_size;
 public:
 int value;

 Pole(){
  plate_size = -1;
 }
 Pole(int max)
 {
  plates = new Plate[max];
  plate_size = 0;
 }

 Pole(int max, int initial_plate)
 {
  plates = new Plate[max];
  plate_size = initial_plate;
  for(int i = 0; i < initial_plate; i++)
  {
   plates[i] = Plate(max-i);
  }
 }

 void add(Plate plate);
 void print_status(int h, int maxi);
 int get_plate_size();
 Plate pop();
};

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
  void move(int before_pole, int after_pole, int move_size);
};  

