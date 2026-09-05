/*
 * /sys/assert.h
 */


#ifdef NDEBUG
#  define assert(x)
#else

/* the usage of "do { ... } while (0)" works around several problems
// with the omitted semicolon at the end.
// the user will usually write "assert(...);" i.e. with a trailing
// semicolon, so we don't want our macro to end in a "}".  the otherwise
// resulting "};" sometimes raises problems.
// we also don't want to just write "if (...) raise_error(...)" because
// then a construct like
// "if (...)
//    assert(...);
//  else
//    ..." would raise the dangling-else problem (the "else" would be
// associated to the "if" in the macro).
// so we want a construct which groups our code in braces and which is
// an instruction which can be followed by a semicolon.
// the "do { ... } while (0)" fits both aspects.
*/

#  define assert(x)                                    \
   do {                                                \
     if (!(x))                                         \
       raise_error("assertion failed: " + "x" + " " +  \
                   __FILE__ + ":" + __LINE__ + "\n");  \
   } while (0)

#endif
