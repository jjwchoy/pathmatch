#include <iostream>
#include <pathmatch.h>

int test(const std::string &pattern, const std::string &text, bool expect) {
    bool actual = pathmatch::match(pattern, text);
    if (actual == expect) {
        std::cout << "OK: ";
    } else {
        std::cout << "ERROR: ";
    }
    std::cout << "Pattern: "
              << pattern
              << " Text: "
              << text
              << " Match: "
              << actual
              << std::endl;

    return actual == expect ? 0 : 1;
}

int main() {
    int failures = 0;
    failures += test("/abc/def", "/abc/def", 1);
    failures += test("/abc/def", "/abc/def/ghi", 0);
    failures += test("/abc/def/*", "/abc/def/ghi", 1);
    failures += test("/abc/def/*", "/abc/def/ghi/jkl", 0);
    failures += test("/abc/def/**", "/abc/def/ghi/jkl", 1);
    failures += test("/abc/def/**/", "/abc/def/ghi", 0);
    failures += test("/abc/def/**/", "/abc/def/ghi/jkl", 0);
    failures += test("/abc/def/**/*", "/abc/def/ghi/jkl", 1);
    failures += test("/abc/def/**/jkl/*", "/abc/def/ghi/jkl/mno", 1);
    failures += test("/abc/def/**/jkl/*", "/abc/def/ghi/jkl/mno/pqr", 0);
    failures += test("/abc/def/**/jkl/**", "/abc/def/ghi/jkl/mno/pqr", 1);
    failures += test("/abc/de?", "/abc/def", 1);
    failures += test("/abc/de?", "/abc/de/", 0);
    failures += test("/abc/de??", "/abc/de/", 1);
    failures += test("/abc/de??", "/abc/de/f", 0);
    return 0;
}
