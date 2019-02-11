/*
   problem  - D
   9/1/19
   by ahmed_drawy
   531 round div3
   technique  :
   self notes :
*/


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;
typedef tree<
        pair<int, int>, // change type
        null_type,
        less<pair<int, int> >, // change type
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
//#define push_back               pb;
//#define make_pair               mp;
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define lllp(i,start , end)       for(ll i = start ; i<end ; ++i)
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define Rlp(i,start , end)      for(int i = start ; i>end ; --i)
#define all(v)                   ((v).begin(),(v).end())
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2 *haven't understood this yet
#define isPowerOfTwo(S) (!(S & (S - 1)))            // done

#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))  // TBD


#define turnOffLastBit(S) ((S) & (S - 1))       // turn off last unset bit from right
#define turnOnLastZero(S) ((S) | (S + 1))       //turn on last unset bit from right
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))



typedef long long               ll;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;


const double EPS =1e-7;
const int OO = 1e6;
bool sortpair( const pair<int , int> & x, const pair<int , int> & y)
{

    return  x.first != y.first ? x.first < y.first : x.second > y.second ;


}
int dcomp(double x , double y)
{
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile(){
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
}

void printarr(int arr [] , int n){
lp(i,0,n) cout<<arr[i]<<" ";cout<<endl;
}

void printset(int n ){
    stack <int> myst;
    while(n)    myst.push(n%2), n/=2;
    while(!myst.empty())    cout<<myst.top(), myst.pop();
    cout<<endl;
}
int arr[5005];
int main(){
	smile();
	freopen("in.txt", "r" , stdin);
    int n ; cin >> n;
    string s ;cin >> s;
    map <char , int >frq ;
    lp(i,0, n){
        frq[s[i]]++;
    }
    if(frq['0'] == frq['1'] &&  frq['1' ] == frq['2']){

        cout<<s;

    }
    else {
        for(int i =s.size()-1   ;i >=0 ; --i){
            if(frq[s[i]] >s.size()/3){

               if(s[i] == '0'){
                    frq[s[i]]--;
                    if(frq['2'] <s.size()/3){
                        s[i] = '2';
                        frq[s[i]]++;
                    }
                    else {
                        s[i] = '1';
                        frq['1']++;
                    }
               }
               else if(s[i ] == '1'){
                    if(frq['2'] <s.size()/3){
                        frq[s[i]]--;
                        s[i] = '2';
                        frq['2']++;
                    }

               }

            }
        }
        lp(i,0,s.size()){
            if(frq[s[i]] > s.size()/3){
                    frq[s[i]]--;
                if(s[i] == '1'){

                    s[i] = '0';
                    frq['0']++;
                }
                else if(s[i ] == '2'){
                    if(frq['0' ] <s.size()/3){
                        frq['0'] ++;
                        s[i] = '0';
                    }
                    else {
                         frq['1'] ++;
                        s[i] = '1';
                    }
                }

            }

        }

        cout<<s;
    }

}



