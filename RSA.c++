#include<bits/stdc++.h>
using namespace std;

long int p,q,n,t,flag, e[100],d[100],temp[100],m[100],en[100],j,i;
char msg[100];
int prime(long int);
void ce();
long int cd(long int);
void encrypt();
void decrypt();

int prime(long int pr){
    int i;
    j=sqrt(pr);
    for(i=2;i<=j;i++){
        if(pr%i==0){
            return 0;
        }
        return 1;
    }
}

int main(){
    cout<<"enter a prime number(large value) "<<endl;
    cin>>p;

    flag=prime(p);
    if(flag==0){
        cout<<"Wrong input provided"<<endl;
        exit(1);
    }

    cout<<"Enter Another prime number(large value) "<<endl;
    cin>>q;
    flag=prime(q);
    if(flag==0 || p==q){
        cout<<"Wrong input reason prime1==prime2 or prime2=0"<<endl;
        exit(1);
    }
    cout<<"Enter message"<<endl;
    fflush(stdin);
    cin>>msg;
    for(i=0;msg[i]!='\0';i++){
        m[i]=msg[i];
    }
    n=p*q;
    t=(p-1)*(q-1);
    ce();

    cout<<"Possible value of e and d are \n";
    for(i=0;i<j-1;i++){
        cout<<e[i]<<"\t"<<d[i]<<"\n";
    }
    encrypt();
    decrypt();

    return 0;
}

void ce(){
    int k=0;
    for(i=2;i<t;i++){
        if(t%i==0){
            continue;
        }
        flag=prime(i);
        if(flag==1 && i!=p &&i!=q){
            e[k]=i;
            flag=cd(e[k]);
            if(flag>0){
                d[k]=flag;
                k++;
            }
            if(k==99){
                break;
            }
        }
    }
}

long int cd(long int x){
    long int k=1;
    while(1){
        k=k+t;
        if(k%x==0){
            return(k/x);
        }
    }
}

void encrypt(){
    long int pt,ct,key=e[0],k,len;
    i=0;
    len=strlen(msg);
    while(i!=len){
        pt=m[i];
        pt=pt-96;
        k=1;
        for(j=0;j<key;j++){
            k=k*pt;
            k=k%n;
        }

        temp[i]=k;
        ct=k+96;
        en[i]=ct;
        i++;
    }
    en[i]=-1;
    cout<<"Encrypted message"<<endl;
    for(i=0;i<en[i]!=-1;i++){
        printf("%c",en[i]);
    }
}

void decrypt(){
    long int pt,ct,key=d[0],k;
    i=0;
    
    while(en[i]!=-1){
        ct=temp[i];
        k=1;
        for(j=0;j<key;j++){
            k=k*ct;
            k=k%n;
        }
        pt=pt+96;
        
        m[i]=pt;
        i++;
    }
   m[i]=-1;
    cout<<"Decrypted message"<<endl;
    for(i=0;i<m[i]!=-1;i++){
        printf("%c",m[i]);
    }
}