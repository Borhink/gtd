#include <string>

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

std::string transformWord(std::string& in)
{
    std::string out = "";
 
    if (in.empty())
        return out;

    out += in[0];
    if (in.size() > 2)
        out += std::to_string(in.size() - 2);
    out += in[in.size() - 1];
    return out;
}

int main()
{
    srand(time(NULL));

    //Char holder
    std::string alnum = "abcdefghijklmnopqrstuvwxyzABCDEFHGIJKLMNOPQRSTUVWXYZ123456789";
    //Test strings
    std::vector<std::string> tests = {
        "",             //Empty str
        "a",            //One char
        "aa",           //Two sames char
        "ab",           //Two different char
        "abcdefg",      //Full str
        "arbre",        //Reference tests
        "parachute",    //Reference tests
        "la",           //Reference tests
    };

    //Some random tests
    for (int i = 0; i < 20; i++)
    {
        int size = rand() % 50 + 5;
        std::string str = "";

        for (int j = 0; j < size; j++)
            str += alnum[rand() % alnum.size()];
        
        tests.push_back(str);
    }

    for (int i = 0; i < tests.size(); i++)
        std::cout << "Apply transform on '" << tests[i] << "' -> '" << transformWord(tests[i]) << "'" << std::endl;
}

/*
** Pour les test, il faut essayer avec :
**  -les différents cas particuliers
**  -les cas de référence
**  -des cas un peu plus aléatoires
*/