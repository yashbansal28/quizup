#include<stdio.h>
#include<math.h>
# define e 0.00001
#define f(x) x*x*x-2*x-5
int main()
{
    float a,b,c;
    int i=1;
    printf("enter valuea of a na b");
    scanf("%f %f",&a,&b);
    if(f(a)*f(b)<=0)
    {
        do
        {
            c=(a+b)/2;
            printf("i=%d | a=%.4f| b=%.4f| c=%.4f |f(a)=%.4f | f(b)=%.4f| f(c)=%.4f",i,a,b,c,f(a),f(b),f(c));
            printf("\n");
            if(f(a)*f(c)<0)
            {
                a=a;
                b=c;
            }
            else
            {
                a=c;
                b=b;
            }
            i++;
        }
            while(fabs(f(c))>e);
            printf("\n");
            printf("roots is %.4f",c);
            
    }
            else
            {
                printf("not exist");
            }
            
            return 0;
        

}
