
#include <iostream>
#include <fstream>

#include <list>
#include <vector>
#include <deque>

#include "my_sort.hpp"

// Change here
// All occurences of TYPE need to be replaced with
// something more meaningfule

template<class TYPE, class CONTAINER>
void read_file_to_cont(std::ifstream& f, CONTAINER& c) 
{
    TYPE elm;
    while (f >> elm)
        c.push_back(elm);
}

template<class CONTAINER>
void read_file_to_cont_char(std::ifstream&f, CONTAINER& c)
{
    char elm;
    while ((elm = f.get()) != EOF)
    {
        c.push_back(elm);
        f.get();
    }
}

template<class TYPE, class CONTAINER>
void read_and_sort(std::ifstream& fi, std::ofstream& fo) {
    CONTAINER container;

    if constexpr (std::is_same_v<TYPE, char>)
    {
        read_file_to_cont_char<CONTAINER>(fi, container);
        my_selection_sort(container.begin(), container.end(), [](char a, char b)->bool{return a < b;});
    }
    else
    {
        read_file_to_cont<TYPE, CONTAINER>(fi, container);
        if constexpr (std::is_same_v<TYPE, int> || std::is_same_v<TYPE, unsigned> || std::is_same_v<TYPE, bool>)
            my_selection_sort_integral(container.begin(), container.end(), [](char a, char b)->bool{return a < b;});
        else
            my_selection_sort_descending(container.begin(), container.end());            
    }
    // if constexpr (std::is_same_v<TYPE, int> || std::is_same_v<TYPE, unsigned> || std::is_same_v<TYPE, char> || std::is_same_v<TYPE, bool>)
        // my_selection_sort<INTEGRAL>(container.begin(), container.end());
    // else
    my_selection_sort(container.begin(), container.end());

    for (TYPE& elm : container)
        fo << elm << std::endl;
}

template<class TYPE>
void read_and_sort_decide_container(std::ifstream& fi, std::ofstream& fo) 
{
    char line;
    fi >> line;
    fo << line << std::endl;

    switch(line)
    {
        case 'l':
            read_and_sort<TYPE, std::list<TYPE>>(fi, fo);
            break;
        case 'v':
            read_and_sort<TYPE, std::vector<TYPE>>(fi, fo);
            break;
        case 'd':
            read_and_sort<TYPE, std::deque<TYPE>>(fi, fo);
            break;
        default:
            std::runtime_error("Can only handle list, vector and deque");
            break;
    }
}


void read_and_sort_decide_valuetype(std::ifstream& fi, std::ofstream& fo)
{
    char line;
    fi >> line;
    fo << line << std::endl;

    switch(line)
    {
        case 'i':
            read_and_sort_decide_container<int>(fi, fo);
            break;
        case 'u':
            read_and_sort_decide_container<unsigned>(fi, fo);
            break;
        case 'f':
            read_and_sort_decide_container<float>(fi, fo);
            break;
        case 'd':
            read_and_sort_decide_container<double>(fi, fo);
            break;
        case 'c':
            read_and_sort_decide_container<char>(fi, fo);
            break;
        case 's':
            read_and_sort_decide_container<std::string>(fi, fo);
            break;
        default:
            std::runtime_error("Can only handle int, unsigned, float, double, char, string");
            break;
    }
}



