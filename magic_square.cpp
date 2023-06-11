#include<stdio.h>
#include<stdlib.h>

using namespace std;

void swap(int &r,int &q){
    int t=r;
    r=q;
    q=t;
}
int main(int argc,char* argv[]){
    int i,j,n,k;
    char ch;
    printf("Enter a number: ");
    scanf("%d",&n);
    do{
        int magic_square[n][n];

        //Odd number
        if(n%2!=0){
            for (int a = 0; a < n; a++) {
                for (int b = 0; b < n; b++) {
                    magic_square[a][b] = 0;
                }
            }
            i = 0;
            j = n/2;
            magic_square[i][j] = 1;
            
            for(k=2;k<=n*n;k++){
                i--;
                j++;
                if(i<0 && j>n-1){
                    i = 1;
                    j = n-1;
                }
                else if(i<0){
                    i = n-1;
                }
                else if(j>n-1){
                    j = 0;
                }
                if(magic_square[i][j]!=0){
                    i+=2;
                    j--;
                }
                magic_square[i][j] = k;
            }


        }
        //case 2(4k)
        else if(n%4==0){
            int temp;
            for (int a = 0; a < n; a++) {
                for (int b = 0; b < n; b++) {
                    temp = a*n+b+1;
                    if(( a%4==0 || a%4==3) &&( b%4==0 || b%4==3)){
                        magic_square[a][b] =temp;
                    }
                    else if(( a%4==1 || a%4==2) &&( b%4==1 || b%4==2)){
                        magic_square[a][b] =temp;
                    }
                    else{
                        magic_square[a][b] = n*n+1-temp;
                    }
                }
            }

        }
        //case 3(4k+2)
        else{
            for (int a = 0; a < n; a++) {
                for (int b = 0; b < n; b++) {
                    magic_square[a][b] = 0;
                }
            }
            int k2 = (n-2)/4;
            printf("k is %d\n",k2);
            int odd = n/2;

            i = 0;
            j = odd/2;
            magic_square[i][j] = 1;
            
            for(k=2;k<=odd*odd;k++){
                i--;
                j++;
                if(i<0 && j>odd-1){
                    i = 1;
                    j = odd-1;
                }
                else if(i<0){
                    i = odd-1;
                }
                else if(j>odd-1){
                    j = 0;
                }
                if(magic_square[i][j]!=0){
                    i+=2;
                    j--;
                }
                magic_square[i][j] = k;
            }

            for(i=0;i<odd;i++){
                for(j=0;j<odd;j++){
                    magic_square[i][j] = magic_square[i][j];
                    magic_square[i+odd][j+odd] = magic_square[i][j]+1*odd*odd;
                    magic_square[i][j+odd] = magic_square[i][j]+2*odd*odd;
                    magic_square[i+odd][j] = magic_square[i][j]+3*odd*odd;
                }
            }
            for(i=0;i<k2;i++){
                for(j=0;j<k2;j++){
                    swap(magic_square[i][j],magic_square[i+odd][j]);
                }
            }
            for(i=odd-k2;i<odd;i++){
                for(j=0;j<k2;j++){
                    swap(magic_square[i][j],magic_square[i+odd][j]);
                }
            }
            for(j=0;j<k2;j++){
                swap(magic_square[odd/2][j+odd/2],magic_square[3*odd/2][j+odd/2]);
            }
            for(i=0;i<odd;i++){
                for(j=3*odd/2;j<3*odd/2+k2-1;j++){
                    swap(magic_square[i][j],magic_square[i+odd][j]);
                }
            }
        }

        //print matrix
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%4d ",magic_square[i][j]);
            }
            printf("\n");
        }
        printf("Enter a number: ");
        scanf("%d",&n);
    }
    while(n!=2);
    return 0;
}
