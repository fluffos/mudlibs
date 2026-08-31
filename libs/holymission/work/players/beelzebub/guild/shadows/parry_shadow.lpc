#define RM "race/master"
#define MAX_ST 40
#define W_PARRY 100    

inherit "/obj/std_shadow";
#include "/players/beelzebub/misc/defs.h"

int stat_dam(object weap) {
  object target;
    
if ((target = me->query_attack()) && random(50) < (5+me->DEX/2)) {
    write("You CRITICALLY HIT "+target->query_name()+"!\n");
    say(me->query_name()+" CRITICALLY HITS "+target->query_name()+"!\n",me,target);
    tell_object(target, me->query_name()+" CRITICALLY HITS you!\n"); 
    return (6 * me->stat_dam(weap));
  }
  return me->stat_dam(weap);
}

varargs mixed hit_player(int dam,int kind,mixed elem) {
  string          name, pname;
  int             dex, dk, enc, i, max, wt;

  dex = me->query_dex() - this_player()->query_dex();
  wt = me->query_weight();          
  enc = wt * 50 / me->query_str();
  name = me->query_name();
  pname = this_player()->query_name();

  if (!kind || kind == 0 || kind==1 || kind == 2 || kind == 6 || kind == 7)
    dk = 0;
  if (dk || dex < 1 || enc > W_PARRY) {
    return me->hit_player(dam, kind);         
  }

  if (! (max = RM->query_max_stat(me->query_race(), 1)) )
    max = MAX_ST;
    
  i = dex * (W_PARRY - enc) / max;
    if (random(100) < i) {                   
    write(name + " parries your attack.\n");
    say(name+" parries the attack of "+pname+".\n",me);
    tell_object(me, "You parry the attack of " + pname + ".\n");
    return 0;
  }

  i = random(100 - i) / 2 + 50;             
  dam = dam * i / 100;
  i = me->hit_player(dam, kind, elem);
  write(me->query_name() +" tried to parry your attack.\n");
  if (i)
    say(me->query_name() +" tried to parry the attack of "+ pname +".\n",me);
    tell_object(me, "You tried to parry the attack of "+ pname +".\n");
  return i;
}

int evade_shadow() {
    return 1;
}

object ninja_object() {
    return this_object();
}        

