// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful

template<class TYPE>
void swap(TYPE& a, TYPE& b) {
    TYPE tmp = a;
    a = b;
    b = tmp;
}

template<class IT>
void my_selection_sort(IT begin, IT end)
{
    for (IT i = begin; i != end; ++i)
    {
        IT min = i;
        IT max = i; 
        for (IT j = ++max; j != end; ++j)
        {
            if (*j < *min)
                min = j;
        }
        swap(*min, *i);
    }
}