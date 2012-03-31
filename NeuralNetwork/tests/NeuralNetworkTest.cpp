/* 
 * File:   NeuronTest.cpp
 * Author: tomko
 *
 * Created on 2012-03-15, 16:31:46
 */

#include <stdlib.h>
#include <iostream>
#include "../../../gtest/gtest_src/include/gtest/gtest.h"
#include "NeuralNetwork.h"
#include "StepActivationFunction.h"

#include <vector>

#define COMMA   ,

/**
 * NeuralNetwork
 */
TEST(StateTest, TryStopWithOutInit)
{
  typedef NeuralNetwork<double, StepActivationFunction<double >> network;
  network nn;
  ASSERT_THROW(nn.stop(), network::WrongState);
}

int main(int argc, char **argv)
{

  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();

}

