class StockList {
public:
    static std::string stockSummary(
        std::vector<std::string> &listOfArt, std::vector<std::string> &categories) {
        if (listOfArt.empty() || categories.empty())
            return "";
        int stocks['Z' + 1] = {0};
        for (const std::string &book : listOfArt) {
                std::size_t position = book.find_first_of(" ", 2, 1);
                stocks[book[0]] += std::atoi(book.data() + position);
        }
        std::string result = "";
        for (const std::string &category : categories) {
            result = result
                + (result.empty() ? "" : " - ")
                + "(" + category[0] + " : " + std::to_string(stocks[category[0]]) + ")";
        }
        return result;
    }
};