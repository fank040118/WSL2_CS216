#include <iostream>
#include <string>

int main() {
    int num = 123;
    
    // 方法1: 使用std::to_string (C++11及以上)
    std::string str1 = std::to_string(num);
    
    // 方法2: 使用stringstream
    std::stringstream ss;
    ss << num;
    std::string str2 = ss.str();
    
    // 方法3: 使用boost::lexical_cast (需要Boost库)
    // std::string str3 = boost::lexical_cast<std::string>(num);
    
    std::cout << "原始整数(original integer): " << num << std::endl;
    std::cout << "转换后的字符串(converted string) 1: " << str1 << std::endl;
    std::cout << "转换后的字符串(converted string) 2: " << str2 << std::endl;
    
    return 0;
}