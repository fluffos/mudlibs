#ifndef _sys_size_h
#define _sys_size_h

// If you add defines here, also add them in LIB_DESCRIBE
#define SIZE_TINY        "20%"          // "tiny"
#define SIZE_SMALL       "70%"          // "small"
#define SIZE_MEDIUM     "100%"          // "medium"
#define SIZE_LARGE      "125%"          // "large"
#define SIZE_HUGE       "180%"          // "huge"
#define SIZE_GIGANTIC   "300%"          // "gigantic"

#define SIZES   ({ SIZE_TINY,           \
                   SIZE_SMALL,          \
                   SIZE_MEDIUM,         \
                   SIZE_LARGE,          \
                   SIZE_HUGE,           \
                   SIZE_GIGANTIC,       \
                })

#define SIZE_DESC_TINY           "tiny"
#define SIZE_DESC_SMALL          "small"
#define SIZE_DESC_MEDIUM         "medium-sized"
#define SIZE_DESC_LARGE          "large"
#define SIZE_DESC_HUGE           "huge"
#define SIZE_DESC_GIGANTIC       "gigantic"

#endif    // _sys_size_h
