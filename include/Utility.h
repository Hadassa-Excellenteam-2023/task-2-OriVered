#include <string>
#include <iostream>
#include <vector>
#include <utility>

using std::vector;
using std::unique_ptr;
using std::string;
using std::make_unique;
using std::make_pair;
using Location = std::pair<string, int>;

Location convertToLocation(int num);
Location convertToLocationFromStr(const std::string& locationStr);
std::vector<Location> getPath(const Location& src, const Location& dest);