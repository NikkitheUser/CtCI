/ Next Number: Given a positive integer, print the next smallest and the previous largest number that
// FIGURE BETTER WAY TO GET BITS

#include <tuple>
#include <iostream>

using namespace std;
template <typename T>
tuple<T, T> nextBiggerSmaller(T v)
{
    static_assert(is_unsigned<T>::value, "T must be unsigned integral type");

    auto result = make_tuple(0U, 0U);
    T rightZeros = 0; // tail zero count
    T rightOnes = 0;  // count of tightmost ones between zeros
    T zeroPos = 0;    // first/rightmost zero of 01 bits
    T tmp = v;

    while (tmp != 0 && !(tmp & 1))
    {
        ++rightZeros;
        tmp >>= 1;
    }
    while (tmp != 0 && (tmp & 1))
    {
        ++rightOnes;
        tmp >>= 1;
    }
    zeroPos = rightZeros + rightOnes;
    if (0 < zeroPos && zeroPos < v)
    {
        tmp = v | (1 << zeroPos);     // rightmost non-trailing zero to 1
        // at this point we have one more bit 1
        tmp &= ~((1 << zeroPos) - 1); // reset all bits right from previously set
        tmp |= (1 << (rightOnes - 1)) - 1; // set rightOnes - 1 rightmost bits to 1
        get<1>(result) = tmp;
    }

    rightOnes = rightZeros = 0;
    tmp = v;

    while (tmp != 0 && (tmp & 1))
    {
        ++rightOnes;
        tmp >>= 1;
    }
    while (tmp != 0 && !(tmp & 1))
    {
        ++rightZeros;
        tmp >>= 1;
    }
    T onePos = rightZeros + rightOnes; // first/rightmost one of 10 bits
    if (0 < onePos && onePos < v)
    {
        tmp = v & ~(1 << onePos);  // rightmost non-trailing 1 to zero
        // at this point we have one bit 1 less
        tmp |= (1 << onePos) - 1;  // set all bits right from previously reset to 0
        tmp &= ~((1 << (rightZeros - 1)) - 1); // reset rightZeros - 1 rightmost bits to 0
        get<0>(result) = tmp;
    }

    return result;
}

int main()
{
    for (uint16_t v : {
              0b11011101111U
            , 0U
            , 0b1111111111111111U
            , 0b0111111111111111U
            , 0b1111111111111110U})
    {
        auto minMax = nextBiggerSmaller(v);
        auto nextMin = get<1>(minMax);
        auto prevMax = get<0>(minMax);
        cout << v << " (" << v << "b " << v << " bits)\nNext min: ";
        if (nextMin > 0)
            cout << nextMin << " (" << nextMin << "b " << nextMin << " bits)";
        else
            cout << "Not existing";
        cout << "\nPrev max: ";
        if (prevMax > 0)
            cout << prevMax << " (" <<prevMax << "b " << prevMax << " bits)";
        else
            cout << "Not existing";
        cout << endl << endl;
    }

    uint8_t v = 1; // rightmost
    do
    {
        cout << v << '\n';
        v = get<1>(nextBiggerSmaller(v));
    }
    while (v != 0);
    cout << endl;
    v = 1 << (v - 1);
    do
    {
        cout << v <<  '\n';
        v = get<0>(nextBiggerSmaller(v));
    }
    while (v != 0);
}
