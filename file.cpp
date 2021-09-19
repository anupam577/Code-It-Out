 /* एक ही नारा एक ही नाम 
              जय श्री राम जय श्री राम  */                  
#include<bits/stdc++.h>
using namespace std;
#define ll          long long 
#define ull         unsigned long long 
#define ld          long double
#define mp          map<ll,ll> 
#define mpc         map<char,ll>
#define mps         map<string,ll>
#define pb          push_back
#define pll         pair<ll,ll> 
#define vll         vector<ll>
#define vpll        vector<pair<ll,ll>>
#define prq         priority_queue<ll>//max
#define prqs        priority_queue<ll,vector<ll>,greater<ll>>//min
#define m_p         make_pair
#define ff          first
#define ss          second
#define b_s         binary_search
#define l_b         lower_bound
#define u_b         upper_bound
#define l(i,s,e)  for(ll i=s;i<e;i++)
#define Test        ll t;cin>>t;while(t--)
#define all(v)      v.begin(),v.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define ln          '\n'  
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
const ll mod =1e9+7;
const ull INF=1e9;
const ll  MOD =  998244353;
const ll  N   =  2e5+7;
ll FACT[N];
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

ll POW(ll x,ll y){
      ll r=1;
      for(; y ; x= (x % MOD * x % MOD ) % MOD  ,y>>=1)
            if(y&1) r = (r % MOD * x % MOD) % MOD ;
      return r;
}

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}
int computeXOR(int n)
{
   
  // If n is a multiple of 4
  if (n % 4 == 0)
    return n;
 
  // If n%4 gives remainder 1
  if (n % 4 == 1)
    return 1;
 
  // If n%4 gives remainder 2
  if (n % 4 == 2)
    return n + 1;
 
  // If n%4 gives remainder 3
  return 0;
}
ll fast_exp(int base, int exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res%MOD;
}

bool areBracketsBalanced(string expr)
{ 
    stack<char> s;
    char x;
 
    // Traversing the Expression
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '['
            || expr[i] == '{')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }
 
        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (s.empty())
            return false;
 
        switch (expr[i]) {
        case ')':
             
            // Store the top element in a
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;
 
        case '}':
 
            // Store the top element in b
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;
 
        case ']':
 
            // Store the top element in c
            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
 
    // Check Empty Stack
    return (s.empty());
}


ll merge(ll arr[],ll l,ll mid,ll r){
    ll inv=0;
    ll n1=mid-l+1;
    ll n2=r-mid;
    ll a[n1];
    ll b[n2];
    
    
    for(ll i=0;i<n1;i++)
    a[i]=arr[l+i];
    for(ll i=0;i<n2;i++)
    b[i]=arr[mid+i+1];
    ll i=0,j=0,k=l;
    
    while(i<n1&&j<n2){
        if(a[i]<=b[j]){
            arr[k]=a[i];
            k++;
            i++;
        }
        else{
            arr[k]=b[j];
         inv +=n1-i;
            k++;
            j++;
        }
    }
    
    while(i<n1){
        arr[k]=a[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++;
        j++;
        
    }
    return inv;
}
 
 ll mergeSort(ll arr[],ll l,ll r){
     ll inv=0;
     if(l<r){
         ll mid=(l+r)/2;
     inv+=  mergeSort(arr,l,mid);
      inv+= mergeSort(arr,mid+1,r);
      inv+=  merge(arr,l,mid,r);
     }
    return inv;
 }
bool sortbysec(const pair<ll,ll> &a,
              const pair<ll,ll> &b)
{
    return (a.second < b.second);
}



int main(){

 fast();
  
ll n;
cin>>n;
ll a[n];
deque<ll>q;
for(ll i=0;i<n;i++){
    cin>>a[i];
    q.pb(a[i]);

}
stack<ll>s;
vector<char> v;
if(n==1){
    cout<<1<<endl<<'L';
return 0;
}

if(q.front()>q.back()){
    v.pb('R');
    ll k=q.back();
    s.push(k);
    q.pop_back();

}
else{
    v.pb('L');
    ll k=q.front();
    s.push(k);
    q.pop_front();

}

while(1){
  
if(q.size()>1){
  if(q.front()>s.top()&&q.front()<q.back()){
    v.pb('L');
    s.push(q.front());
    q.pop_front();

  }
  else if(q.back()>s.top()){
     v.pb('R');
    s.push(q.back());
    q.pop_back();
  }
  else if(q.front()>s.top()){

    v.pb('L');
    s.push(q.front());
    q.pop_front();
  }

  else
    break;

}
else{
    if(q.front()>s.top()){
        v.pb('L');
        s.push(q.front());
    }
    break;
}

  

// break;



}


  cout<<s.size()<<endl;
  for(auto i:v)
    cout<<i;

 

}