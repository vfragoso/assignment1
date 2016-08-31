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

#include <vector>
#include <iostream>
#include "assignment.h"
#include "glog/logging.h"

namespace wvu {
int SumArray(int* start, int* end) {
  if (start > end) return 0;
  int sum = 0;
  for (int* ptr = start; ptr != end; ++ptr) {
    sum += *ptr;
  }
  return sum;
}

int Sum(const std::vector<int>& vector) {
  int sum = 0;
  for (int i = 0; i < vector.size(); ++i) {
    sum += vector[i];
  }
  return sum;
}

void Swap(int* number_1, int* number_2) {
  if (number_1 && number_2) {
    int temp = *number_1;
    *number_1 = *number_2;
    *number_2 = temp;
  }
}

void ReverseInPlace(std::vector<int>* vector) {
  int start = 0;
  int end = vector->size() - 1;
  while (start < end) {
    Swap(&vector->at(start), &vector->at(end));
    ++start;
    --end;
  }
}

void Exchange(const int array_size,
              int** array,
              std::vector<int>* vector) {
  // Implement this function according to the instructions in assignment.h.
}

void IdentifyUniqueElements(std::vector<int>* vector) {
  // Implement this function according to the instructions in assignment.h.
}

}  // namespace wvu
