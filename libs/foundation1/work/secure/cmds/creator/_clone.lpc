//      /bin/system/_clone.c
//      from the Nightmare Mudlib
//      clones objects into the game
//      created by Sulam 911219
//      largely rewritten for Nightmare by Descartes of Borg 930809

#include <std.h>

inherit DAEMON;

int cmd_clone(string str) {
    object ob;
    string msg;
    mixed res;

    if(ambassadorp(previous_object())) return 0;
    if(!str) {
        notify_fail("Clone what file?\n");
        return 0;
    }
    if(res = catch(ob = new(str = absolute_path((string)this_player()->get_path(),
      str))))
        write(str+": "+res);
    if(!ob) return 1;
    if(ob->move(this_player()) || !ob->get())
      ob->move(environment(this_player()));
    write(file_name(ob)+": cloned.");
    if(!this_player()->query_invis() && ob->query_short()) {
    msg = (string)this_player()->query_env("MCLONE");
    if(!msg) msg = "$N clones a $O.";
    msg = replace_string(msg, "$N", this_player()->query_cap_name());
    msg = replace_string(msg, "$O", ob->query_short());
    message("their_action", msg, environment(this_player()), this_player());
}
    return 1;
}

void help() {
   message("help", "Syntax: <clone [filename]>\n\nClones an object into your"
           " inventory if it is an object which can be gotten, otherwise it "
           "moves it into your environment.", this_player());
}
