#include <iostream>
#include <cstdlib>

// Inserire qui sotto le definizioni delle funzioni SnowFlake e KochCurve
void KochCurve(double line_length, int level) {
  if (0 == level) {
    std::cout << "F(" << line_length << ");";
    return;
  }
  line_length /= 3.0;
  KochCurve(line_length, level-1);
  std::cout << "RL(60);";
  KochCurve(line_length, level-1);
  std::cout << "RR(120);";
  KochCurve(line_length, level-1);
  std::cout << "RL(60);";
  KochCurve(line_length, level-1);
}

void SnowFlake(double line_length, int level) {
  for(int i = 0; i < 3; i++) {
    KochCurve(line_length, level);
    std::cout << "RR(120);";
  }
  std::cout << std::endl;
}

// Inserire qui sopra le definizioni delle funzioni SnowFlake e KochCurve


int main(int argc, char **argv) {
  int level = 2;
  double line_length = 90.0;

  if (argc == 3) {
    level = strtol(argv[1], NULL, 10);
    line_length = strtod(argv[2], NULL);
  }

  std::cout << "Un fiocco di neve per ll="
           << line_length <<  " e level ="
           << level << " e': " << std::endl;
  SnowFlake(line_length, level);
  std::cout << std::endl;
}
