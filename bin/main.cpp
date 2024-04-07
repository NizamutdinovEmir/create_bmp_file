#include "../lib/create_bmp.h"
#include "../lib/parsing.h"
#include "../lib/sandpile.h"


int main(int argc, char** argv) {
  setlocale(LC_ALL, "Russian");
  ParseOptions arguments_parsing;
  Gridsize arguments;
  ParseArguments(argc, argv, arguments_parsing);


  if (arguments_parsing.input == "C:\\Users\\emirn\\ClionProjects\\labwork3\\test.tsv" || arguments_parsing.output == "C:\\Users\\emirn\\ClionProjects\\labwork3") {
    std::cout << "For User : you forgot to enter the input data, we used the default data" << std::endl;
  }


  std::cout << "Input File: " << arguments_parsing.input << std::endl;
  std::cout << "Output Directory: " << arguments_parsing.output << std::endl;



  const char* path = arguments_parsing.input;
  std::ifstream fin(path);
  if (!fin.is_open()) {
    std::cerr << "Error with opening file " << path << std::endl;
    exit(1);
  }
  std::cout << "reading input start" << '\n';
  arguments.length = 0;
  arguments.width = 0;



  int16_t MaxWidth=0;
  int16_t MaxLenght=0;
  uint64_t pixels;
  while (fin.good()) {
    fin >> MaxWidth;
    fin >> MaxLenght;
    fin >> pixels;
    if (arguments.width <= MaxWidth){
      arguments.width = MaxWidth + 1;
    }
    if (arguments.length <= MaxLenght) {
      arguments.length = MaxLenght + 1;
    }
    std::cout << "ReadingInput finished. Length: " << arguments.length << ", Width: " << arguments.width << std::endl;
  }
  fin.close();


  uint64_t** matrix;
  matrix = new uint64_t*[arguments.width];
  for (int16_t i = 0; i < arguments.width; ++i) {
    matrix[i] = new uint64_t[arguments.length];
    for (int16_t j = 0; j < arguments.length; ++j) {
      matrix[i][j] = 0;
    }
  }

  int PlaceWith4 = 0;
  ReadTSV(arguments_parsing.input, matrix, arguments, PlaceWith4);
  int now_iterations = 0;

  while (PlaceWith4 != 0) {
    Iteration(matrix, arguments, PlaceWith4);
    now_iterations++;
      if (arguments_parsing.freq != 0) {
        if (now_iterations % arguments_parsing.freq == 0 && PlaceWith4 != 0) {
          CreateBmp(arguments_parsing.output, matrix, arguments);
        }
      }
      if (now_iterations == arguments_parsing.max_iter) {
        break;
    }
  }


  CreateBmp(arguments_parsing.output, matrix, arguments);

  return 0;
}
