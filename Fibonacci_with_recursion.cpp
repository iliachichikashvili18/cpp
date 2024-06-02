#include<iostream>
void Fibonacci_calculator(int n,int before_previous,int previous,int holder){

    if(n==1){
        std::cout<<before_previous;
    }
    else{
        holder = previous;
        previous+=before_previous;
        before_previous=holder;
        Fibonacci_calculator(n-1,before_previous,previous,holder);
    }
}
void Fibonacci(int n){
    return Fibonacci_calculator(n,0,1,0);
}
int main(){
    Fibonacci(3);
}
