#ifdef DEBUG
#define assert(x) if(!(x)) \
    printf("assertion failed :file %s, %s.\n", __FILE__,"x")
#define ASSERT(x) if(!(x)) \
    error(sprintf("assertion failed : file %s, %s." , __FILE__ , "x" ))
#else
#define assert(x)
#define ASSERT(x)
#endif
