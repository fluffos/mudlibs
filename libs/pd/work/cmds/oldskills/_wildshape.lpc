#include <std.h>
inherit DAEMON;
int spell();
int cmd_wildshape(string str) {
   int i;
   object *weps, ob;
   if(!spell())
     return 0;
   if(str)
     return notify_fail("Syntax: <wildshape>\n");
   if(this_player()->query_current_attacker())
     return notify_fail("You don't have the time to change shape in battle.\n");
   if(this_player()->query_ghost())
     return notify_fail("You need a physical form to change.\n");
   if(this_player()->query_skill("nature") < 200)
     return notify_fail("You are not close enough to nature to change.\n");
   if(!this_player()->query("bear")) {
     if(this_player()->query_mp() < 500)
       return notify_fail("You do not have the magical stamina for such a change.\n");
     weps = this_player()->query_wielded();
     i = sizeof(weps);
     while(i--)
       this_player()->force_me("unwield "+weps[i]->query_id()[0]);
     this_player()->force_me("remove all");
     say(this_player()->query_cap_name()+" morphs into the shape of a bear.");
     this_player()->set("bear", 1);
     this_player()->set_max_hp(to_int(this_player()->query_max_hp() * 1.4));
     this_player()->set_max_mp(0);
     this_player()->add_stat_bonus("strength", 10);
     this_player()->add_stat_bonus("constitution", 7);
     this_player()->add_stat_bonus("intelligence", -10);
     this_player()->add_skill_bonus("melee", this_player()->query_max_skill("melee")*this_player()->query_level()/2 - this_player()->query_skill("melee"));
     this_player()->add_skill_bonus("attack", this_player()->query_skill("nature")/2);
     this_player()->add_skill_bonus("defense", this_player()->query_skill("nature")/3);
     write("Your body morphs and forms the shape of a large bear.");
   }
   else {
     this_player()->set("bear", 0);
     say("A bear morphs into the shape of "+this_player()->query_cap_name()+".");
     this_player()->fix_vital_bonus();
     this_player()->add_stat_bonus("strength", -10);
     this_player()->add_stat_bonus("constitution", -7);
     this_player()->add_stat_bonus("intelligence", 10);
     this_player()->add_skill_bonus("melee", -1*this_player()->query_skill_bonus("melee"));
     this_player()->add_skill_bonus("attack", -1*this_player()->query_skill_bonus("attack"));
     this_player()->add_skill_bonus("defense", -1*this_player()->query_skill_bonus("defense"));
     write("Your body morphs and forms your original body.");
   }
   return 1;
}
void help() {
write("Syntax <wildshape>
  Druids who have become one with nature may take the form of a bear.");
}
int spell() {
  if(this_player()->query_subclass() != "druid") return 0;
  if(this_player()->query_level() < 45) return 0;
  return 1;
}
