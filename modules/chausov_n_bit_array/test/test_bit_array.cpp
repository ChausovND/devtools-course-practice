// Copyright 2022 Chausov Nikita
#include <gtest/gtest.h>

#include <string>

#include "include/bit_array.h"

TEST(Chausov_BitArray_Test, DefaultConstructor) {
  BitArray arr;
  ASSERT_TRUE(arr.IsEmpty());
}

TEST(Chausov_BitArray_Test, InitializationConstructor) {
  BitArray arr(2);
  EXPECT_EQ(2, arr.GetSizeBits());
}

TEST(Chausov_BitArray_Test, Set_Get) {
  BitArray arr(2);
  arr.SetBit(0, 1);
  EXPECT_EQ(1, arr.GetBit(0));
}

TEST(Chausov_BitArray_Test, Set_Get_Max) {
  BitArray arr(8);
  arr.SetBit(7, 1);
  EXPECT_EQ(1, arr.GetBit(7));
}

TEST(Chausov_BitArray_Test, Set_Get_OutOfRange) {
  BitArray arr(8);
  ASSERT_ANY_THROW(arr.SetBit(8, 1));
  ASSERT_ANY_THROW(arr.GetBit(8));
}

TEST(Chausov_BitArray_Test, Set_Get_Feature) {
  BitArray arr(2);
  arr.SetBit(6, 1);
  EXPECT_EQ(1, arr.GetBit(6));
}

TEST(Chausov_BitArray_Test, CopyConstructor) {
  BitArray arr(10);
  for (int i = 0; i < arr.GetSizeBits(); i++) arr.SetBit(i, i % 2);
  BitArray arrC(arr);
  for (int i = 0; i < arrC.GetSizeBits(); i++)
    EXPECT_EQ(arr.GetBit(i), arrC.GetBit(i));
}

TEST(Chausov_BitArray_Test, DeleteArray) {
  BitArray arr(10);
  arr.DeleteArray();
  ASSERT_TRUE(arr.IsEmpty());
}

TEST(Chausov_BitArray_Test, DeleteEmptyArray) {
  BitArray arr;
  ASSERT_ANY_THROW(arr.DeleteArray());
}

TEST(Chausov_BitArray_Test, AllocateEmptyArray) {
  BitArray arr;
  arr.AllocateArray(10);
  ASSERT_FALSE(arr.IsEmpty());
}

TEST(Chausov_BitArray_Test, TryToAllocateMotEmptyArray) {
  BitArray arr(10);
  ASSERT_ANY_THROW(arr.AllocateArray(20));
}

TEST(Chausov_BitArray_Test, GetSizeBits) {
  BitArray arr(10);
  EXPECT_EQ(10, arr.GetSizeBits());
}
