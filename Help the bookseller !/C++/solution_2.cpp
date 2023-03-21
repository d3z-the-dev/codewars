#include <numeric>

class StockList {
public:
    static std::string stockSummary(
        std::vector<std::string> &listOfArt, std::vector<std::string> &categories) {
        return listOfArt.empty() ? "" : std::accumulate(
            categories.begin(), categories.end(), std::string(), [&listOfArt](auto &&result, auto &&m) {
            return result + std::string(result.empty() ? "" : " - ") + '(' + m + " : " + 
                std::to_string(std::accumulate(
                    listOfArt.begin(), listOfArt.end(), 0, [&m](auto sum, auto &&l) {
                return sum + (l[0] == m[0] ? atoi(l.data() + l.find(' ')) : 0); })) + ")";
        });
    }
};