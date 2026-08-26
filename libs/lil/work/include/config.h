/*
 * if "global include file" is specified in the config file, this header
 * file is automatically included by all objects; otherwise, you have to
 * #include it manually
 */
#ifndef __CONFIG_H__
#define __CONFIG_H__

// FluffOS-compat fix (this project, 2026): the shipped config.h was an
// empty site-customization stub, but the bundled testsuite (single/tests/
// efuns/*, single/tests/operators/*) relies on ASSERT()/ASSERT2()/SAVETP/
// RESTORETP from tests.h being available in every compiled object without
// an explicit #include -- that's exactly what "global include file" is
// for. tests.h is include-guarded (TESTS_H), so this is safe even for
// files that also explicitly #include <globals.h> (which itself pulls in
// tests.h).
#include "tests.h"

#endif
