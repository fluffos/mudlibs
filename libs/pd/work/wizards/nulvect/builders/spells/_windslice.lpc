
#include <std.h>

#define BAIL(s) return notify_fail(s);

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && 
      tp->query_subclass() == "scout" &&
      tp->query_level() >= 12 &&
      tp->query_skill("attack") >= 50 &&
      tp->query_skill("agility") >= 50)
    return 1;

  return 0;
}

int is_knife(object *blah) { return (blah->query_type() == "knife" ? 1 : 0); }

int cmd_windslice(string str) {
  object tp=this_player();
  int i, s, l, hits, dex, att, agil, def, dam, cost;
  object *dag, *enemies, check, en;

  if (!abil()) return 0;

  if (tp->query_disable()) return 1;

  if (!tp->query_current_attacker() && !sizeof(tp->query_attackers()))
    BAIL("You are not in combat.\n");

  if (!sizeof(dag=filter(tp->query_wielded(),"is_knife",this_object())))
    BAIL("You must use a knife for that.\n");

  dex=tp->query_stats("dexterity");
  att=tp->query_skill("attack");
  agil=tp->query_skill("agility");
  l=tp->query_level();

  dam= dex*5/4 + att*2/3 + agil;
  cost=dam/6;

  if (tp->query_sp() < cost)
    BAIL("Not enough stamina.\n"); 

  if (l < 20) hits=1;
  else if (l < 30) hits=2;
  else hits=3;

  en=tp->query_attackers();
  s=sizeof(en);
  enemies=({});
  for (i=0;i<s;i++) {
    if (check=en[i])
      enemies+=({check});
    if (sizeof(enemies) > 1)
      break;
  }
  
  if (hits > 1 && sizeof(enemies) == 2 && sizeof(dag) > 1) {
    message("combat","You dash between "+enemies[0]->query_cap_name()+
      " and "+enemies[1]->query_cap_name()+
      ", slicing them with your daggers!",tp);
    message("combat",tp->query_cap_name()+" dashes between "+
      enemies[0]->query_cap_name()+" and "+enemies[1]->query_cap_name()+
      ", slicing them badly!",environment(tp), ({tp,enemies[0],enemies[1]}));
    message("combat",tp->query_cape_name()+" dashes between you and "+
      enemies[0]->query_cap_name()+", slicing you both!", enemies[1]);
    message("combat",tp->query_cape_name()+" dashes between you and "+
      enemies[1]->query_cap_name()+", slicing you both!", enemies[0]);

    def=enemies[0]->query_skill("defense")/5;
    def+=enemies[0]->query_skill("agility")/3;
    def+=enemies[0]->query_stats("dexterity")/4;
    enemies[0]->do_damage(enemies[0]->return_target_limb(),(dam-def)*(60+(att/40))/100);

    def=enemies[1]->query_skill("defense")/5;
    def+=enemies[1]->query_skill("agility")/3;
    def+=enemies[1]->query_stats("dexterity")/4;
    enemies[1]->do_damage(enemies[1]->return_target_limb(),(dam-def)*(60+(att/40))/100);

    if (hits == 3) {
      message("combat","%^BOLD%^You quickly spin and slice "+
        enemies[0]->query_cap_name()+" again!%^RESET%^",tp);
      message("combat","%^BOLD%^"+tp->query_cap_name()+" spins and slices "+
        enemies[0]->query_cap_name()+" again!%^RESET%^",
        environment(tp),({tp,enemies[0]}));
      message("combat","%^BOLD%^"+tp->query_cap_name()+" spins and slices you again!",
        enemies[0]);

      cost*=3/2;
      def=enemies[0]->query_skill("agility")/2;
      def+=enemies[0]->query_stats("dexterity")*2;
      enemies[0]->do_damage(enemies[0]->return_target_limb(),dam/2-def);
    }
  }
  else {
    message("combat","You dash past "+enemies[0]->query_cap_name()+
      ", slicing "+enemies[0]->query_objective()+" with your dagger"+
      (sizeof(dag) > 1 ? "s" : "") +"!", tp);
    message("combat",tp->query_cap_name()+" dashes past "+enemies[0]->query_cap_name()+
      ", slicing "+enemies[0]->query_objective()+" badly!",environment(tp),({tp,enemies[0]}));
    message("combat",tp->query_cap_name()+" dashes past and slices you badly!",enemies[0]);

    def=enemies[0]->query_skill("defense")/5;
    def+=enemies[0]->query_skill("agility")/3;
    def+=enemies[0]->query_stats("dexterity")/4;
    enemies[0]->do_damage(enemies[0]->return_target_limb(),dam-def);
  }
  tp->add_sp(-(cost+random(15)));

  return 1;
}

