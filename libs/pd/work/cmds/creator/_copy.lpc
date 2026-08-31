#include <std.h>
inherit DAEMON;
void help() {
  message("help",
    "Syntax: <copy (-eq) player>\n\n"
    "This sets you to a copy of the given player: race, class, skills, stats, etc.\n"
    "Using the -eq flag will also load a copy of all the items he is carrying."
    , this_player() );
}
int cmd_copy(string str)
{ 
 object ob;
 object *eq;
 int i, flag;
 string tmp, who; int tm;
 mapping skills;
  if (sscanf(str, "-eq %s", who) == 1) flag = 1;
  else who = str;
 if (!who || who=="") return notify_fail("Copy who?\n");
 if (!ob = find_player(who))
   return notify_fail("That player is not on.\n");
 this_player()->set_class(ob->query_class());
 skills = ob->query_skills();
 this_player()->set_subclass(ob->query_subclass());
 this_player()->set_skills(skills);
 this_player()->set_stats("strength",ob->query_stats("strength"));
this_player()->set_stats("dexterity",ob->query_stats("dexterity"));
this_player()->set_stats("constitution", ob->query_stats("constitution"));
this_player()->set_stats("charisma", ob->query_stats("charisma"));
this_player()->set_stats("intelligence", ob->query_stats("intelligence"));
this_player()->set_stats("wisdom", ob->query_stats("wisdom"));
this_player()->set_exp(ob->query_exp());
this_player()->set_level(ob->query_level());
this_player()->set_race(ob->query_race());
this_player()->new_body();
this_player()->set_alignment(ob->query_alignment());
//this_player()->set_guild(ob->query_guild());
this_player()->fix_vital_bonus();
  if (flag) {
    i = sizeof(eq = all_inventory(ob));
    while(i--)
    {
    if (sscanf(file_name(eq[i]), "%s#%d",tmp,tm)==2)
     new(tmp)->move(this_player());
    write(file_name(eq[i]));
    }
  }
 write("Copied "+ob->query_cap_name());
 return 1;
}
