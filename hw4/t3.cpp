#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,k,q,l,r;
char** a;
char** save;

int cntF(char *a){
    int cnt=0;
    for(int i=0;i<k;i++){
        if(a[i]=='F') cnt++;
    }
    return cnt;
}

void solve(){
    for(int i=k-1;i>=0;i--){
        int backet[16];
        for(int j=0;j<16;j++){
            backet[j]=0;
        }
        for(int j=1;j<=n;j++){
            char c=a[j][i];
            int dig;
            if('0'<=c&&c<='9'){
                dig=c-48;
            }
            else{
                dig=c-55;
            }
            backet[dig]++;
        }
        for(int j=1;j<16;j++){
            backet[j]+=backet[j-1];
        }
        for(int j=n;j>=1;j--){
            char c=a[j][i];
            int dig;
            if('0'<=c&&c<='9'){
                dig=c-48;
            }
            else{
                dig=c-55;
            }
            strcpy(save[backet[dig]--],a[j]);
        }
        for(int j=1;j<=n;j++){
            strcpy(a[j],save[j]);
        }
    }
}

int main(){
    scanf("%d %d",&n,&k);
    a=(char**)malloc((n+1)*sizeof(char*));
    save=(char**)malloc((n+1)*sizeof(char*));
    char* b=(char*)malloc(2*(n+1)*(k+1)*sizeof(char));
    for(int i=0;i<n;i++){
        a[i+1]=b+i*(k+1);
        scanf("%s",a[i+1]);
        save[i+1]=b+(n+1)*(k+1)+i*(k+1);
    }
    scanf("%d",&q);
    solve();
    int prec[n+1];
    prec[0]=0;
    for(int i=1;i<=n;i++){
        prec[i]=prec[i-1]+cntF(a[i]);
    }
    while(q--){
        scanf("%d %d",&l,&r);
        printf("%d\n",prec[r]-prec[l-1]);
    }
    return 0;
}