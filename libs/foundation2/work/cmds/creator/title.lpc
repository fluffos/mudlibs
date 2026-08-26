#include <lib.h>

inherit LIB_DAEMON;

int cmd(string str) {
    if (!str) {
        notify_fail("title <string>\n");
        return 0;
    }
    if (strsrch(str, "$N")==-1) str = "$N " + str;
    this_player()->SetShort(str);
    write("Changed to: " + str);
    return 1;
}
