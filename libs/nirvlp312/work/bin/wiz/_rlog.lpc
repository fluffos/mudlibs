#include <security.h>
#pragma strict_types
#pragma save_types
int cmd_rlog(string arg) {
    if(this_player()->query_level() < EXPLORE) return 0;
    if(!arg || arg == (string)this_player()->query_real_name())
    {
    rm("/log/"+this_player()->query_real_name());
    write("Ok.\n");
    return 1; }
    if(this_player()->query_level() < SENIOR) return 0;
    rm("/log/"+arg);
    write("Deleted "+arg+"'s error log file.\n");
    return 1; }

/* Quick Error-Log Rm Command. -Kazer [12-17-99] */
/* fixed by -Bp */
