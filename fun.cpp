#include "header.h"

void read(std::string &data)
{
    std::ifstream fd("duomenys.txt");
    std::ofstream fr("rezultatai.txt", std::ios::trunc);
    fr.close();
    while(!fd.eof())
    {
        std::getline(fd, data);
        gen(data);
        //if( !fd.eof() ) break;

    }
    fd.close();
}
void write(std::string &data)
{
    std::ofstream fr("rezultatai.txt", std::ios::app);
    fr << data << std::endl;
    fr.close();
}
void toASCII(std::string &data, std::vector<int> &numb)
{
    for(int i=0;i<data.length();i++)
    {
        if(isdigit(data[i]))
        {
            numb.push_back(data[i]);
        }
        else
        {
            int t=data[i];
            numb.push_back(t);
        }

    }
}
int allsum(std::string &data)
{
    std::vector<int> vec;
    for(int i=0;i<data.length();i++)
    {
        if(isdigit(data[i]))
        {
            vec.push_back(data[i]);
        }
        else
        {
            int t=data[i];
            vec.push_back(t);
        }
    }
    return (accumulate(vec.begin(),vec.end(),0)%10);
}
void gen(std::string &data)
{
    int sum=allsum(data);
    std::vector<int> numb;
    to64(data);
    toASCII(data,numb);

    if(sum==0)
        sum=3;

    for(auto &v:numb)
    {
        v=v*sum;
        v=(v*v*v)%100;

    }

    for(int i=0;i<numb.size();i++)
    {
        numb[i]+=i;
        if(numb[i]>=65 && numb[i]<=90)
        {
            char tem1=numb[i];
            data[i]=tem1;
        }
        else if(numb[i]>=97 && numb[i]<=122)
        {
            char tem1=numb[i];
            data[i]=tem1;
        }
        else if(numb[i]>=48 && numb[i]<=57)
        {
            int temp2=numb[i];
            data[i]=temp2;
        }
        else
        {
            std::stringstream ss;
            if(numb[i]<0)
                numb[i]*=-1;
            ss << numb[i];
            std::string str = ss.str();
            char ch=str[0];
            data[i]=ch;

        }


    }
    write(data);
    numb.clear();
}
void to64(std::string &data)
{

    int len= data.length();

    std::string temp;
    for(int i=len;i>len/2;i--)
    {
        temp.push_back(data[i]);
    }

    int j=0;
    for(int i=0;i<len;i=i+2)
    {
        std::string temporary;
        temporary.push_back(temp[j]);
        data.insert(i,temporary);
        j++;
    }


    if(len<64)
    {
        int i=1;
        while (data.length() < 64)
        {
            if(i==10)
                i=0;
            data += std::to_string( i);
            i++;
        }

    }

    data.resize(64);



}