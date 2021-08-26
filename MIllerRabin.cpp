#include <iostream>
#include <cstring>
#include <cstdlib>
typedef long long ll;
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
u64 binpower(u64 base, u64 e, u64 mod)
{
    u64 result = 1;
    base %= mod;
    while (e)
    {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s)
{
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++)
    {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};
bool MillerRabin(u64 n)
{
    if (n < 6)
        return n == 2 || n == 3 || n == 5;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        r++;
    }

    for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
    //thường thì sẽ dùng 40 base nhưng trên trang https://miller-rabin.appspot.com/
    //thì có mấy thánh nhân dùng 7 base thôi nên mình copy 7 base đó
    {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0) ;
    cout.tie(0);
    unsigned long long num;
    while (cin >> num)
    {

        cout << MillerRabin(num) << endl;
    }
}
