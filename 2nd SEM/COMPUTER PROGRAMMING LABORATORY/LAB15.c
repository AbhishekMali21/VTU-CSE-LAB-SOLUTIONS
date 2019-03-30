#include <stdio.h>
#include <math.h>
int BinaryToDecimal(long long n);

int main()
{
    long long n;
    printf("Enter a binary number: ");
    scanf("%lld", &n);
    printf("%lld in binary = %d in decimal", n, BinaryToDecimal(n));
    return 0;
}

int BinaryToDecimal(long long n)
{
    int dec = 0, i = 0, rem;
    while (n!=0)
    {
    	rem = n % 10;
    	n = n / 10;
    	dec = dec + rem*pow(2,i);
    	i++;
    }
    return dec;
}
