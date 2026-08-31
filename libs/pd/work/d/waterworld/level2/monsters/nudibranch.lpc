#include <std.h>
#include <waterworld.h>

inherit MONSTER;


object target;

void create() {
  ::create();

  set_name("nudibranch");
  set_id(({"nudibranch","sea slug","slug"}));
  set_short("a nudibranch munching on the sponge");
  set_long("The nudibranch, or sea slug, comes in a VAST variety of colours and shapes."
   " There are well over 2,000 species of nudibranchs."
   " The nudibranchs are one of the few predators of the aquatic sponges."
   " In fact, they actually use the poisons from the sponges for defense.");
  set_race("nudibranch");
  set_level(15+(random(10)));
  set_class("fighter");
  set_subclass("ranger");
  set_body_type("worm");
  add_action("slime","slime");
  add_action("spit","spit");
  set_spells(({"slime","spit"}));
  set_spell_chance(90);

  // attack functions

}
int slime() {
  target = this_object()->query_current_attacker();

  tell_object(target,"The nudibranch inches across your chest leaving a trail of poisonous %^GREEN%^slime%^RESET%^ behind.");
  tell_object(target,"The poison seeps into your skin!");
  tell_room(environment(this_object()),target->query_cap_name()+" has been %^GREEN%^SLIMED%^RESET%^ by the nudibranch!",target);
  target->add_poisoning(random(random(15)));
  target->damage(random(10)+random(10)+random(10));
  return 1;
}
int spit() {
  target=this_object()->query_current_attacker();
  tell_object(target,"The nudibranch spits %^GREEN%^poisonous slime%^RESET%^ in your face!");
  tell_room(environment(this_object()),"The nudibrach spits %^GREEN%^SLIME%^RESET%^ on the face of "+target->query_cap_name()+"!",target);
  target->add_poisoning(random(random(15)));
  target->damage(random(10)+random(10)+random(10));
  return 1;
}
