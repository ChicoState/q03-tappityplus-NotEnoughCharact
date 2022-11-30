/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"

class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){}
		virtual ~tappityTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, check_data_is_received)
{
  tappity tap("abc");
  tap.entry("a");
  int length = tap.length_difference();
  if(length == 2)
  {
    ASSERT_TRUE(true);
  }
  else
  {
    ASSERT_TRUE(false);
  }
}

TEST(tappityTest, length_difference_works)
{
  tappity tap("abc");
  tap.entry("addddd");
  int length1 = tap.length_difference();
  tap.entry("add");
  int length2 = tap.length_difference();
  tap.entry("a");
  int length3 = tap.length_difference();
  if(length1 == 3 && length2 == 0 && length3 == 2)
  {
    ASSERT_TRUE(true);
  }
  else
  {
    ASSERT_TRUE(false);
  }
}

TEST(tappityTest, all_correct)
{
  tappity tap("abc");
  tap.entry("abc");
  double correctness = tap.accuracy();
  if(correctness == 100)
  {
    ASSERT_TRUE(true);
  }
  else
  {
    ASSERT_TRUE(false);
  }
}

TEST(tappityTest, all_wrong)
{
  tappity tap("abc");
  tap.entry("def");
  double correctness = tap.accuracy();
  if(correctness == 0)
  {
    ASSERT_TRUE(true);
  }
  else
  {
    ASSERT_TRUE(false);
  }
}

TEST(tappityTest, too_long_input_dec)
{
  tappity tap("abcd");
  tap.entry("abcdef");
  double correctness = tap.accuracy();
  if(correctness == (4.0/6.0)*100)
  {
    ASSERT_TRUE(true);
  }
  else
  {
    ASSERT_TRUE(false);
  }
}

TEST(tappityTest, too_long_input_whole)
{
  tappity tap("abc");
  tap.entry("abcdef");
  double correctness = tap.accuracy();
  if(correctness == 50)
  {
    ASSERT_TRUE(true);
  }
  else
  {
    ASSERT_TRUE(false);
  }
}

TEST(tappityTest, too_short_input_whole)
{
  tappity tap("abcdef");
  tap.entry("abc");
  double correctness = tap.accuracy();
  if(correctness == 50)
  {
    ASSERT_TRUE(true);
  }
  else
  {
    ASSERT_TRUE(false);
  }
}

TEST(tappityTest, too_short_input_dec)
{
  tappity tap("abcdef");
  tap.entry("abcd");
  double correctness = tap.accuracy();
  if(correctness == (4.0/6.0)*100)
  {
    ASSERT_TRUE(true);
  }
  else
  {
    ASSERT_TRUE(false);
  }
}

TEST(tappityTest, lots_of_letters_phrase)
{
  tappity tap("abcdefghijklmnopqrstuvwxyz");
  tap.entry("abcde");
  double correctness = tap.accuracy();
  if(correctness == (5.0/26.0)*100)
  {
    ASSERT_TRUE(true);
  }
  else
  {
    ASSERT_TRUE(false);
  }
}

TEST(tappityTest, lots_of_letters_input)
{
  tappity tap("abcde");
  tap.entry("abcdefghijklmnopqrstuvwxyz");
  double correctness = tap.accuracy();
  if(correctness == (5.0/26.0)*100)
  {
    ASSERT_TRUE(true);
  }
  else
  {
    ASSERT_TRUE(false);
  }
}
