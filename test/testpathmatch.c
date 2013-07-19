#include <stdio.h>
#include <pathmatch.h>

int test(const char *pattern, const char *text, int expect) {
    int actual = pathmatch(pattern, text);
    if (actual == expect) {
        printf("OK: ");
    } else {
        printf("ERROR: ");
    }
    printf("Pattern: %s Text: %s Match: %d\n", pattern, text, actual);
    return actual != expect;
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
