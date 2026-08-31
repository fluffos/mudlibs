// spiffy utility to fix skills

#include <std.h>

inherit DAEMON;

int cmd_fixskills(string str)
{
 object ob;
 mapping sk;
 string *skills;
 int i;

 if (!str || str=="") return notify_fail("Fix who?\n");
 ob = find_player(str);
 if (!ob) return notify_fail("No such player.\n");
 sk = ob->query_skills();
 ob->init_skills(ob->query_class()); 
 skills = keys(sk);
 i = sizeof(skills);
 while(i--)
  {
   if (!skills[i]) continue;
   if (!ob->skill_exists(skills[i])) continue;
   ob->set_skill(skills[i], sk[ skills[i] ]["level"]);
   write("Setting %^BOLD%^"+skills[i]+" at %^RED%^"+sk[ skills[i] ]["level"]+"%^RESET%^");
  }
 write("Done.");
 return 1;
}
