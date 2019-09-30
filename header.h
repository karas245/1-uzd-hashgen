
#ifndef INC_1_UZD_HASHGEN_HEADER_H
#define INC_1_UZD_HASHGEN_HEADER_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

void read(std::string &data);
void write(std::string &data);
void toASCII(std::string &data, std::vector<int> &numb);
void gen(std::string &data);
void to64(std::string &data );

#endif //INC_1_UZD_HASHGEN_HEADER_H