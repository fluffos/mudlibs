//      /bin/ambassador/_goto.c
//      from the Nightmare Mudlib
//      teleports a person to another location
//      created by Descartes of Borg 930906

#include <std.h>

inherit DAEMON;
 
int cmd_goto(string str) {
    object ob;

    if(!str) return notify_fail("Goto where?\n");
    if((ob = find_living(lower_case(str))) && 
      (!ob->query_invis() || !adminp(ob)) && ob=environment(ob)) {
        if(ob == environment(this_player())) {
            message("my_action", "You twitch.", this_player());
            if(hiddenp(this_player())) return 1;
            message("other_action", (string)this_player()->query_cap_name()+
              " twitches.", ob, ({ this_player() }));
            return 1;
        }
    }
    if(ob && ob->query_invis() && creatorp(ob) && !adminp(this_player())) ob = 0;
    if(!ob) str = absolute_path((string)this_player()->get_path(), str);
    if(ob) this_player()->move_player(ob, "");
      else this_player()->move_player(str, "");
    return 1;
}

void help() {
    message("help",
      "Syntax: <goto [living thing|file]>\n\n"
      "This command will move you to where the living thing is if it can "
      "be found, otherwise it will search for the file named and try to "
      "move you into that file.\n\nSee also: home, move, trans.",
      this_player()
    );
}
