#include <cmd.h>
#include <config.h>

nomask varargs status
bug_cmd(string str)
{
    string who, room, myname;
    if(!str) return notify_fail("Give an argument.\n"), 0;
    if (present(str, environment(this_player())))
	return notify_fail("Use bug-command to report bugs;\
 it's not a feeling unlike some seem to think...\n"), 0;
    room = object_name(environment(TP));
    myname = (string) TP -> query_real_name();
    log_file("BUGS", "\n" + myname + " (" + room + "):\n" +str + "\n");
    if (sscanf(room, PATH_USER_FNAME "%s/", who)) log_file(
	  who + ".rep", room + " " + "Bug: " + myname + "\n" + str + "\n");
    TP -> tell_me("Ok.");
    return 1;
}
