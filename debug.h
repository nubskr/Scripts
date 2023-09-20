#define        pb                push_back
#define        sz(v)             ((int)(v).size())
#define        int               long long
#define        nl                '\n'
#define        all(x)            (x).begin(),(x).end()
#define        se                second
#define        fs                first
#define        trav(a,x)         for(auto &a:x)
#define        per(i,a,b)        for(int i=b-1;i>=a;i--)
#define        rall(x)           (x).rbegin(),(x).rend()
#define        rep(i,a,b)        for(int i=a;i<b;i++)
namespace Color {
enum Code {
  FG_RED     = 31,
  FG_GREEN   = 32,
  FG_YELLOW  = 33,
  FG_BLUE    = 34,
  FG_DEFAULT = 39
};
class ColorDebugger {
  Code code;
 public:
  ColorDebugger(Code pCode) : code(pCode) {}
  template <class T>
  ColorDebugger& operator<<(const T &other) {
    cout << "\033[" << code << "m" << other << "\033[" << FG_DEFAULT << "m";
    return *this;
  }
  ColorDebugger& operator<<(ostream&(*pManip)(ostream&)){
    (*pManip)(cout);
    return *this;
  }
};
}

using namespace Color;
ColorDebugger ycout(FG_YELLOW);
ColorDebugger rcout(FG_RED);
ColorDebugger bcout(FG_BLUE);
ColorDebugger gcout(FG_GREEN);

void dbg_out() { ycout << nl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { ycout << ' ' << H; dbg_out(T...); }
#define deb(...) ycout << "(" << #__VA_ARGS__ << "):"; dbg_out(__VA_ARGS__);
// #define debv(a) rcout << #a << " : ("; rep(i,0,sz(a)){rcout << a[i] << (i==sz(a)-1 ? ")" : ",");} rcout << nl;
#define debv(a) rcout << #a << ": "; trav(i,a){rcout << i <<  ",";} rcout << nl;
// #define debp(a) rcout << #a << "[ \n"; trav(i,a){rcout << i.fs << '-' << i.se << nl;} rcout << ']';
