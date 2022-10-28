// Copyright 2022 Chausov Nikita

#ifndef MODULES_CHAUSOV_N_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_
#define MODULES_CHAUSOV_N_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_

#include <string>

class BitArray {
 private:
  char* arr;
  unsigned int bitSize;
  unsigned int size;

 public:
  BitArray();
  explicit BitArray(const unsigned int _bitSize);
  BitArray(const BitArray& arrCopy);
  ~BitArray();

  int GetSizeBits();
  void SetBit(unsigned int bitPos, bool val);
  bool GetBit(unsigned int bitPos);

  bool IsEmpty();
  void DeleteArray();
  void AllocateArray(int _bitSize);
};

#endif  // MODULES_CHAUSOV_N_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_
