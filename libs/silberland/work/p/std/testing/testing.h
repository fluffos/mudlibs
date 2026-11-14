#define T_SUCCESS       1
#define T_FAILED        0
#define T_NOT_EXECUTED -1

#define T_STATUS "status"
#define T_REASON "reason"

void success();
varargs void fail(string reason);