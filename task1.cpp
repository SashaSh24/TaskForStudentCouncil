#include <iostream>

int main(){
    int GivenNum, Digits = 10, Reverse = 0, num;
    std::cin >> GivenNum;
    num = GivenNum;
    do
     {
         Digits = num % 10;
         Reverse = (Reverse * 10) + Digits;
         num = num / 10;
     } while (num != 0);

   if(GivenNum == Reverse){return 1;}
   else{return 0;}

    return 0;
}

