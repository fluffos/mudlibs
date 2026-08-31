#include <std.h>
inherit DAEMON;

int spell();

int cmd_stop(string str) {
   object ob;
   if (!str) return notify_fail("Stop what?\n");
   if (!(ob = present(str, environment(this_player()))))
     return notify_fail("You don't see that here.\n");
   if (ob->query_hp() >= 5) return notify_fail("No.\n");
   ob->set_paralyzed(99999);
   write("You stop "+ob->query_cap_name()+".");
   say(this_player()->query_cap_name()+" stops "+ob->query_cap_name()+
     ".", this_player());
   return 1;
}

void help() {
write("Syntax <stop [monster]>
This spell is granted by the gods to all mortals free of cost.
Some monsters have a 'wimpy' to them.. They run away when they
should be dying. This command paralyzes those monsters so you can
kill them.");
}

int spell() { return 0; }
