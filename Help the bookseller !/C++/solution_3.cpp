#include <vector>
#include <string>
#include <unordered_map>

class StockList {
public:
    static std::string stockSummary(
        std::vector<std::string> &listOfArt, std::vector<std::string> &categories) {
        if (listOfArt.empty() || categories.empty()) return "";
        std::unordered_map<char, int> stocks;
        for (const auto& book : listOfArt) {
            std::string code = book.substr(0, 1);
            int i = std::stoi(book.substr(book.find(' ') + 1));
            if (stocks.find(code[0]) == stocks.end())
                stocks[code[0]] = 0;
            stocks[code[0]] += i;
        }
        std::string result;
        for (const auto& category : categories) {
            if (!result.empty()) result += " - ";
            result += "(" + category + " : " + std::to_string(stocks[category[0]]) + ")";
        }
        return result;
    }
};