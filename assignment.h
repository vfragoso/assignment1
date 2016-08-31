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

#ifndef ASSIGNMENT_1_H_
#define ASSIGNMENT_1_H_

#include <vector>

// Assignment 1. Implement the functions declared below in assignment.cc. The
// goal of the assignment is to test the topics we covered as part of the
// C++ crash course.
//
// Send your solution as a single file and with the following format:
//
// assignment1_<firstname>_<lastname>.zip,
//
// where <first> is replaced with your firstname and <lastname> with your
// lastname. For example, in my case it would be:
//
// assignment1_victor_fragoso.zip.
//
// The zip file should include *only* source code of the project, don't include
// any binaries.
//
// Compilation. Use the instructions we saw in class to compile this project.
//
// Verification of solution. To verify your implementations, the project
// generates a binary called assignment under the created bin directory. When
// the implementations are correct all the tests run by the binary will be
// marked as OK.
namespace wvu {
// Sums all the elements in the array. For example:
// SumArray(array={1, 2 ,3, 4}) -> 10.
// Your job is to implement this function in assignment.cc
// The function should return 0 when the array is empty.
// The function should return 0 when invalid pointers are passed; invalid
// pointers means that the address of start is greater than end.
int SumArray(int* start, int* end);

// Sums all the elements in the vector. For example:
// Sum(vector={1, 2 ,3, 4}) -> 10.
// Your job is to implement this function in assignment.cc
// The function should return 0 when the vector is empty.
int Sum(const std::vector<int>& vector);

// Swaps the values of two integers.
// Your job is to implement this function in assignment.cc.
void Swap(int* number_1, int* number_2);

// Reverses the elements in the vector. For instance, assume the vector has
// v = {1, 2, 3, 4, 5}. After reversal, the vector should look like
// v = {5, 4, 3, 2, 1}.
// Your job is to implement this function in assignment.cc uisng the Swap
// function only.
void ReverseInPlace(std::vector<int>* vector);

// Exchanges information from vector to an array. For example:
// vector = {1, 2, 3, 4, 5}
// array = {6, 7, 8, 9, 0}
// Exchange(vector, array) vector -> {6, 7, 8, 9, 0}, array - {1, 2, 3, 4, 5}.
// Hint: For vector you can use a method called resize().
// See link: http://en.cppreference.com/w/cpp/container/vector/resize
// Your job is to implement this function in assignment.cc.
void Exchange(const int array_size,
              int** array,
              std::vector<int>* vector);

// Identify unique elements in a vector using map, and return the unique
// elements in the same vector. For example: vector = {1, 1, 1, 1, 2}
// vector = {1, 2} <- IdentifyUniqueElements(vector).
// Hint: For vector you can use a method called resize().
void IdentifyUniqueElements(std::vector<int>* vector);

}  // namespace

#endif  // ASSIGNMENT_1_H_
