#include <door.h>

mixed query_short(int mode, object who) {
    if(who && who->query_coder_level()) 
	return ::query_short(0,who) + " <invis for players>";
    return 0;
}
