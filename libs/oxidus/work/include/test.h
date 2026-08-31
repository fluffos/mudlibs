#ifndef TESTS_H
#define TESTS_H

#include <driver/type.h>

#define SAFE(x) do {x} while(0)

#define CLEAR_ERROR ((master()->clear_last_error() || 1))

#define OUTPUT(x) SAFE(write(catch(error(x)));)
#define WHERE __FILE__ + ":" + __LINE__

#define ASSERT(x) if (CLEAR_ERROR && !(x)) { OUTPUT(WHERE + ", Check failed.\n"); }
#define ASSERT2(x, r) if (CLEAR_ERROR && !(x)) { OUTPUT(WHERE + ", Check failed: " + r + ".\n"); }
#define ASSERT_EQ(x, y) do { CLEAR_ERROR; _assert_eq((x), (y), WHERE); } while (0)
#define ASSERT_NE(x, y) do { CLEAR_ERROR; _assert_ne((x), (y), WHERE); } while (0)

#endif
