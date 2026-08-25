#include <std.h>

inherit DAEMON;

int cmd_wizheal(string str) {
    object ob;

    if(!str) ob = this_player();
    else ob = find_living(str);
    if(!ob) {
        notify_fail(capitalize(str) +": not found\n");
        return 0;
    }
    ob->heal((int)ob->query_max_hp()+ ((int)ob->query_max_mp()));
    if(!creatorp(ob)) log_file("illegal", this_player()->query_name() +
      " wizhealed " + ob->query_name() + " at " + ctime(time())+".\n");
    write("You heal "+ob->query_cap_name()+".\n");
    if(ob != this_player()) tell_object(ob, "You are healed by "+this_player()->query_cap_name()+".\n");
    return 1;
}

int help()
{
  write( @EndText
Syntax: wizheal <user>
Effect: Puts <user> back on full hit points.
Warning: Do not heal players unless you are a law arch.
EndText
  );
  return 1;
}
