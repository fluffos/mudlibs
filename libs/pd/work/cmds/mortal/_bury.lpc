//      /cmds/mortal/_bury
//      created by Seeker

#include <std.h>

inherit DAEMON;

int cmd_bury(string str) {
  object ob;
 
    if (!str || str=="")
      {
       notify_fail("Bury what?\n");
       return 0;
      }
  
    ob = present(str, this_player());

    if (!ob)
      {
       write("You dont have "+str+".");
       return 1;
      }
     if (ob->bury(str))
       return 1;
    write("You dig a small hole and bury "+ob->query_short());
    message("info", this_player()->query_cap_name()+" digs a small hole and buries "+ob->query_short(), environment(this_player()), this_player());
    ob->remove();
    return 1;
}

void help() {
    write("Syntax: <bury [item]>\n\n"
    "Burys un-wanted items. If you dont need an item bury it "
    "instead of dropping it. ");
    
}
