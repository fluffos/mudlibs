//      /bin/user/_keep.c
//      from Shadowraith
//      Allows players to mark items as kept
//      that they do not want sold when they 
//      type "sell all"

#include <std.h>

int cmd_keep(string str) {
    string name;
    int i;
    object ob, *inv;
    if(!str) {
        inv = all_inventory(this_player());
        if(!inv || !sizeof(inv)) {
          notify_fail("You have nothing in your inventory.\n");
          return 1;
        }
        i = sizeof(inv);
        write("You have the following items marked to keep:\n");
        while(i--) {
          if(inv[i]->query_property("KEEP")) {
            name = inv[i]->query_short();
            write(name);
          }
        }
        return 1;
    }
    if(!(ob = present(str,this_player())))
      notify_fail("You do not have a "+str+" in your possesion.\n");
    if(ob->query_property("KEEP"))
      ob->remove_property("KEEP");
    else
      ob->set_property("KEEP",1);
     write("Ok.\n");
    return 1;
}

void help() {
    write("Syntax: <keep> [item]\n\n"
      "This command is used to toggle items as kept such that when you\n"
      "type 'sell all' in a shop, it will skip the items you have marked\n"
      "as kept.  Type 'keep' alone to list the items you currently have\n"
      "that are marked.\n"
    );
}
