// Copyright 2022 Chausov Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(CHAUSOV_NIKITA_COMPLEXNUMBER, can_create_complex_number) {
  ASSERT_NO_THROW(ComplexNumber z(1.0, 2.0));
}

TEST(CHAUSOV_NIKITA_COMPLEXNUMBER, getRe_getIm_works_correct) {
  double re = 1.0;
  double im = 2.0;
  ComplexNumber z(re, im);
  EXPECT_DOUBLE_EQ(re, z.getRe());
  EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(CHAUSOV_NIKITA_COMPLEXNUMBER, setRe_setIm_works_correct) {
  ComplexNumber z;
  double re = 1.0;
  double im = 1.0;
  z.setRe(re);
  EXPECT_DOUBLE_EQ(re, z.getRe());
  z.setIm(im);
  EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(CHAUSOV_NIKITA_COMPLEXNUMBER, addition_is_correct) {
  double re1 = 1.0, re2 = 3.0;
  double im1 = 2.0, im2 = 4.0;
  ComplexNumber z1(re1, im1), z2(re2, im2), z_res;
  z_res = z1 + z2;
  EXPECT_DOUBLE_EQ(re1 + re2, z_res.getRe());
  EXPECT_DOUBLE_EQ(im1 + im2, z_res.getIm());
}

TEST(CHAUSOV_NIKITA_COMPLEXNUMBER, subtraction_is_correct) {
  double re1 = 1.0, re2 = 3.0;
  double im1 = 2.0, im2 = 4.0;
  ComplexNumber z1(re1, im1), z2(re2, im2), z_res;
  z_res = z1 - z2;
  EXPECT_DOUBLE_EQ(re1 - re2, z_res.getRe());
  EXPECT_DOUBLE_EQ(im1 - im2, z_res.getIm());
}

TEST(CHAUSOV_NIKITA_COMPLEXNUMBER, multiplication_is_correct) {
  double re1 = 1.0, re2 = 3.0;
  double im1 = 2.0, im2 = 4.0;
  ComplexNumber z1(re1, im1), z2(re2, im2), z_res;
  z_res = z1 * z2;
  EXPECT_DOUBLE_EQ(re1 * re2 - im1 * im2, z_res.getRe());
  EXPECT_DOUBLE_EQ(re1 * im2 + re2 * im1, z_res.getIm());
}

TEST(CHAUSOV_NIKITA_COMPLEXNUMBER, division_is_correct) {
  double re1 = 5.0, re2 = 3.5;
  double im1 = 2.5, im2 = -6.0;
  ComplexNumber z1(re1, im1), z2(re2, im2), z_res;
  z_res = z1 / z2;
  double resRe = (re1 * re2 + im1 * im2) / (re2 * re2 + im2 * im2);
  double resIm = (re2 * im1 - re1 * im2) / (re2 * re2 + im2 * im2);
  EXPECT_DOUBLE_EQ(resRe, z_res.getRe());
  EXPECT_DOUBLE_EQ(resIm, z_res.getIm());
}

TEST(CHAUSOV_NIKITA_COMPLEXNUMBER, cant_divide_by_zero) {
  double re1 = 1.0, re2 = 0.0;
  double im1 = 2.0, im2 = 0.0;
  ComplexNumber z1(re1, im1), z2(re2, im2);
  ASSERT_ANY_THROW(z1 / z2);
}
