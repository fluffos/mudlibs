#include <defines.h>
#include <moredef.h>

#define EVENT(x) "/d/event/"+x
#define EVENTLOG EVENT("log/")+x

#define EVENTMASTER EVENT("master/eventmaster.lpc")

#define RABBIT(x) EVENT("rabbit/")+x
