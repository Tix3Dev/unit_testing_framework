/*
	This file is part of an lightweight and basic unit testing framework
	Everything is openly developed on GitHub: https://github.com/Tix3Dev/unit_testing_framework

	Copyright (C) 2022  Yves Vollmeier <https://github.com/Tix3Dev>
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdlib.h>

#include "../unit_test.h"
#include "unit_test_list.h"

UNIT_TEST(dummy1)
{
    void *ptr = malloc(1337);

    UNIT_ASSERT(ptr != NULL);

    free(ptr);
}

UNIT_TEST(dummy2)
{
    UNIT_ASSERT(1 == 1);

    UNIT_ASSERT(1 != 4);
}

UNIT_TEST(dummy3)
{
    UNIT_ASSERT(3 == 3);

    UNIT_ASSERT(4 == 3);
}

UNIT_TEST(dummy4)
{
    UNIT_ASSERT(2 == 2);

    UNIT_ASSERT(1 == 2);

    UNIT_ASSERT(3 > 5);

    UNIT_ASSERT(4 != 5);
}
