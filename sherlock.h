/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
int const max_HP=999,max_EXP=900,max_M=2000,min_all=0;

int limit(double x, int min_x, int max_x){
    if(x<min_x) x=min_x;
    else if (x>max_x) x=max_x;
    if (round(x)!=x){
        x=round(x+0.5);
    }
    return (int)x;
}


int firstMeet(int& EXP1, int& EXP2, const int& E1){
    //Complete this function to gain point on task 1
    // kiem tra dieu kien cua cac input
    EXP1=limit(EXP1,min_all,max_EXP);
    EXP2=limit(EXP2,min_all,max_EXP);
    //truong hop 1
    if (E1<400){
        //thay doi exp cua waston qua thong tin cua sherlock
        if(E1<50){
            EXP2+=25;
        }
        else if (E1<100){
            EXP2+=50;
        }
        else if (E1<150){
            EXP2+=85;
        }
        else if (E1<200){
            EXP2+=(25+50);
        }
        else if (E1<250){
            EXP2+=(85+25);
        }
        else if (E1<300){
            EXP2+=(85+50);
        }
        else{
            EXP2+=(25+50+85);
        }
        //thay doi exp cua sherlock qua viec doan dat nuoc cua waston tro ve
        if((E1%2)!=0){
            EXP1=limit(EXP1+(E1/10.0),min_all,max_EXP);
        }
        else{
            EXP1=limit(EXP1-(E1/5.0),min_all,max_EXP);
        }
    //kiem tra lai dieu kien EXP cua waston, EXP1 da thoa dieu kien truoc do
    EXP2=limit(EXP2,min_all,max_EXP);
    }
    //truong hop 2
    else{
        if (E1<500){
            EXP2=limit(EXP2+E1/7.0+9,min_all,max_EXP);
        }
        else if (E1<600){
            EXP2=limit(EXP2+E1/9.0+11,min_all,max_EXP);
        }
        else if (E1<700){
            EXP2=limit(EXP2+E1/5.0+6,min_all,max_EXP);
        }
        else if (E1<800){
            EXP2=limit(EXP2+E1/7.0+9,min_all,max_EXP);
            if (EXP2>200){
                EXP2=limit(EXP2+E1/9.0+11,min_all,max_EXP);
            }
        }
        else {
            EXP2=limit(EXP2+E1/7.0+9,min_all,max_EXP);
            EXP2=limit(EXP2+E1/9.0+11,min_all,max_EXP);
            if (EXP2>600){
                EXP2=limit(EXP2+E1/5.0+6,min_all,max_EXP);
                EXP2=limit(EXP2*1.15,min_all,max_EXP);
            }
        }
        EXP1=limit(EXP1-0.1*E1,min_all,max_EXP);
        //ca 2 EXP deu duoc tinh bang limit nen khong can kiem tra dieu kien
    }
    return EXP1+EXP2;

}

int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2){
    //Complete this function to gain point on task 2
    /*// kiem tra dieu kien input
    EXP1=limit(EXP1,min_all,max_EXP);
    EXP2=limit(EXP2,min_all,max_EXP);
    HP1=limit(HP1,min_all,max_HP);
    HP2=limit(HP2,min_all,max_HP);
    M2=limit(M2,min_all,max_M);
    //giai doan 1
    // khai bao bien la exp tang cua waston
    int d=0;
    //cac truong hop E2
    d+=limit(E2/9.0+10,min_all,max_EXP);
    if(EXP>=300){
        d+=limit()
    }

    */return -1;
}

void con_duong_1(int& HP1, int& EXP1, int& M1,const int E3){
   bool hanh_ly=false;
   int i=0,k;
    // khai bao mang p1[i]
    int p1[9];
    // cap nhat cac gia tri p1[i]
    for(i=0;i<9;i++){
        p1[i]=(2*i+1+E3)%26+65;
        // tim hanh ly 80
        if (p1[i]==80){
            hanh_ly=true;
            break;
        }
    }
    //cap nhat chi so sherlock
    if(hanh_ly){
        k=i+1;
        HP1=limit(HP1-p1[i]*k*2,min_all,max_HP);
        EXP1=limit(EXP1+(1000-p1[i]*k)%101,min_all,max_EXP);
        M1=limit(M1-k*E3/9.0,min_all,max_M);
    }
    else{
        M1=limit(M1-9*9*E3/9.0,min_all,max_M);
    }
}

// ham kiem tra so nguyen to
bool isPrime(int n)
{
    /*TODO: add your code here*/
    if (n==2) return true;
    if ((n==0) || (n==1) || ((n%2)==0)) return false;
    for (int i=3; i<n;i+=2)
        if (( n % i)==0) return false;
    return true;
}

void con_duong_2(int& HP1, int& EXP1, int& M1,const int E3){
   bool hanh_ly=false;
   int so_snt=0,p2[7],n=2;
   // tim 7 so nguyen to dau tien
   while(so_snt<7){
    if (isPrime(n)){
        p2[so_snt]=n;
        so_snt++;
    }
    n++;
   }
   // phep bien doi dau tien p2i=(p2i+E3)%26
   for(int i=0;i<7;i++){
        p2[i]=(p2[i]+E3)%26;
   }
   
}

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3){
    //Complete this function to gain point on task 3
    // kiem tra dieu kien input
    HP1=limit(HP1,min_all,max_HP);
    EXP1=limit(EXP1,min_all,max_EXP);
    M1=limit(M1,min_all,max_M);
    //con duong 1
    con_duong_1(HP1,EXP1,M1,E3);
    return -1;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
