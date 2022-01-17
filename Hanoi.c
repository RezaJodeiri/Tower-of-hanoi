#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int peg1[9]={0},peg2[9]={0},peg3[9]={0};
void display_pegs() {
    int i,space,a,b,c,p,j,k;
    
    for(i = 0; i < 10; i++) {
        if (i !=9) {
            
            a=peg1[8-i];
            b=peg2[8-i];
            c=peg3[8-i];
            //a here
            for (space=10;space>a;space--) {
                printf(" ");
            }
            
            for (j=0;j<2*a+1;j++) {
                if (j==a) {
                    printf("|");
                }
                else {
                    printf("+");
                }
            }
            for (space;space<15;space++) {
                printf(" ");
            }
            
            ///b here
            for (space=10;space>b;space--) {
                printf(" ");
            }
            
            for (j=0;j<2*b+1;j++) {
                if (j==b) {
                    printf("|");
                }
                else {
                    printf("+");
                }
            }
            if (b=0) {
                printf("|"); 
            }
            for (space;space<15;space++) {
                printf(" ");
            }
            
            ///c here
            for (space=10;space>c;space--) {
                printf(" ");
            }
            
            for (j=0;j<2*c+1;j++) {
                if (j==c) {
                    printf("|");
                }
                else {
                    printf("+");
                }
            }
            if (c=0 && peg3[0]==0) {
                printf("|"); 
            }
        
        }
        else {
            for (p=0;p<3;p++) {
                for (j=0;j<21;j++) {
                    printf("X");
                }
                if (p<2) {
                    for (k=0;k<5;k++) {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
}
void move(int pegA[9],int pegB[9]) {
    int i,j,temp;
    for(i= 0; i < 9; i++) {
        if (pegA[i+1]==0) {
            temp=pegA[i];
            pegA[i]=0;
            break;
        }
    }
    for (j=0;j<9;j++) {
        if (pegB[j]==0) {
            pegB[j]=temp;
            break;
        }
    }
    display_pegs();
    sleep(1);
}
void hantow(int nod,int pego[9],int pegd[9],int pegh[9]) {
    if (nod > 1) {
        hantow(nod-1,pego,pegh,pegd);
    }
    move(pego,pegd);
    if (nod > 1) {
        hantow(nod-1,pegh,pegd,pego);
    }
}
int main(int argc,char* argv[]) {
  int i,nod;
  if (argc != 2) {
    printf("Too many command line arguments\n");
    return 0;
  }
  else if (strlen(argv[1])!= 1) {
    printf("Incorrect argument\n");
    return 0;
  }
  else if (argv[1][0]<'1' || argv[1][0]>'9') {
    printf("Incorrect number\n");
    return 0;
  }
  nod = argv[1][0]-'0';
  for(i = 0; i < 9; i++) {
      if (nod-i >-1) {
          peg1[i]=nod-i;
      }
  }
  display_pegs();
  hantow(nod,peg1,peg2,peg3);
  printf("done!");
  return 0;
}