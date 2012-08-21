/**
 * libextc contracts testcase
 * ExtendedC
 *
 * Copyright (C) 2012 Justin Spahr-Summers
 * Released under the MIT license
 */

#include "contracts_test.h"

void contracts_test (void) {
	LOG_TEST("passing a valid parameter value");
	assert(in_test(5) == true);
	
	LOG_TEST("passing an invalid parameter value");
	assert(in_test(6) == false);
	assert(in_test(-10) == false);
	assert(in_test(0) == false);
	
	LOG_TEST("validating 'out' contract");
	void *ptr = out_test(1024);
	assert(ptr != NULL);
	
	free(ptr);
}

bool in_test_body (int value) {
	LOG_TEST("value = %i", value);
	return true;
}

void *out_test_body (size_t size) {
	LOG_TEST("size = %zu", size);
	return malloc(size);
}
