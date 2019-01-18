cmake_minimum_required(VERSION 3.12)
project(Huffman)

set(CMAKE_CXX_STANDARD 17)

add_executable(Huffman main.cpp MinHeap.h HuffmanTree.h)