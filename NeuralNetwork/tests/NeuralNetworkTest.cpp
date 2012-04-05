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

TEST(RealWordTest, AND)
{
  typedef NeuralNetwork<double, StepActivationFunction<double >> network;
  network nn;
  nn.setEntries(2);
  nn.setExits(1);
  nn.setLayersCount(1);
  nn.init();
  std::vector<double> in1(2);
  std::vector<double> in2(2);
  std::vector<double> in3(2);
  std::vector<double> in4(2);
  in1[0] = 0;
  in1[1] = 0;
  in2[0] = 1;
  in2[1] = 0;
  in3[0] = 0;
  in3[1] = 1;
  in4[0] = 1;
  in4[1] = 1;
  std::vector<double> out0(1);
  std::vector<double> out1(1);
  out0[0] = 0;
  out1[0] = 1;
  //uczenie
  for (int i = 0; i < 100; ++i)
  {
    nn.setInput(in1.begin(), in1.end());
    nn.calcOutput();
    nn.learn(out0.begin(), out0.end());
    nn.setInput(in2.begin(), in2.end());
    nn.calcOutput();
    nn.learn(out0.begin(), out0.end());
    nn.setInput(in3.begin(), in3.end());
    nn.calcOutput();
    nn.learn(out0.begin(), out0.end());
    nn.setInput(in4.begin(), in4.end());
    nn.calcOutput();
    nn.learn(out1.begin(), out1.end());
  }
  //test
  std::vector<double> out;
  nn.setInput(in1.begin(), in1.end());
  out = nn.calcOutput();
  ASSERT_EQ(out[0], 0);
  nn.setInput(in2.begin(), in2.end());
  out = nn.calcOutput();
  ASSERT_EQ(out[0], 0);
  nn.setInput(in3.begin(), in3.end());
  out = nn.calcOutput();
  ASSERT_EQ(out[0], 0);
  nn.setInput(in4.begin(), in4.end());
  out = nn.calcOutput();
  ASSERT_EQ(out[0], 1);
}

TEST(RealWordTest, OR)
{
  typedef NeuralNetwork<double, StepActivationFunction<double >> network;
  network nn;
  nn.setEntries(2);
  nn.setExits(1);
  nn.setLayersCount(1);
  nn.init();
  std::vector<double> in1(2);
  std::vector<double> in2(2);
  std::vector<double> in3(2);
  std::vector<double> in4(2);
  in1[0] = 0;
  in1[1] = 0;
  in2[0] = 1;
  in2[1] = 0;
  in3[0] = 0;
  in3[1] = 1;
  in4[0] = 1;
  in4[1] = 1;
  std::vector<double> out0(1);
  std::vector<double> out1(1);
  out0[0] = 0;
  out1[0] = 1;
  //uczenie
  for (int i = 0; i < 100; ++i)
  {
    nn.setInput(in1.begin(), in1.end());
    nn.calcOutput();
    nn.learn(out0.begin(), out0.end());
    nn.setInput(in2.begin(), in2.end());
    nn.calcOutput();
    nn.learn(out1.begin(), out1.end());
    nn.setInput(in3.begin(), in3.end());
    nn.calcOutput();
    nn.learn(out1.begin(), out1.end());
    nn.setInput(in4.begin(), in4.end());
    nn.calcOutput();
    nn.learn(out1.begin(), out1.end());
  }
  //test
  std::vector<double> out;
  nn.setInput(in1.begin(), in1.end());
  out = nn.calcOutput();
  ASSERT_EQ(out[0], 0);
  nn.setInput(in2.begin(), in2.end());
  out = nn.calcOutput();
  ASSERT_EQ(out[0], 1);
  nn.setInput(in3.begin(), in3.end());
  out = nn.calcOutput();
  ASSERT_EQ(out[0], 1);
  nn.setInput(in4.begin(), in4.end());
  out = nn.calcOutput();
  ASSERT_EQ(out[0], 1);
}

TEST(RealWordTest, XOR)
{
  typedef NeuralNetwork<double, StepActivationFunction<double >> network;
  network nn;
  nn.setEntries(2);
  nn.setExits(1);
  nn.setLayersCount(2);
  nn.setNeurons(1, 2);
  nn.init();
  std::vector<double> in1(2);
  std::vector<double> in2(2);
  std::vector<double> in3(2);
  std::vector<double> in4(2);
  in1[0] = 0;
  in1[1] = 0;
  in2[0] = 1;
  in2[1] = 0;
  in3[0] = 0;
  in3[1] = 1;
  in4[0] = 1;
  in4[1] = 1;
  std::vector<double> out0(1);
  std::vector<double> out1(1);
  out0[0] = 0;
  out1[0] = 1;
  //uczenie
  for (int i = 0; i < 100; ++i)
  {
    nn.setInput(in1.begin(), in1.end());
    nn.calcOutput();
    nn.learn(out0.begin(), out0.end());
    nn.setInput(in2.begin(), in2.end());
    nn.calcOutput();
    nn.learn(out1.begin(), out1.end());
    nn.setInput(in3.begin(), in3.end());
    nn.calcOutput();
    nn.learn(out1.begin(), out1.end());
    nn.setInput(in4.begin(), in4.end());
    nn.calcOutput();
    nn.learn(out0.begin(), out0.end());
  }
  //test
  std::vector<double> out;
  std::vector<double> o(4);
  nn.setInput(in1.begin(), in1.end());
  out = nn.calcOutput();
  o[0] = out[0];
  ASSERT_EQ(out[0], 0);
  nn.setInput(in2.begin(), in2.end());
  out = nn.calcOutput();
  o[1] = out[0];
  ASSERT_EQ(out[0], 1);
  nn.setInput(in3.begin(), in3.end());
  out = nn.calcOutput();
  o[2] = out[0];
  ASSERT_EQ(out[0], 1);
  nn.setInput(in4.begin(), in4.end());
  out = nn.calcOutput();
  o[3] = out[0];
  ASSERT_EQ(out[0], 0);
  
  std::cout << o[0] << " " << o[1] << " " << o[2] << " " << o[3] << "\n";
}

int main(int argc, char **argv)
{

  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();

}

