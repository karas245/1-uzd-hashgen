#include "header.h"


int main(int argc, char *argv[]) {

    std::string data;

    if(argc>1)
    {
        for(int i=1;i<argc;i++)
        {
            data+=argv[i];
        }
        gen(data);
    }
    else
        read(data);
    

    return 0;
}