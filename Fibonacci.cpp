#include<iostream>
int main(){
    int n;
    std::cin>>n;
    long long pr =0;
    long long nx =1;
    if(n==0){
        std::cout<<0;
    }
    else{
        for(int i=0;i<n-1;++i){
            long long f;
            f = pr+nx;
            pr = nx;
            nx=f;
    }   
    std::cout<<nx<<std::endl;
    }
}
