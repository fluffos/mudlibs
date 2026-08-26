#include "path.h"
inherit "/std/effect_shadow";
void add_effect(string eff, mixed arg){
 if(member_array("blind", explode( eff->query_classification(), "."))
      != -1 && random(2)){
  tell_object(player, "Your goggles seem to have protected you from "
     "a bright flash of light.\n");
  if(environment(player))
   tell_room(environment(player), capitalize(player->query_short())+
      " looks momentarially dazed, but recovers.\n", ({player}));
  return;
 }
 player->add_effect(eff, arg);
}
int check_dark(int light){
 return player->check_dark((70*light)/100);
}
int query_skill_bonus(string skill, int true){
 if(skill == "other.perception" && (!true))
  return((90*(player->query_skill_bonus(skill)))/100);
 return player->query_skill_bonus(skill,true);
}
void taken_off(object what, string eff)
{
  if (eff != EFFECTS+"goggle_effect")
    player->taken_off(what, eff);
  else {
    remove_this_effect();
  }
}
int add_skill_level(string skill, int level, mixed xp){
 if(!xp && skill == "other.perception")
  return 0;
 return player->add_skill_level(skill, level, xp);
}
