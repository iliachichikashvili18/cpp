#include<iostream>
int Power(int num,int power){
    int x=1;
    for(int i = 0;i<power;++i){
        x*=num;
    }
    return x;
}
int String_to_int(std::string string_number){
    int number=0;
    for(int i=0;i<string_number.length();++i){
        int num = int(char(string_number[i]))-48;
        if(num>=0&&num<=9){
            number+=(num)*Power(10,string_number.length()-i-1);
        }
        else{
            return 0;
        }
    }
    return number;
}
int main(){
   std::cout<<String_to_int("202324234");
}