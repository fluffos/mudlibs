// Chronos made another fun weapon.
// %chance for special stun attack = your charisma.  Not too likely. ;)
// (04-??-98) Written by Chronos.
// (05-11-98) Chronos makes it not stun people over level 50. 
#include <mudlib.h>

inherit WEAPON;

void create() {
   set_weapon_type("mace") ;
  set("damage", ({ 1, 4 }) ) ;
  set("id", ({ "sceptre", "jester sceptre" }) ) ;
  set("author", "Chronos") ;
  set("short", "the Jester Sceptre") ;
	set("long", @LONG
A ridiculous-looking sceptre with the head of jester carved into
the head.
LONG
	);
	set("value", 3500);
  set("name", "Jester Sceptre") ;
  set_verbs( ({ "swing at", "attack", "assault" }) ) ;
  set("hit_func", "blahdy blah") ;
}

int hit_func(object victim, int damage) {
  object *inv ;
  int i ;
  if (!victim) return damage ;
  if (!damage) return 0 ;
  if ((int)victim->query_level()>50) {
    return damage ; 
  }
  if (random(100)+1 < environment(TO)->query("stat/charisma")) {
  inv = all_inventory(environment(environment(TO))) ;
  if (!inv) return damage ;
  for(i=0;i<sizeof(inv);i++) {
    if (inv[i]==environment(TO)) 
     {
    message("combat", iwrap("The Jester Sceptre suddenly comes to life in your hands and spits a strange twinkling dust all over "+victim->query("cap_name")+"!"), inv[i]) ;
   tell_object(environment(TO), victim->query("cap_name")+" begins laughing uncontrollably!\n") ;
    continue ;
    }
  if (inv[i]==victim) {
   message("combat", wrap("The Jester Sceptre suddenly comes to life in "+environment(TO)->query("cap_name")+"'s hands and spits a strange twinkling dust all over you!"), victim);
   tell_object(victim, "You suddenly begin to laugh uncontrollably!\n");
   continue ;
   }
  message("combat", wrap("The Jester Sceptre suddenly comes to life in "+environment(TO)->query("cap_name")+"'s hands and spits a strange twinkling dust all over "+victim->query("cap_name")+"!"), inv[i]) ;
   tell_object(inv[i], victim->query("cap_name") + " begins laughing uncontrollably!\n");
  continue ;
  }
  }
  return damage ;
}

