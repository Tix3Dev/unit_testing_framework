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

#include <stdio.h>

#include "unit_test.h"

unit_test_t tests[MAX_TESTS];
int test_count = 0;

failed_assert_t fails[MAX_FAIL_COUNT];
int fail_count = 0;

void unit_assert_impl(char *file, int line_nr, bool condition, char *condition_str)
{
    if (condition)
        return;

    if (fail_count >= MAX_FAIL_COUNT)
    {
        printf("[WARNING]   Unit test - Maximal assert count exceeded!\n");
        return;
    }

    fails[fail_count++] = (failed_assert_t)
    {
        .file_name = file,
        .line_number = line_nr,
        .condition_string = condition_str
    };
}

void unit_test_add(unit_test_t test)
{
    tests[test_count++] = test;
}

void unit_test_run_all(void)
{
    for (int i = 0; i < test_count; i++)
    {
        unit_test_t current_test = tests[i];
        (*current_test.func_ptr)();

        if (fail_count == 0)
	{
            printf("[ 🗸 ]   Unit test for %s passed\n", current_test.func_name);
	    continue;
	}

        printf("[ ✗ ]	Unit test for %s failed\n", current_test.func_name);
        printf("	Failed asserts:\n");

        for (int j = 0; j < fail_count; j++)
        {
            failed_assert_t current_fail = fails[j];

            printf("		In %s:%d with condition %s\n",
                  current_fail.file_name,
                  current_fail.line_number,
                  current_fail.condition_string
	    );
        }

        // reset fails array by allowing overwriting from the start on
        fail_count = 0;
    }
}
