inherit "/std/effect_shadow";
void add_effect(string eff, mixed arg){
 if(member_array("blind", explode( eff->query_classification(), "."))
      != -1 && (random(3+ (player->query_skill_bonus("other.perception")/200))>1)){
  tell_object(player, "A bright flash of light "
     "seems to reflect off your eyes.\n");
  if(environment(player))
   tell_room(environment(player), capitalize(player->query_short())+
      " looks momentarially dazed, but recovers.\n", ({player}));
  return;
 }
 player->add_effect(eff, arg);
}
int check_dark(int light){
 return player->check_dark((60*light)/100);
}
int query_skill_bonus(string skill, int true){
 if(skill == "other.perception" && !true)
  return((80*(player->query_skill_bonus(skill)))/100);
 return player->query_skill_bonus(skill);
}
int add_skill_level(string skill, int level, int xp){
 if(!xp && skill == "other.perception")
  return 0;
 return player->add_skill_level(skill, level, xp);
}