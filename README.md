pathmatch
=========

pathmatch is a very simple path matching library, designed for fast matching of filesystem-style paths.

Language
--------

`*` - matches zero-or-more of any character(s) but '/'
`**` - matches zero-or-more of any character(s)
`?` - matches exactly one of any character but '/'
`??` - matches exactly one of any character

All other characters specify literal matches

There is no way to escape a ? or *

Examples
--------

`/foo/bar` matches only the path `/foo/bar`
`/foo/*/baz` matches `/foo/bar/baz` and `/foo/bob/baz` but not `/foo/baz` or `/foo/bar/bob/baz`
`/foo/**/baz` matches `/foo/bar/baz` and `/foo/bob/baz` and `/foo/bar/bob/baz` but not `/foo/baz`
`/foo?ar` matches `/foobar` and `/foocar` but not `/foo/ar`
`/foo??ar` matches /foobar` and `/foocar` and `/foo/ar`

API
---

C API

```
int path_match(const char *pattern, const char *text);
```

Returns 1 on successful match, 0 otherwise

C++ API
```
namespace pathmatch {

bool match(const std::string &pattern, const std::string &text);

}
```

Returns `true` on successful match, `false` otherwise

Features
--------

- Very small (<50 LOC)
- C89 compliant
- C++ interface
- MIT License
- Zero dependencies
- No configuration - easily embeddable

License
-------

The MIT License (MIT)

Copyright (c) 2013 Jason Choy

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so, 
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all 
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
