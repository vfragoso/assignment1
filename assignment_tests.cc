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

// C headers.
#include <stdlib.h>  // For random.

// C++ headers.
#include <algorithm>  // For std::accumulate.
#include <unordered_set>
#include <vector>

// System specific headers.
#include "assignment.h"
#include "glog/logging.h"
#include "gtest/gtest.h"

// These are unit tests using google gtest library. A binary will be created
// automatically to run the tests below.
namespace wvu {
// Tests if the SumArray function was correctly implemented.
TEST(Assignment, SumArray) {
  const int kNumPoints = 50;
  std::vector<int> my_vector(kNumPoints);
  for (int i = 0; i < kNumPoints; ++i) {
    my_vector[i] = rand();
  }
  const int sum = SumArray(my_vector.data(), my_vector.data() + kNumPoints);
  EXPECT_EQ(std::accumulate(my_vector.begin(), my_vector.end(), 0), sum);
}

// Tests for the sum of an array with a single element.
TEST(Assignment, SumArraySingleElement) {
  int my_array[] = {1};
  const int sum = SumArray(my_array, my_array);
  EXPECT_EQ(my_array[0], sum);
}

// Tests for the sum of an array with null pointers.
TEST(Assignment, SumArrayWithNullPointers) {
  const int sum = SumArray(nullptr, nullptr);
  EXPECT_EQ(0, sum);
}

// Tests for the sum of an array with wrong order of the pointers.
TEST(Assignment, SumArrayWithInvalidPointers) {
  int my_array[] = {1, 2, 3, 4};
  const int sum = SumArray(my_array + 4, my_array);
  EXPECT_EQ(0, sum);
}

// Tests if the Sum function was correctly implemented.
TEST(Assignment, Sum) {
  const int kNumPoints = 50;
  std::vector<int> my_vector(kNumPoints);
  const int sum = Sum(my_vector);
  EXPECT_EQ(std::accumulate(my_vector.begin(), my_vector.end(), 0), sum);
}

// Tests if the Sum function was correctly implemented.
TEST(Assignment, SumOfEmptyVector) {
  const std::vector<int> my_vector;
  const int sum = Sum(my_vector);
  EXPECT_EQ(0, sum);
}

// Tests if the Swap function was correctly implemented.
TEST(Assignment, Swap) {
  int variable_1 = rand();
  int variable_2 = variable_1 + rand();
  const int variable_1_output = variable_2;
  const int variable_2_output = variable_1;
  Swap(&variable_1, &variable_2);
  EXPECT_EQ(variable_2_output, variable_2);
  EXPECT_EQ(variable_1_output, variable_1);
}

// Tests if the Swap function was correctly implemented.
TEST(Assignment, SwapWithNullPointers) {
  Swap(nullptr, nullptr);
}

// Tests if the reverse vector was correctly implemented.
TEST(Assignment, ReverseInPlace) {
  const int kNumPoints = 50;
  std::vector<int> my_vector(kNumPoints);
  for (int i = 0; i < kNumPoints; ++i) {
    my_vector[i] = rand();
  }
  std::vector<int> reversed_vector = my_vector;
  ReverseInPlace(&my_vector);
  std::reverse(reversed_vector.begin(), reversed_vector.end());
  for (int i = 0; i < my_vector.size(); ++i) {
    EXPECT_EQ(reversed_vector[i], my_vector[i]);
  }
}

// Test if the reverse vector was correctly implemented with a single element.
TEST(Assignment, ReverseInPlaceWithSingleElement) {
  const int kNumPoints = 1;
  std::vector<int> my_vector(kNumPoints);
  for (int i = 0; i < kNumPoints; ++i) {
    my_vector[i] = rand();
  }
  std::vector<int> reversed_vector = my_vector;
  ReverseInPlace(&my_vector);
  std::reverse(reversed_vector.begin(), reversed_vector.end());
  for (int i = 0; i < my_vector.size(); ++i) {
    EXPECT_EQ(reversed_vector[i], my_vector[i]);
  }
}

// Test if the reverse vector was correctly implemented with a null pointer.
TEST(Assignment, ReverseInPlaceWithNullPointer) {
  ReverseInPlace(nullptr);
}

// Tests if the Exchange function was correctly implemented.
TEST(Assignment, Exchange) {
  constexpr int kNumPointsVector = 50;
  constexpr int kNumPointsArray = 25;
  std::vector<int> my_vector(kNumPointsVector);
  int my_array[kNumPointsArray];

  // Initialize vector and array.
  for (int i = 0; i < my_vector.size(); ++i) {
    my_vector[i] = rand();
  }
  for (int i = 0; i < kNumPointsArray; ++i) {
    my_array[i] = rand();
  }
  // Create the correct answer using vectors.
  const std::vector<int> my_array_output = my_vector;
  const std::vector<int> my_vector_output(my_array, my_array + kNumPointsArray);

  const int size_of_array = sizeof(my_array) / sizeof(my_array[0]);
  int* my_array_ptr = my_array;
  Exchange(size_of_array, &my_array_ptr, &my_vector);
  for (int i = 0; i < my_array_output.size(); ++i) {
    EXPECT_EQ(my_array_output[i], my_array_ptr[i]);
  }
  for (int i = 0; i < my_vector_output.size(); ++i) {
    EXPECT_EQ(my_vector_output[i], my_vector[i]);
  }
}

// Tests if the Exchange function was correctly implemented.
TEST(Assignment, ExchangeWithNullPointers) {
  Exchange(0, nullptr, nullptr);
}

// Tests if the Exchange function was correctly implemented.
TEST(Assignment, ExchangeWithEmptyArray) {
  constexpr int kNumPointsVector = 50;
  constexpr int kNumPointsArray = 0;
  std::vector<int> my_vector(kNumPointsVector);
  int my_array[kNumPointsArray];

  // Initialize vector and array.
  for (int i = 0; i < my_vector.size(); ++i) {
    my_vector[i] = rand();
  }
  for (int i = 0; i < kNumPointsArray; ++i) {
    my_array[i] = rand();
  }
  // Create the correct answer using vectors.
  const std::vector<int> my_array_output = my_vector;
  const std::vector<int> my_vector_output(my_array, my_array + kNumPointsArray);

  const int size_of_array = sizeof(my_array) / sizeof(my_array[0]);
  int* my_array_ptr = my_array;
  Exchange(size_of_array, &my_array_ptr, &my_vector);
  for (int i = 0; i < my_array_output.size(); ++i) {
    EXPECT_EQ(my_array_output[i], my_array_ptr[i]);
  }
  for (int i = 0; i < my_vector_output.size(); ++i) {
    EXPECT_EQ(my_vector_output[i], my_vector[i]);
  }
}

// Tests if the IdentifyUniqueElements function was correctly implemented.
TEST(Assignment, IdentifyUniqueElements) {
  constexpr int kNumPointsVector = 50;
  std::vector<int> my_vector(kNumPointsVector);
  // Initialize vector and array.
  // The % is the modulo/remainder operator.
  for (int i = 0; i < my_vector.size(); ++i) {
    my_vector[i] = rand() % 10;
  }
  // Unordered set or set
  std::unordered_set<int> unique_elements(my_vector.begin(), my_vector.end());
  IdentifyUniqueElements(&my_vector);
  EXPECT_EQ(unique_elements.size(), my_vector.size());
  for (int i = 0; i < my_vector.size(); ++i) {
    EXPECT_TRUE(unique_elements.find(my_vector[i]) != unique_elements.end());
  }
}

// Tests if the IdentifyUniqueElements function was correctly implemented.
TEST(Assignment, IdentifyUniqueElementsWithNullPointer) {
  IdentifyUniqueElements(nullptr);
}

}  // namespace
