
#ifndef INC_1_UZD_HASHGEN_HEADER_H
#define INC_1_UZD_HASHGEN_HEADER_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <numeric>
#include <chrono>
#include <cstdlib>
#include <bitset>

void read(std::string &data);
void write(std::string &data);
void toASCII(std::string &data, std::vector<int> &numb);
int allsum(std::string &data);
void gen(std::string &data);
void to64(std::string &data );
void generate();
void test4();
std::string TextToBinaryString(std::string hash);
void bitTest(std::vector<std::string> numb);

#endif //INC_1_UZD_HASHGEN_HEADER_H
