## 순환 
> 자기 자신을 호출하는 함수 

### 무한루프에 빠지지 않으려면 ?
> - base case : 적어도 하나의 recursion에 빠지지 않는 경우가 존재해야 한다.
> - recursive case : recursion을 반복하다보면 결국 base case로 수렴해야 한다.

```
public static void func(int k) {
    if(k<=0)          // base case
       return;
    else {
        System.out.println("Hello");
        func(k-1);    // recursive case
    }
} 
```

### 기본예제들 
> - 정수 n에 대해서 0~n까지의 합. 
```
public class code {
    public static void main(string [] args) {
        int result = func(4);
        System.out.print(result);
    }
}

public static int func(int n) {
    if(n<=0)
        return 0;
    else {
        return n+func(n-1);
    }
}
```

> - 팩토리얼 
> 0! = 1
> n! = n x (n-1)!  
```
public static int factorial(int n)
{
    if (n==0)
       return 1;
    else
       return n*factorial(n-1);
}
```

> - x<sup>n</sup>
```
public static double power(double x, int n) {
    if (n==0)
        return 1;
    else
        return x * power(x, n-1);
}
```

> - fibonacci number 
> f<sub>0</sub> = 0
> f<sub>1</sub> = 1
> f<sub>n</sub> = f<sub>n-1</sub> + f<sub>n-2</sub> 
```
public int fibonacci (int n) {
    if(n<2)
       return n;
    else
       return fibonacci(n-1) + fibonacci(n-2);
}
```

> - 최대공약수
> m>=n 인 두 양의 정수 m과 n에 대해서 m이 n의 배수이면 gcd(m,n) = n이고, 그렇지 않으면 gcd(m,n) = gcd(n,m%n) 이다.
```
public static double gcd(int m, int n) {
    if(q==0)
       return p;
    else
       return gcd(q, p%q);
}
```