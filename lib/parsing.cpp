#include "parsing.h"


void ParseArguments(int argc, char** argv, ParseOptions& arguments_parsing) {
  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "-i") == 0) {
      if (i + 1 < argc) {
        ++i;
        arguments_parsing.input = argv[i];
      } else {
        std::cerr << "Error: Missing argument for -i" << "\n";
      }
    } else if (strcmp(argv[i], "--input") == 0) {
      if (i + 1 < argc) {
        ++i;
        arguments_parsing.input = argv[i];
      } else {
        std::cerr << "Error: Missing argument for --input" << "\n";
      }
    } else if (strcmp(argv[i], "--output") == 0) {
      if (i + 1 < argc) {
        ++i;
        arguments_parsing.output = argv[i];
      } else {
        std::cerr << "Error: Missing argument for --output" << "\n";
      }
    } else if (strcmp(argv[i], "-o") == 0) {
      if (i + 1 < argc) {
        ++i;
        arguments_parsing.output = argv[i];
      } else {
        std::cerr << "Error: Missing argument for -o" << "\n";
      }
    } else if (strcmp(argv[i], "-m") == 0) {
      if (i + 1 < argc) {
        ++i;
        arguments_parsing.max_iter = atoi(argv[i]);
      } else {
        std::cerr << "Error: Missing argument for -m" << "\n";
      }
    } else if (strcmp(argv[i], "--max-iter") == 0) {
      if (i + 1 < argc) {
        ++i;
        arguments_parsing.max_iter = atoi(argv[i]);
      } else {
        std::cerr << "Error: Missing argument for --max-iter" << "\n";
      }
    } else if (strcmp(argv[i], "-f") == 0) {
      if (i + 1 < argc) {
        ++i;
        arguments_parsing.freq = atoi(argv[i]);
      } else {
        std::cerr << "Error: Missing argument for -f" << "\n";
      }
    } else if (strcmp(argv[i], "--freq") == 0) {
      if (i + 1 < argc) {
        ++i;
        arguments_parsing.freq = atoi(argv[i]);
      } else {
        std::cerr << "Error: Missing argument for --freq" << "\n";
      }
    } else {
      std::cerr << "Error: Unknown argument - " << argv[i] << '\n';
    }
  }
}
