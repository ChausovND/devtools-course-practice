// Copyright 2022 Chausov Nikita

#ifndef MODULES_PODOVINNIKOV_A_BULLS_AND_COWS_INCLUDE_BULLSANDCOWS_APP_H_
#define MODULES_PODOVINNIKOV_A_BULLS_AND_COWS_INCLUDE_BULLSANDCOWS_APP_H_

#include <string>

class CLPApplication {
 public:
  CLPApplication();
  std::string operator()(int argc, const char** argv);

 private:
  std::string help();
  std::string argument_error();
};

#endif  //  MODULES_PODOVINNIKOV_A_BULLS_AND_COWS_INCLUDE_BULLSANDCOWS_APP_H_
