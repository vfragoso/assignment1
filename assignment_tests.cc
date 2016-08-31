// Copyright (C) 2016  Victor Fragoso <victor.fragoso@mail.wvu.edu>
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above
//       copyright notice, this list of conditions and the following
//       disclaimer in the documentation and/or other materials provided
//       with the distribution.
//
//     * Neither the name of the West Virginia University nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL VICTOR FRAGOSO BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#include <unordered_set>
#include <vector>
#include "assignment.h"
#include "glog/logging.h"
#include "gtest/gtest.h"

// These are unit tests using google gtest library. A binary will be created
// automatically to run the tests below.
namespace wvu {
// Tests if the SumArray function was correctly implemented.
TEST(Assignment, SumArray) {
  int my_array[] = {1, 2, 3, 4};
  const int sum = SumArray(my_array, my_array + 4);
  EXPECT_EQ(0, sum);
}

TEST(Assignment, SumArrayWithInvalidPointers) {
  int my_array[] = {1, 2, 3, 4};
  const int sum = SumArray(my_array + 4, my_array);
  EXPECT_EQ(0, sum);
}

// Tests if the Sum function was correctly implemented.
TEST(Assignment, Sum) {
  const std::vector<int> my_vector = {1, 2, 3, 4};
  const int sum = Sum(my_vector);
  EXPECT_EQ(10, sum);
}

// Tests if the Sum function was correctly implemented.
TEST(Assignment, SumOfEmptyVector) {
  const std::vector<int> my_vector;
  const int sum = Sum(my_vector);
  EXPECT_EQ(0, sum);
}

// Tests if the Swap function was correctly implemented.
TEST(Assignment, Swap) {
  int variable_1 = 50;
  int variable_2 = 100;
  Swap(&variable_1, &variable_2);
  EXPECT_EQ(50, variable_2);
  EXPECT_EQ(100, variable_1);
}

// Tests if the reverse vector was correctly implemented.
TEST(Assignment, ReverseInPlace) {
  std::vector<int> my_vector = {1, 2, 3, 4};
  ReverseInPlace(&my_vector);
  for (int i = 4; i > 0; --i) {
    EXPECT_EQ(i, my_vector[i]);
  }
}

// Tests if the Exchange function was correctly implemented.
TEST(Assignment, Exchange) {
  std::vector<int> my_vector = {1, 2, 3, 4};
  int my_array[] = {5, 6, 7, 8, 9};
  const int size_of_array = sizeof(my_array) / sizeof(my_array[0]);
  int* my_array_ptr = my_array;
  Exchange(size_of_array, &my_array_ptr, &my_vector);
  for (int i = 1; i <= 4; ++i) {
    EXPECT_EQ(i, my_array_ptr[i]);
  }
  for (int i = 5; i <= 9; ++i) {
    EXPECT_EQ(i, my_vector[i]);
  }
}

// Tests if the IdentifyUniqueElements function was correctly implemented.
TEST(Assignment, IdentifyUniqueElements) {
  std::vector<int> my_vector = {1, 1, 1, 2, 3, 4, 4, 5, 5};
  std::unordered_set<int> unique_elements(my_vector.begin(), my_vector.end());
  IdentifyUniqueElements(&my_vector);
  EXPECT_EQ(unique_elements.size(), my_vector.size());
  for (int i = 0; i < my_vector.size(); ++i) {
    EXPECT_TRUE(unique_elements.find(my_vector[i]) != unique_elements.end());
  }
}

}  // namespace
