#include <std.h>

inherit ARMOUR;

string *valid_stats = ({ "strength",  "constitution", "dexterity",
                         "charisma", "intelligence", "wisdom" });

mapping areas = ([ "nightshade" : "/d/shadow/rooms/entrance" ]);
void create()
{
 ::create();
 set_name("vip pass");
 set_short("A V.I.P. Pass to Beta-II");
 set_long("This pass allows you to set your stats/skills/level etc. "
          "to test out your area. It it attached to a clip where "
          "you can clip it to clothing.\n"
          "%^CYAN%^(commands):\n"
          "%^BLUE%^%^BOLD%^setstat\nsetskill\nsetlevel\nsetrace\n"
          "goto-area\nhome");
 set_mass(1);
 set_value(1);
 set_ac(1);
 set_type("name tag");
 set_id( ({ "vip pass", "pass" }) );
 set_limbs( ({ "torso" }) );
}

void init()
{
 ::init();
 add_action("f_setstats", "setstat");
 add_action("f_setskills", "setskill"); 
 add_action("f_setlevel", "setlevel");
 add_action("f_setrace", "setrace");
 add_action("f_gohome", "home");
 add_action("f_goto_area", "goto-area");
}

int f_setstats(string str)
{
 string stat;
 int level;
 if (!str || str == "") return notify_fail("setstat [what stat] to [what level]?\n");
 if (sscanf(str, "%s to %d", stat, level)!=2)
   return notify_fail("setstat [which stat] to [what level]\n");
 if (member_array(stat, valid_stats)==-1)
   return notify_fail("setstat: invalid stat\n");
 if (level > 200 || level < 1)
   return notify_fail("setstat: invalid stat level\n"); 
 this_player()->set_stats(stat, level);
 write("setstat: set \""+stat+"\" to "+level+".");
 return 1;
}

int f_setskills(string str)
{
 string skill;
 string *skills;
 int level;
 if (!str || str == "") return notify_fail("setskill [what skill] to [what level]\n"); 
 if (sscanf(str, "%s to %d", skill, level)!=2)
   return notify_fail("setskill [which skill] to [what level]\n");
 skills = keys(this_player()->query_skills());
 if (member_array(skill, skills)==-1)
   return notify_fail("setskill: invalid skill\n");
 if (level > 800 || level < 1)
   return notify_fail("setskill: invalid skill level\n");
 this_player()->set_skill(skill, level);
 write("setskill: set \""+skill+"\" to "+level+".");
 return 1;
}

int f_setlevel(string str)
{
 int level;
 if (!str||str=="") return notify_fail("setlevel to [what level]?\n");
 if (sscanf(str, "to %d", level)!=1) return notify_fail("setlevel to [what level]?\n");
 if (level < 1 || level > 100) return notify_fail("setlevel: invalid level\n");
 this_player()->set_level(level);
 this_player()->fix_vital_bonus();
 write("setlevel: set level to "+level+".");
 return 1;
}
int f_setrace(string str)
{
 int race;
 if (!str||str=="") return notify_fail("setrace to [what race]?\n");
 if (sscanf(str, "to %s", race)!=1) return notify_fail("setrace to [what race]\n");
 if (!"/adm/daemon/race_d"->is_race(race)) return notify_fail("setrace: invalid race\n");
 this_player()->set_race(race);
 this_player()->new_body();
 this_player()->fix_vital_bonus();
 write("setrace: set race to "+race+".");
 return 1;
}


int f_gohome()
{
 write("You are transported back to the V.I.P. hall");
 this_player()->move_player("/d/standard/viphall", "into the shadows");
 return 1;
}

int f_goto_area()
{
 write("You are transported to your area.");
 if (!areas[this_player()->query_name()])
   return notify_fail("Contact an immortal, your area was not found.\n");
 this_player()->move_player(areas[this_player()->query_name()], "into the darkness");
 return 1;
}
