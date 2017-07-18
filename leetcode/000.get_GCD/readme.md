## Final code
```
int generateGCD(int a,int b)
{
  return b==0? a : generateGCD(b, a%b);
}
```
https://codereview.stackexchange.com/questions/66711/greatest-common-divisor
