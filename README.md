<div align="center">

<h3>Lightweight unit testing framework written in C</h3>
<p>Perfect for low level development!</p>

<img src="https://github.com/Tix3Dev/unit_testing_framework/blob/main/screenshot.png"> </a>

</div>

## Usage

Copy `unit_test.c` and `unit_test.h` into your C project.
You are now able to include the framework in every file you like:

```c
#include "unit_test.h"
```

In order to write tests, use `UNIT_TEST` and `UNIT_ASSERT`:
```c
#include "unit_test.h"

UNIT_TEST(dummy1)
{
    int a = 1;
    // do something cool with a

    UNIT_ASSERT(a == 2);
}

UNIT_TEST(dummy2)
{
    UNIT_ASSERT(2 == 2);

    UNIT_ASSERT(1 == 2);

    UNIT_ASSERT(3 > 5);

    UNIT_ASSERT(4 != 5);
}
```

So far, those tests will do nothing. To change that, simply call `unit_test_run_all` somewhere in your code:
```c
#include "unit_test.h"

int main(void)
{
    unit_test_run_all();
}
```

It's as easy as that!
