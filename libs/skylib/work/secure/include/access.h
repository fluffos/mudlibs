#ifndef __SYS__ACCESS
#define __SYS__ACCESS

#define ACCESS    1
#define NO_ACCESS 3
#define NO_NEW    2
#define ERROR     0

#define DEFAULT ACCESS

#define ACCESS_LEVEL   0
#define ACCESS_REASON  1
#define ACCESS_TIMEOUT 2

#define SUSPEND_TIME   0
#define SUSPEND_REASON 1

#define READ_MASK   1
#define WRITE_MASK  2
#define GRANT_MASK  4
#define LOCK_MASK   8

#define PERM_NAMES ({ "error", "normal access", "no new characters", "no access" })
#endif /* __SYS__ACCESS */
