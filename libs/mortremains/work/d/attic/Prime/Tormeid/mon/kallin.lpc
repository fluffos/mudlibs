#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create(){
  ::create();
  set("short", "Kallin") ;
  set("spellcaster", 1) ;
  set("long", @ENDLONG
Kallin looks like the stereotypical elf with the slender features,
high cheekbones and pointed ears.  His fine features are offset
by piercing green eyes and long brown hair.
ENDLONG
  );
  set("id", ({ "elf", "kallin" }) ) ;
  set("gender", "male");
  set("race", "elf");
  set_name("Kallin") ;
  credit(random(300)+ 102) ;
  set_level(30) ;
  set_skill("Evasion", 2, "dexterity") ;
  set_skill("Awareness", 2, "dexterity") ;
  set_skill("Clubbing Weapons", 2, "strength") ;
  set("stat", ([
    "strength" : 13 , "dexterity" : 16,
    "constitution" : 17, "intelligence" : 17,
   "wisdom" : 9, "charisma" : 10 
  ]) ) ;
  set_alignment("cn") ;
  set("damage", ({ 2, 4 }) );
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack" }) );
  wear(ARM(protring3), "ring")  ;
  wear(ARM(elven_chain), "chain") ;
  wear(ARM(displacercloak), "cloak") ;
  wear(ARM(boots_of_speed), "boots") ;
  arm(WEP(warstaff), "staff") ;
  set("special", 1) ;
}

void special_attack() {
  object victim;
  string v_msg, msg, name, damage_type ;
  int damage ;
  if (random(10) < 5) return ;
  victim = query_current_attacker() ;
  if (!victim) return ;
  if (environment(TO) != environment(victim)) return ;
  name = victim->query("cap_name") ;
  message("combat", "Kallin casts a spell!\n", environment(TO), ({ TO }));
  tell_object(TO, "You cast a spell!\n") ;
  if (victim->query_skill("Evasion")) {
    if (random(25)+4 < (int)victim->query("stat/dexterity")) {
      tell_object(victim, "You manage to dodge the spell's effect!\n") ;
      message("combat", victim->query("cap_name") + " manages to dodge the spell's effects!\n", environment(TO), ({ victim }) ) ;
    return ;
    } else {
      tell_object(victim, "You try to evade the spell, but can't!\n");
    }
  }
  switch(random(8)) {
  case 1: v_msg = "A gout of fire shoots up from the ground, burning you!";
          msg = "A gout of fire shoots up from the ground, burning "+name+"!";
          damage_type = "fire";
          damage = random(20) + 40 ;
          break ;
  case 2: v_msg = "Electricity crackles through your body, making you twitch and spasm!";
          msg = "Electricity courses through "+TPN+"'s body!";
          damage_type = "electricity";                        
          damage = random(20) + 20 ;
          break ;
  case 3: v_msg = "You feel a great pressure on your heart!";
          msg = name+" suddenly grimaces in agony!";
    damage_type = "force" ;
          damage = random(50) + 50 ;
          break ;
  case 4: v_msg = "Lightning shoots from Kallin's fingers, electrocuting you!";
          msg = "Lightning shoots into "+name+"'s body!";
          damage_type = "electricity";
          damage = random(20) + 30 ;
          break ;
  case 5: v_msg = "Pain suddenly wracks your body!";
          msg = name+" suddenly convulses in agony!";
     damage_type = "force" ;
          damage = random(20) + 20 ;
          break ;
  default: v_msg = "Magic missiles shoot into your body!";
          msg = "Magic missiles shoot into "+name+"'s body!";
          damage_type = "force" ;
          damage = random(20) + 10 ;
          break ;
  }
  message("combat", v_msg + "\n", victim) ;
  message("combat", msg+"\n", environment(TO), ({ victim }) ) ;
  victim->receive_damage(damage, damage_type);
  return ;
}
