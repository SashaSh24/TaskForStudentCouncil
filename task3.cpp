#include <iostream>
#include<map>
using namespace std;

string printRoman(int n) {

    string str_romans[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

    string result = "";

    for (int i = 0; i < 13; ++i)
    {
        while (n - values[i] >= 0)
        {
            result += str_romans[i];
            n -= values[i];
        }
    }

    return result;
}

int romanToDecimal(string& str)
{
    map<char, int> m;
    m.insert({ 'I', 1 });
    m.insert({ 'V', 5 });
    m.insert({ 'X', 10 });
    m.insert({ 'L', 50 });
    m.insert({ 'C', 100 });
    m.insert({ 'D', 500 });
    m.insert({ 'M', 1000 });
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        /*If present value is less than next value,
          subtract present from next value and add the
          resultant to the sum variable.*/
        if (m[str[i]] < m[str[i + 1]])
        {
            sum += m[str[i + 1]] - m[str[i]];
            i++;
            continue;
        }
        sum += m[str[i]];
    }
    return sum;
}


int main()
{
    string sum, firstNum, secondNum;
    cin >> sum;
    int i;
    for (i = 0; sum[i] != '+'; i++) {
        firstNum += sum[i];
    }
    i++;
    for (; i <= sum.length(); i++) {
        secondNum+= sum[i];
    }
    int x = romanToDecimal(firstNum), y = romanToDecimal(secondNum);
    int summ = x + y;
    cout<<endl << printRoman(summ);
    return 0;
}