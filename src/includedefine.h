/* includedefine.h Shared includes and declarations for IRFinder/NxtIRF

Copyright (C) 2021 Alex Chit Hei Wong
Copyright (C) 2016 William Ritchie
  - original: https://github.com/williamritchie/IRFinder/tree/IRFinder-1.3.1)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.  */

#ifndef INCLUDEDEFINE_DEF
#define INCLUDEDEFINE_DEF

#include <cstring>    // memcpy, strncmp, size_t
#include <fstream>    // i/o
#include <sstream>    // stringstream
#include <limits>
#include <sys/types.h>  // size_t, other type definitions
#include <vector>     // std::vector
#include <map>        // std::map
#include <algorithm>  // std::sort std::min std::max
#include <functional> // std::function

#include <math.h>

#ifdef GALAXY
#include <iostream>   // for cout
#define Rcout cout
#define Rcpp::Rcout cout
#endif

using namespace std;



#ifdef _OPENMP
#include <omp.h>
#endif

// Tell Linux not to cache the large files:
//__asm__(".symver memcpy,memcpy@GLIBC_2.2.5");

#define DEF_lineLengthMax 10000
#define DEF_adaptLengthMax 500

// A class storing the refID, chrom name and length
class chr_entry {
  public:
    unsigned int refID;
    std::string chr_name;
    int32_t chr_len;
    
    chr_entry(unsigned int a, std::string b, int32_t c) {
      refID = a;
      chr_name = b;
      chr_len = c;
    };
};

// Sort a vector of chr_entry by chr_name in alphabetical order
inline bool operator< (const chr_entry& lhs, const chr_entry& rhs){
  return lhs.chr_name < rhs.chr_name;
}

#endif