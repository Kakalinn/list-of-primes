#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define MAXN 10000000
#define rep(E, F) for (E = 0; E < (F); E++)
typedef long long ll;
typedef __int128 lll;

ll bigprod(ll x, ll y, ll m)
{
	return ((lll)x*y)%m;
}

ll modpow(ll x, ll n, ll m)
{ 
	ll r = 1;
	while (n > 0) 
	{ 
		if (n%2 == 1) r = bigprod(r, x, m);
		n = n/2;
		x = bigprod(x, x, m);
	} 
	return r; 
}

int ispp(ll n)
{
	if (n%2 == 0) return n == 2;
	if (n <= 3) return n == 3;
	ll i, k, s = 0, d = n - 1,
	   	t[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	while (d%2 == 0) d /= 2, s++;
	rep(k, 12) if (t[k] <= n - 2)
	{
		ll a = t[k];
		lll x = modpow(a, d, n);
		if (x == 1 || x == n - 1) continue;
		rep(i, s - 1) if ((x = bigprod(x, x, n)) == n - 1) break;
		if (i == s - 1) return 0;
	}
	return 1;
}

int isp(ll n)
{
	ll i;
	if (n == 2 || n == 3) return 1;
	if (n%2 == 0 || n%3 == 0) return 0;
	for (i = 5; i*i <= n; i+= 6) if (n%i == 0 || n%(i + 2) == 0) return 0;
	return 1;
}

int main()
{ // slowly finds all primes larger then |x| using first Miller-Rabin and then a slower deterministic check.
	ll x;
	for (scanf("%lld", &x);; x++) if (ispp(x) && isp(x)) printf("%lld\n", x);
}
