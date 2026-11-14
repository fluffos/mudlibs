#include "../files.h"

#pragma strong_types

#include <defines.h>
#include <moredef.h>

#define TELLPLAYER(x) tell_object(TP,x)
#define TELLOTHERS(x) tell_room(ENV(TP),x,({TP}))
#define DB(x) if(find_player("ronja")) tell_object(find_player("ronja"), "\nXXX "+x+"\n\n")

#define TPUID capitalize(getuid(this_player()))
#define UID(x) capitalize(getuid(x))
#define BSI(x,y) break_string(x,78,y,1)
#define CTPN capitalize(this_player()->name())

