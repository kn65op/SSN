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
#include "Link.h"
#include "Exit.h"
#include "Entry.h"
#include "StepActivationFunction.h"
#include "Bias.h"

#include <vector>

/**
 * SQLiteController
 */
TEST(SimpleTest, StepActivationDefault)
{
  Entry<int> a;
  Entry<int> b;
  Neuron<int, StepActivationFunction<int >> n;
  Exit<int> exit;
  std::vector < Link<int >> links(3);
  a.setLinkOut(&links[0]);
  b.setLinkOut(&links[1]);
  n.setLinkIn(&links[0]);
  n.setLinkIn(&links[1]);
  n.setLinkOut(&links[2]);
  exit.setLinkIn(&links[2]);
  a.setEntry(0);
  b.setEntry(0);
  n.calculateOutput();
  ASSERT_EQ(0, exit.getExit());
}

TEST(SimpleTest, StepActivationInt2)
{
  Entry<int> a;
  Entry<int> b;
  Neuron<int, StepActivationFunction<int >> n(StepActivationFunction<int>(2));
  Exit<int> exit;
  std::vector < Link<int >> links(3);
  a.setLinkOut(&links[0]);
  b.setLinkOut(&links[1]);
  n.setLinkIn(&links[0]);
  n.setLinkIn(&links[1]);
  n.setLinkOut(&links[2]);
  exit.setLinkIn(&links[2]);
  a.setEntry(1);
  b.setEntry(2);
  n.calculateOutput();
  ASSERT_EQ(1, exit.getExit());
}

TEST(SimpleTest, StepActivationIntMinus22)
{
  Entry<int> a;
  Entry<int> b;
  Neuron<int, StepActivationFunction<int >> n(StepActivationFunction<int>(-2));
  Exit<int> exit;
  std::vector < Link<int >> links(3);
  a.setLinkOut(&links[0]);
  b.setLinkOut(&links[1]);
  n.setLinkIn(&links[0]);
  n.setLinkIn(&links[1]);
  n.setLinkOut(&links[2]);
  exit.setLinkIn(&links[2]);
  a.setEntry(1);
  b.setEntry(-2);
  n.calculateOutput();
  ASSERT_EQ(1, exit.getExit());
}

TEST(LearnWithDeltaTest, Or100)
{
  Entry<double> a;
  Entry<double> b;
  Neuron<double, StepActivationFunction<double >> n(StepActivationFunction<double>(3));
  Exit<double> exit;
  std::vector < Link<double >> links(3);
  a.setLinkOut(&links[0]);
  b.setLinkOut(&links[1]);
  n.setLinkIn(&links[0]);
  n.setLinkIn(&links[1]);
  n.setLinkOut(&links[2]);
  //n.printWages();
  exit.setLinkIn(&links[2]);
  for (int i = 0; i < 100; i++)
  {
    a.setEntry(0);
    b.setEntry(0);
    n.calculateOutput();
    n.learn(0);
    //n.printWages();
    //EXPECT_EQ(0, exit.getExit());
    a.setEntry(1);
    b.setEntry(0);
    n.calculateOutput();
    n.learn(1);
    //n.printWages();
    //EXPECT_EQ(1, exit.getExit());
    a.setEntry(0);
    b.setEntry(1);
    n.calculateOutput();
    n.learn(1);
    //n.printWages();
    //EXPECT_EQ(1, exit.getExit());
    a.setEntry(1);
    b.setEntry(1);
    n.calculateOutput();
    n.learn(1);
    //n.printWages();
  }
  //EXPECT_EQ(1, exit.getExit());
  a.setEntry(0);
  b.setEntry(0);
  n.calculateOutput();
  ASSERT_EQ(0, exit.getExit());
  a.setEntry(1);
  b.setEntry(0);
  n.calculateOutput();
  ASSERT_EQ(1, exit.getExit());
  a.setEntry(0);
  b.setEntry(1);
  n.calculateOutput();
  ASSERT_EQ(1, exit.getExit());
  a.setEntry(1);
  b.setEntry(1);
  n.calculateOutput();
  ASSERT_EQ(1, exit.getExit());
}

TEST(LearnWithDeltaTest, And100)
{
  Entry<double> a;
  Entry<double> b;
  Bias<double> bias(1);
  Neuron<double, StepActivationFunction<double >> n(StepActivationFunction<double>(5));
  Exit<double> exit;
  std::vector < Link<double >> links(4);
  a.setLinkOut(&links[0]);
  b.setLinkOut(&links[1]);
  bias.setLinkOut(&links[3]);
  n.setLinkIn(&links[3]);
  n.setLinkIn(&links[0]);
  n.setLinkIn(&links[1]);
  n.setLinkOut(&links[2]);
  bias.sendBiasToLinks();
  //n.printWages();
  exit.setLinkIn(&links[2]);
  for (int i = 0; i < 100; i++)
  {
    a.setEntry(0);
    b.setEntry(0);
    n.calculateOutput();
    n.learn(0);
    //n.printWages();
    //EXPECT_EQ(0, exit.getExit());
    a.setEntry(1);
    b.setEntry(0);
    n.calculateOutput();
    n.learn(0);
    //n.printWages();
    //EXPECT_EQ(0, exit.getExit());
    a.setEntry(0);
    b.setEntry(1);
    n.calculateOutput();
    n.learn(0);
    //n.printWages();
    //EXPECT_EQ(0, exit.getExit());
    a.setEntry(1);
    b.setEntry(1);
    n.calculateOutput();
    n.learn(1);
    //n.printWages();
  }
  //EXPECT_EQ(1, exit.getExit());
  a.setEntry(0);
  b.setEntry(0);
  n.calculateOutput();
  ASSERT_EQ(0, exit.getExit());
  a.setEntry(0);
  b.setEntry(1);
  n.calculateOutput();
  ASSERT_EQ(0, exit.getExit());
  a.setEntry(1);
  b.setEntry(0);
  n.calculateOutput();
  ASSERT_EQ(0, exit.getExit());
  a.setEntry(1);
  b.setEntry(1);
  n.calculateOutput();
  ASSERT_EQ(1, exit.getExit());
}

int main(int argc, char **argv)
{

  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();

}

