#include <iostream>
#include <string>

class MaxRotate
{
public:
  static long long maxRot(long long n)
  {
    std::string digits = std::to_string(n);
    long long max_val = n;
    for (int i = 0; i < digits.length(); i++)
    {
        char c = digits[i];
        digits.erase(digits.begin() + i);
        digits.push_back(c);
        long long rotated = std::stoll(digits);
        if (rotated > max_val)
        {
            max_val = rotated;
        }
    }
    return max_val;
  }
};
