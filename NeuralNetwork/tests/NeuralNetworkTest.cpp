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

/**
 * NeuralNetwork
 */

TEST(StartTest, Create)
{
  typedef NeuralNetwork<double, StepActivationFunction<double >> network;
  ASSERT_NO_THROW(network nn);
}

TEST(StateTest, StateAtCreate)
{
  typedef NeuralNetwork<double, StepActivationFunction<double >> network;
  network nn;
  ASSERT_THROW(nn.stop(), network::WrongState);
  ASSERT_NO_THROW(nn.init());
}

TEST(StateTest, InitStop)
{
  typedef NeuralNetwork<double, StepActivationFunction<double >> network;
  network nn;
  ASSERT_NO_THROW(nn.init());
  ASSERT_THROW(nn.init(), network::WrongState);
  ASSERT_NO_THROW(nn.stop());
  ASSERT_THROW(nn.stop(), network::WrongState);
  ASSERT_NO_THROW(nn.init());
}

TEST(StateTest, AllMethodsWithoutInit)
{
  typedef NeuralNetwork<double, StepActivationFunction<double >> network;
  NeuralNetwork<double, StepActivationFunction<double >> nn;
  ASSERT_NO_THROW(nn.setEntries(2));
  ASSERT_NO_THROW(nn.setExits(2));
  ASSERT_NO_THROW(nn.setLayersCount(1));
  ASSERT_NO_THROW(nn.setEntries(2));
  ASSERT_THROW(nn.setNeurons(1, 2), network::WrongArgument);
  ASSERT_THROW(nn.setLayersCount(4), network::WrongArgument);
  ASSERT_THROW(nn.setNeurons(2, 2), network::WrongArgument);
  std::vector<double> ans;
  ans.assign(2, 1);
  ASSERT_THROW(nn.learn(ans.begin(), ans.end()), network::WrongState);
  ASSERT_THROW(nn.calcOutput(), network::WrongState);
  ASSERT_NO_THROW(nn.init());

}

TEST(StateTest, AllMethodsWithInit)
{
  typedef NeuralNetwork<double, StepActivationFunction<double >> network;
  NeuralNetwork<double, StepActivationFunction<double >> nn;
  ASSERT_NO_THROW(nn.init());
  ASSERT_THROW(nn.setEntries(2), network::WrongState);
  ASSERT_THROW(nn.setExits(2), network::WrongState);
  ASSERT_THROW(nn.setLayersCount(1), network::WrongState);
  ASSERT_THROW(nn.setEntries(2), network::WrongState);
  ASSERT_THROW(nn.setNeurons(1, 2), network::WrongState);
  ASSERT_THROW(nn.setNeurons(2, 2), network::WrongState);
  std::vector<double> ans;
  ans.assign(2, 1);
  ASSERT_NO_THROW(nn.learn(ans.begin(), ans.end()));
  ASSERT_NO_THROW(nn.calcOutput());
  ASSERT_NO_THROW(nn.stop());
}

TEST(CreationTest, Entries2Exit1Layers2)
{
  typedef NeuralNetwork<double, StepActivationFunction<double >> network;
  NeuralNetwork<double, StepActivationFunction<double >> nn;
  ASSERT_NO_THROW(nn.setEntries(2));
  ASSERT_NO_THROW(nn.setExits(1));
  ASSERT_NO_THROW(nn.setLayersCount(2));
  ASSERT_NO_THROW(nn.setEntries(2));
  ASSERT_NO_THROW(nn.setNeurons(1, 2));
  ASSERT_THROW(nn.setNeurons(2, 2), network::WrongArgument);
  ASSERT_NO_THROW(nn.init());
  std::vector<double> ans;
  ans.assign(2, 1);
  ASSERT_NO_THROW(nn.learn(ans.begin(), ans.end()));
  ASSERT_NO_THROW(nn.calcOutput());
  ASSERT_NO_THROW(nn.stop());
}

int main(int argc, char **argv)
{

  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();

}

