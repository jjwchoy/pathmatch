#include "pathmatch.h"

#include <assert.h>

int path_match(const char *pattern, const char *text) {
    assert(pattern && text);
    while (pattern[0] != '\0' && text[0] != '\0') {
        if (pattern[0] == '?') {
            if (!text[0]) {
                return 0;
            }
            if (pattern[1] == '?') {
                pattern += 2;
            } else {
                if (text[0] == '/') {
                    return 0;
                }
                ++pattern;
            }
            ++text;
        } else if (pattern[0] == '*') {
            int allow_slash = pattern[1] == '*';
            ++pattern;
            if (allow_slash) {
                ++pattern;
            }
            do {
                if (path_match(pattern, text)) {
                    return 1;
                }
            } while (text[0] != '\0' && (*text++ != '/' || allow_slash));
        } else {
            if (text[0] != pattern[0]) {
                return 0;
            }
            ++pattern;
            ++text;
        }
    }

    return *pattern == *text;
}
