/*
 * if "global include file" is specified in the config file, this header
 * file is automatically included by all objects; otherwise, you have to
 * #include it manually
 */
#ifndef __CONFIG_H__
#define __CONFIG_H__

// The original GLOBAL_H macro pointed at a nonexistent
// /secure/include/globals.h (only a placeholder README lives under
// secure/include/ in this archive; the real header is
// /core/include/globals.h) and, even so, was never actually #include'd --
// just defined -- so this file never delivered on the comment above despite
// being wired up as the driver's "global include file". Fixed to really
// auto-include the real globals.h in every compiled object, which is also
// what makes the ASSERT/ASSERT2 macros (added in globals.h -- see its own
// comment) reach the whole /core/sefun/tests/ self-test suite, which calls
// them with no #include of their own.
#include <globals.h>

#endif
