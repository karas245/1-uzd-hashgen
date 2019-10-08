#include "header.h"

void read(std::string &data)
{
    //std::ifstream fd("duomenys.txt");
    std::ifstream fd("konstitucija.txt");
    //std::ofstream fr("rezultatai.txt", std::ios::trunc);
    std::ofstream fr("rezkonstitucijos.txt", std::ios::trunc);
    fr.close();
    double took=0;

    while(!fd.eof())
    {
        std::getline(fd, data);
        auto start = std::chrono::system_clock::now();

        gen(data);

        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        took+= elapsed_seconds.count() ;
        auto diff = end - start ;

        //if( !fd.eof() ) break;

    }
    std::cout << "Hash Generator took " << took << " s" << std::endl;
    fd.close();
}
void write(std::string &data)
{
    //std::ofstream fr("rezultatai.txt", std::ios::app);
    std::ofstream fr("rezkonstitucijos.txt", std::ios::app);

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
    return ((accumulate(vec.begin(),vec.end(),0)%10000)*vec.size());
}
void gen(std::string &data)
{

    int sum=allsum(data);
    std::vector<int> numb;
    std::string original=data;
    std::vector<int> vorigin;
    to64(data);
    toASCII(data,numb);
    toASCII(original,vorigin);
    if(sum==0)
        sum=3;




    int j=0;
    for(auto &v:numb)
    {

        v=v*(sum*11);
        v=v*vorigin[j];

        j++;
        if(j==vorigin.size())
            j=0;

    }

    j=0;
    for(int i=63;i>=0;i--)
    {
        int magic1=vorigin[j]*vorigin[j] +3;
        int magic2=vorigin[j]*11+2;
        int magic3=vorigin[j]*(i+3)+magic2;

        numb[i]=numb[i]*vorigin[j];
        j++;

        numb[i]=(magic1*magic2*magic3)%100;

        if(j==vorigin.size())
        {
            j=0;

        }
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


    //write(data);
    vorigin.clear();
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

void generate()
{
    int num=0;
    std::ofstream fr("testfile4.txt");
    for(char i='a';i<='v';i++)
    {
        for(char j=i+1;j<='w';j++)
        {
            for(char k=j+1;k<='x';k++)
            {
                for(char l=k+1;l<='y';l++)
                {
                    for(char p=l+1;p<='z';p++)
                    {
                        if(i==j && j==k && k==l && l==p)
                            p++;
                        fr << i << j << k << l << p << std::endl;
                        num++;
                    }

                }
                if(num>1000000)
                    break;
            }
            if(num>1000000)
                break;
        }
        if(num>1000000)
            break;
    }
    for(char i='z';i>='e';i--)
    {
        for(char j=i-1;j>='d';j--)
        {
            for(char k=j-1;k>='c';k--)
            {
                for(char l=k-1;l>='b';l--)
                {
                    for(char p=l-1;p>='a';p--)
                    {
                        if(i==j && j==k && k==l && l==p)
                            p++;
                        fr << i << j << k << l << p << std::endl;
                        num++;
                    }

                }
                if(num>1000000)
                    break;
            }
            if(num>1000000)
                break;
        }
        if(num>1000000)
            break;
    }

    fr.close();

}
void test4()
{
    std::ifstream fd("testfile.txt");
    //std::ifstream fd("duomenys.txt");
    std::string data4test;
    std::vector<std::string> vec;
    int i=0;
    while(!fd.eof())
    {
        std::getline(fd, data4test);

        gen(data4test);
        vec.push_back(data4test);
        i++;
       // if(i==10)
           // break;

        //if( !fd.eof() ) break;

    }
    //std::cout << "NUMBER" << std::endl;
    /*if(std::equal(vec.begin(), vec.end(), vec.begin()))
    {
        std::cout << " HASH IS THE SAME AS OTHER  "  << std::endl;
        //std::cout <<  vec[i] << std::endl;
        //std::cout <<  vec[j] << std::endl;

        std::exit(EXIT_FAILURE);
    }
    std::cout << "DONE IF " << std::endl;*/

    int number=0;

    for(int i=0;i<vec.size()-1;i++)
    {
        for(int j=i+1;j<vec.size();j++)
        {

            if(vec[i]==vec[j])
            {
                //std::cout << " HASH IS THE SAME AS OTHER " << i << " : " << j << std::endl;
                //std::cout <<  vec[i] << std::endl;
                //std::cout <<  vec[j] << std::endl;
                //std::cout << number << std::endl;
                //std::exit(EXIT_FAILURE);
                number++;
            }

        }
    }
    //std::cout << number << std::endl;
    bitTest(vec);
}
std::string TextToBinaryString(std::string hash) {
    std::string binaryString = "";
    for (char& _char : hash) {
        binaryString +=std::bitset<8>(_char).to_string();
    }
    return binaryString;
}
void bitTest(std::vector<std::string> numb)
{
    std::vector<std::string> binary;
    std::vector<double> mismatch;
    if(numb.size()%2!=0)
    {
        numb.resize(numb.size()-1);
    }

    for (int i = 0; i < numb.size(); i=i+2)
    {
        double temp = 0;
        std::string binary1= TextToBinaryString(numb[i]);
        std::string binary2= TextToBinaryString(numb[i+1]);

        for(int j=0;j<binary1.size();j++)
        {


            if (binary1[j] != binary2[j]) {
                temp++;



            }

        }

        mismatch.push_back(temp/numb[i].length());


    }
    double min, max, avg;
    min=*std::min_element(mismatch.begin(), mismatch.end());
    max=*std::max_element(mismatch.begin(), mismatch.end());
    avg=(std::accumulate(mismatch.begin(), mismatch.end(), 0.0))/mismatch.size();
    std::cout << min *100<< std::endl;
    std::cout << max *100<< std::endl;
    std::cout << avg *100<< std::endl;

}