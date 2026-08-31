// Seeker 01/01/2002

#include <std.h>
inherit DAEMON;

int abil();

mapping disguised = ([]);

int cmd_disguise(string cmd)
{
 object ob;
 string tmp;

 if (!abil()) return 0;
 if (!cmd || cmd == "") return notify_fail("disguise as what?\n");
 if (sscanf(cmd, "as %s", tmp)==1) cmd = tmp;
 if (disguised[this_player()->query_name()]) 
     return notify_fail("You are already being disguised.\n");
 if (this_player()->query_sp() < 50)
    return notify_fail("You are too tired to try to disguise yourself.\n");
 if (!(ob = present(cmd, environment(this_player()))))
     return notify_fail("You dont see "+a_or_an(cmd)+" "+cmd+" around here.\n");
 if (!ob->is_living()) return notify_fail("You cannot disguise youself as inanimate things.\n");
 if (wizardp(ob)) return notify_fail("You dare not impersonate an Immortal.\n");
 if (this_player()->query_skill("stealth") < 100 + random(50)) {
   this_player()->add_sp(-20);
   return notify_fail("You fail to disguise yourself.\n");
 }
 disguised[this_player()->query_name()] = ob->query_short();
 call_out("remove_disguise", this_player()->query_skill("stealth")-random(15),  this_player());
 this_player()->set_disquised_short(ob->query_short());
 this_player()->add_sp(-50);
 write("You slyly disguise yourself as "+capitalize(ob->query_short()));
 return 1;
  
}

int remove_disguise(object ob) {
 map_delete(disguised, ob->query_name());
 if (ob) ob->remove_disquised_short();
 if (ob) message("info", "Your disguise fades away.", ob);
}

int abil() {
 if (this_player()->query_class()!="rogue") return 0;
 if (this_player()->query_level() < 20)     return 0;
 if (this_player()->query_skill("stealth") < 100) return 0;
 return 1;
}

int help() {
 write("Syntax: <disguise (as) [who]>\n\n"
       "Allows you to disguise yourself as any living thing that is "
       "currently in the room with you.");
}
