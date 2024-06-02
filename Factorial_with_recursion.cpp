#include<iostream>
int Factorial_calculator(int n,int final_answer){
    if(n==1){//we are stopping when n=1 because any number * 1 is the same number so we would waste 1 more function call if we stopped when n was = to 0
        return final_answer;
    }
    else{
        return Factorial_calculator(n-1,final_answer*n);
    }
}
int Factorial(int k){
    return Factorial_calculator(k,1);
}
int main(){
    std::cout<<Factorial(5);
}
