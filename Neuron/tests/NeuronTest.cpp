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

#include <vector>

/**
 * SQLiteController
 */
TEST(SimpleTest, C2Entry1Neuron1Exit0Int)
{
  Entry<int> a;
  Entry<int> b;
  Neuron<int> n;
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
  std::cout << "A\n";
  n.calculateOutput();
  std::cout << "A\n";
  ASSERT_EQ(0, exit.getExit());
  std::cout << "A\n";
}

TEST(SimpleTest, C2Entry1Neuron1Exit3Int)
{
  std::cout << "A\n";
  Entry<int> a;
  Entry<int> b;
  Neuron<int> n;
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
  ASSERT_EQ(3, exit.getExit());
}

TEST(SimpleTest, C2Entry1Neuron1ExitMinus1Int)
{
  std::cout << "A\n";
  Entry<int> a;
  Entry<int> b;
  Neuron<int> n;
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
  ASSERT_EQ(-1, exit.getExit());
}


int main(int argc, char **argv)
{

  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();

}

