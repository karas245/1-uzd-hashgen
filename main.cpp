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
        std::cout<< data << std::endl;
        //printf("%s\n", argv[1]);
    }
    else
        read(data);

    //generate();
    //test4();
    std::cout << "program succes" << std::endl;




    return 0;
}