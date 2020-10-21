#include <iostream>
#include <exception>
#include <stdexcept>
#include <map>

using namespace std;
template <typename Value, typename Key>
Value& GetRefStrict(map<Key, Value>& items, const Key key) {
  if (items.count(key)) {
    return items[key];
  }
  throw runtime_error("");
}

int main() {

  map<int, string> m = {{0, "value"}};
  string& item = GetRefStrict(m, 0);
  item = "newvalue";
  cout << m[0] << endl; // выведет newvalue
  return 0;
}
