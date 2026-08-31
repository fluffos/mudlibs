#include <std.h>

inherit DAEMON;

int cmd_scope(string str) {
    object ob;
    string desc;
    if (!str || str == "") return 0;
    ob = find_living(str);
    if (!ob) return notify_fail("No player found");
    ob = environment(ob);
    write("%^BOLD%^Filename%^RESET%^: "+file_name(ob));
    write(ob->query_long());
    write(ob->describe_item_contents( ({}) ) + "\n");
    write(ob->describe_living_contents( ({}) ) + "\n");
    write(ob->query_short_exits());

    return 1;
}

