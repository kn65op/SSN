/* 
 * File:   NeuronTest.cpp
 * Author: tomko
 *
 * Created on 2012-03-15, 16:31:46
 */

#include <stdlib.h>
#include <iostream>
#include "../../../gtest/gtest_src/include/gtest/gtest.h"
#include "Neuron.h"

/**
 * SQLiteController
 */
TEST(Constructor, Good)
{
  ASSERT_TRUE(true);
}

TEST(Constructor, Bad)
{
  
}


int main(int argc, char **argv)
{

  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();

}

