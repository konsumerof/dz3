#include "header.hpp"

int main() {
    std::cout << "Enter the expression:";
    std::string a;
    getline(std::cin, a);
    std::cout << "Enter the accuracy:";
    int accuracy;
    std::cin >> accuracy;

    std::string PI;
    std::ostringstream stream;
    stream << std::setprecision(22) << M_PI;
    PI = stream.str();

    std::string x;
    if (std::count(a.begin(), a.end(), 'x') > 0) {
        std::cout << "Enter x:  ";
        std::cin >> x;
    }

    for (size_t i = 0; (i = a.find('x', i)) != std::string::npos; i += x.size())
        a.replace(i, 1, x);
    for (size_t i = 0; (i = a.find("cos", i)) != std::string::npos; i++)
        a.replace(i, 3, "c");
    for (size_t i = 0; (i = a.find("sin", i)) != std::string::npos; i++)
        a.replace(i, 3, "s");
    for (size_t i = 0; (i = a.find("tan", i)) != std::string::npos; i++)
        a.replace(i, 3, "t");
    for (size_t i = 0; (i = a.find("ctn", i)) != std::string::npos; i++)
        a.replace(i, 3, "k");
    for (size_t i = 0; (i = a.find("exp", i)) != std::string::npos; i++)
        a.replace(i, 3, "e");
    for (size_t i = 0; (i = a.find("pi", i)) != std::string::npos; i += PI.length())
        a.replace(i, 2, PI);
    for (size_t i = 0; (i = a.find('-', i)) != std::string::npos; i++)
        if (isdigit(a[i - 1]) == 0 && a[i - 1] != ')')
            a.replace(i, 1, "m");

    int amount = std::count(a.begin(), a.end(), ')');
    if (amount != std::count(a.begin(), a.end(), ')')) {
        std::cout << "Sorry but you've made a mistake" << std::endl;
        return 1;
    }

    for (int i = 0; i < amount; i++) {
        for (size_t m = 0; (m = a.find('-', m)) != std::string::npos; m++)
            if (isdigit(a[m - 1]) == 0 && a[m - 1] != ')')
                a.replace(m, 1, "m");
        int p2 = a.find(')');
        int p1 = a.rfind('(', p2);
        std::string sub = a.substr(p1 + 1, p2 - p1 - 1);
        sub = signs(sub);
        sub = expressions(sub);
        a.replace(p1, p2 - p1 + 1, sub);
    }

    for (size_t m = 0; (m = a.find('-', m)) != std::string::npos; m++)
        if (isdigit(a[m - 1]) == 0 && a[m - 1] != ')')
            a.replace(m, 1, "m");
    a = signs(a);
    expressions(a);
    char *end;
    double t = strtod(a.c_str(), &end);
    std::cout << std::setprecision(accuracy) << t << std::endl;

    return 0;
}
