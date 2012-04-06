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
#include "LinearActivationFunction.h"

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

TEST(RealWordTest, XORLinear)
{
  typedef NeuralNetwork<double, LinearActivationFunction<double >> network;
  network nn;
  //nn.setActivationfunction(LinearActivationFunction<double>(10));
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
    std::vector<double> o(1);
    
    nn.setInput(in1.begin(), in1.end());
    o = nn.calcOutput();
    nn.learn(out0.begin(), out0.end());
//
//    std::cout << "Wynik0: " << o[0] << "\n";
//    nn.printWages();

    nn.setInput(in2.begin(), in2.end());
    o = nn.calcOutput();
    nn.learn(out1.begin(), out1.end());
//
//    std::cout << "Wynik1: " << o[0] << "\n";
//    nn.printWages();

    nn.setInput(in3.begin(), in3.end());
    o = nn.calcOutput();
    nn.learn(out1.begin(), out1.end());
//
//    std::cout << "Wynik1: " << o[0] << "\n";
//    nn.printWages();

    nn.setInput(in4.begin(), in4.end());
    o = nn.calcOutput();
    nn.learn(out0.begin(), out0.end());
//
//    std::cout << "Wynik0: " << o[0] << "\n";
//    nn.printWages();

  }
  //test
  std::vector<double> out;
  std::vector<double> o(4);
  nn.setInput(in1.begin(), in1.end());
  out = nn.calcOutput();
  o[0] = out[0];
  EXPECT_LT(out[0], 0.1);
  nn.setInput(in2.begin(), in2.end());
  out = nn.calcOutput();
  o[1] = out[0];
  EXPECT_GT(out[0], 0.9);
  nn.setInput(in3.begin(), in3.end());
  out = nn.calcOutput();
  o[2] = out[0];
  EXPECT_GT(out[0], 0.9);
  nn.setInput(in4.begin(), in4.end());
  out = nn.calcOutput();
  o[3] = out[0];
  EXPECT_LT(out[0], 0.1);

  std::cout << o[0] << " " << o[1] << " " << o[2] << " " << o[3] << "\n";
}

TEST(RealWordTest, XORStep)
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
  for (int i = 0; i < 1000; ++i)
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

TEST(RealWordTest, LiczbyLinear)
{
  typedef NeuralNetwork<double, LinearActivationFunction<double >> network;
  network nn;
  nn.setEntries(7);
  nn.setExits(10);
  nn.setLayersCount(2);
  nn.setNeurons(1, 7);
  nn.init();
  std::vector<double> in0 = {1, 1, 1, 1, 1 ,1 ,0};
  std::vector<double> in1 = {0, 1, 1, 0, 0, 0, 0};
  std::vector<double> in2 = {1, 1, 0, 1, 1, 0, 1};
  std::vector<double> in3 = {1, 1, 1, 1, 0, 0, 1};
  std::vector<double> in4 = {0, 1, 1, 0, 0, 1, 1};
  std::vector<double> in5 = {1, 0, 1, 1, 0, 1, 1};
  std::vector<double> in6 = {1, 0, 1, 1, 1, 1, 1};
  std::vector<double> in7 = {1, 1, 1, 0, 0, 0, 0};
  std::vector<double> in8 = {1, 1, 1, 1, 1, 1, 1};
  std::vector<double> in9 = {1, 1, 1, 1, 0, 1, 1};
  std::vector<double> out0 = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  std::vector<double> out1 = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
  std::vector<double> out2 = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
  std::vector<double> out3 = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
  std::vector<double> out4 = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
  std::vector<double> out5 = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
  std::vector<double> out6 = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
  std::vector<double> out7 = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
  std::vector<double> out8 = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0};
  std::vector<double> out9 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
  //uczenie
  for (int i = 0; i < 0; ++i)
  {
    nn.setInput(in0.begin(), in0.end());
    nn.calcOutput();
    nn.learn(out0.begin(), out0.end());
    nn.setInput(in1.begin(), in1.end());
    nn.calcOutput();
    nn.learn(out1.begin(), out1.end());
    nn.setInput(in2.begin(), in2.end());
    nn.calcOutput();
    nn.learn(out2.begin(), out2.end());
    nn.setInput(in3.begin(), in3.end());
    nn.calcOutput();
    nn.learn(out3.begin(), out3.end());
    nn.setInput(in4.begin(), in4.end());
    nn.calcOutput();
    nn.learn(out4.begin(), out4.end());
    nn.setInput(in5.begin(), in5.end());
    nn.calcOutput();
    nn.learn(out5.begin(), out5.end());
    nn.setInput(in6.begin(), in6.end());
    nn.calcOutput();
    nn.learn(out6.begin(), out6.end());
    nn.setInput(in7.begin(), in7.end());
    nn.calcOutput();
    nn.learn(out7.begin(), out7.end());
    nn.setInput(in8.begin(), in8.end());
    nn.calcOutput();
    nn.learn(out8.begin(), out8.end());
    nn.setInput(in9.begin(), in9.end());
    nn.calcOutput();
    nn.learn(out9.begin(), out9.end());
  }
  //test
  std::vector<double> out;
  nn.setInput(in0.begin(), in0.end());
  out = nn.calcOutput();
  for (auto o : out)
  {
    std::cout << o << " ";
  }
  std::cout << "\n";
  nn.setInput(in1.begin(), in1.end());
  out = nn.calcOutput();
  for (auto o : out)
  {
    std::cout << o << " ";
  }
  std::cout << "\n";
  nn.setInput(in2.begin(), in2.end());
  out = nn.calcOutput();
  for (auto o : out)
  {
    std::cout << o << " ";
  }
  std::cout << "\n";
  nn.setInput(in3.begin(), in3.end());
  out = nn.calcOutput();
  for (auto o : out)
  {
    std::cout << o << " ";
  }
  std::cout << "\n";
  nn.setInput(in4.begin(), in4.end());
  out = nn.calcOutput();
  for (auto o : out)
  {
    std::cout << o << " ";
  }
  std::cout << "\n";
  nn.setInput(in5.begin(), in5.end());
  out = nn.calcOutput();
  for (auto o : out)
  {
    std::cout << o << " ";
  }
  std::cout << "\n";
  nn.setInput(in6.begin(), in6.end());
  out = nn.calcOutput();
  for (auto o : out)
  {
    std::cout << o << " ";
  }
  std::cout << "\n";
  nn.setInput(in7.begin(), in7.end());
  out = nn.calcOutput();
  for (auto o : out)
  {
    std::cout << o << " ";
  }
  std::cout << "\n";
  nn.setInput(in8.begin(), in8.end());
  out = nn.calcOutput();
  for (auto o : out)
  {
    std::cout << o << " ";
  }
  std::cout << "\n";
  nn.setInput(in9.begin(), in9.end());
  out = nn.calcOutput();
  for (auto o : out)
  {
    std::cout << o << " ";
  }
  std::cout << "\n";
  nn.printWages();
}

int main(int argc, char **argv)
{

  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();

}

