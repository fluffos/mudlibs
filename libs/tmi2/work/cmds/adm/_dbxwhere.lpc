#include <mudlib.h>

inherit DAEMON;

int
cmd_dbxwhere(string str) {
    mapping error;
    object ob;
    int i;

    if (str) {
        ob = find_player(str);
        if (!ob) {
            write("No such player.");
            return 1;
        }
    } else
        ob = this_player();
    if (error = (mapping)ob->query_error()) {

        printf("%s\n", master()->standard_trace(error, 1));
    } else write("No error.\n");
    return 1;
}
