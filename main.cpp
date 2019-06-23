#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto x = [](){ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

class Solution {
public:

    bool matches(const string& n, const string& h, int len, int offset) {
      for (int i = 0; i < len; ++i) {
        if (n[i] != h[i + offset])
          return false;
      }
      return true;
    }

    int strStr(string haystack, string needle) {
      int needleLen = needle.length();
      if (needleLen == 0) return 0;
      int haystackLen = haystack.length();
      if (needleLen == haystackLen && needle == haystack) return 0;
      int start = 0;
      for (start = 0; start <= (haystackLen - needleLen); ++start) {
        if (matches(needle, haystack, needleLen, start))
          return start;
      }
      return -1;
    }
};
void test1() {
  Solution S;
  string h = "hello";
  string n = "ll";

  cout << "2? " << S.strStr(h, n) << endl;

  h = "a";
  n = "a";
  cout << "0? " << S.strStr(h, n) << endl;

  h = "abbb";
  n = "bbb";
  cout << "1? " << S.strStr(h, n) << endl;

  h = "bbba";
  n = "bbb";
  cout << "0? " << S.strStr(h, n) << endl;

}

void test2() {
  Solution S;
}

void test3() {
  Solution S;
}

int main() {
  test1();
  test2();
  test3();
  cout << "Done!" << endl;
  
  return 0;
}

