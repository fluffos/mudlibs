#include <std.h>
#include <daemons.h>

inherit DAEMON;

int do_find(object);

int cmd_find(string str) {
    //env = environment(this_object());
    if(!str) return notify_fail("Find who?\n");
    if(!find_player(str)) return notify_fail("Could not find that player\n");
    return do_find(find_player(str));
}

int do_find(object ob) {
    object env;
    string desc, file, exits, smell, listen;
    string liv, item;
    mixed tmp;

    desc = file = "";
    exits = smell = listen = liv = item = "";

    env = environment(ob);
    if (!env) {
      write("They are nowhere.");
      return 1;
    }

    if(this_player()->query_verbose()) {
/*
        if(maps && env->query_property("no map") != 1)
          desc = (string)MAPPER_D->mapper(this_player());
        else
          desc = wrap((string)env->query_long(0)+" ");
*/
        desc = (string)MAPPER_D->mapper(ob);

        exits = env->query_long_exits();

        tmp = env->query_smell("default");
        if (stringp(tmp)) smell = tmp;
        else if (functionp(tmp)) smell = (*tmp)("default");

        tmp = env->query_listen("default");
        if (stringp(tmp)) listen = tmp;
        else if (functionp(tmp)) listen = (*tmp)("default");

    }
    else {
        desc = (string)env->query_short(0) || "";
        desc += env->query_short_exits();
    }
    liv = env->describe_living_contents();
    item = env->describe_item_contents();

    if (wizardp(this_player())) file = file_name(env)+"\n";

    write(file+desc);

    if (strlen(smell))
      write("%^ORANGE%^"+smell+"%^RESET%^");
    if (strlen(listen))
      write("%^CYAN%^"+listen+"%^RESET%^");
    if (strlen(exits))
      write("\n"+exits+"\n");
    if (strlen(liv))
      write(liv+"\n");
    if (strlen(item))
      write(item);
    return 1;
}
