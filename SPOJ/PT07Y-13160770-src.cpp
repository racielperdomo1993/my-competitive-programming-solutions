#include<stdio.h>
struct NODE{
int pi;
int prior;
};
int BUSCA(struct NODE ar[],int a){
if(ar[a].pi==-1){
return a;
}
BUSCA(ar,ar[a].pi);
}
int main(){
int a,b,c,d,e,x,i=0;
scanf("%d %d",&a,&b);
struct NODE ar[a+1];
for(x=0;x<=a;x++){
ar[x].pi=-1;
ar[x].prior=0;
}
while(b--){
scanf("%d %d",&c,&d);
int g=BUSCA(ar,c);
int f=BUSCA(ar,d);
if(g==f){
i=1;
}else{
if(ar[g].prior<ar[f].prior)
        ar[g].pi=f;
    else if(ar[g].prior>ar[f].prior)
        ar[f].pi=g;
    else{
        ar[f].pi=g;
        ar[g].prior++;
    }
}
}
if(i==0){
printf("YES\n");
}else{
printf("NO\n");
}
return 0;
}
