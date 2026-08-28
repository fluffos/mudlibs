#ifndef __ASSERT_H__
#define __ASSERT_H__

#ifdef DEBUG
# define assert(x)	if (x) {} else { error(sprintf(\
		    "Assertion failed: \"##x\" (File: %s)\n",  __FILE__)); }
#else
# define assert(x)
#endif

#define ENSURE(x)	if (x) {} else { error(sprintf(\
		    "Assertion failed: \"##x\" (File: %s)\n",  __FILE__)); }

//### backwards compat
#define ASSERT(x) ENSURE(x)

#endif /* __ASSERT_H__ */
