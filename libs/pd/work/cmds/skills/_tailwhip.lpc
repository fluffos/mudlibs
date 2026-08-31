// tailspear..  by Nightshade
// renamed to tailwhip by Nulvect

#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
int abil();

string type() { return "attack"; }

int cmd_tailwhip(string str) { 
  int attack;
  object ob;

  if (!abil()) {
    write("What?\n");
    return 1;
  }
  if(!str)
    ob = (object)this_player()->query_current_attacker();
  else {
    ob = present(str, environment(this_player()));
    if(!ob) ob = parse_objects(environment(this_player()), str);
  }
  if(!ob || !living(ob)) {
    notify_fail("You do not see that here.\n");
    return 0;
  }
  if (ob==this_player())
    return notify_fail("You are an idiot.\n");
  if(this_player()->query_ghost()) {
    notify_fail("You are a ghost.");
    return 0;
  }
  if (this_player()->query_busy()){
    write("You are busy.");
    return 1;
  }

  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }
  if(environment(this_player())->query_property("no attack")) {
    notify_fail("Greater powers prevent your malice.\n");
    return 0;
  }
  if((int)this_player()->query_sp() < 20) {
    notify_fail("You are too tired.\n");
    return 0;
  }
  this_player()->set_disable();
  attack = BALANCE3_D->get_damage( this_player(), ob, 1, ({ "attack", "tail", "tail" }),
   ({ "dexterity", "strength" }) );
  if (attack < 10) {
    write("You try to lash your opponent but miss.");
    tell_room(environment(this_player()), this_player()->query_cap_name()+
     "tries to lash "+ob->query_cap_name()+" but misses!", ({ ob, this_player() }));
    return 1;
  }
  write("You lash "+ob->query_cap_name()+" with your tail!\n");
  tell_room(environment(this_player()), this_player()->query_cap_name()+
   " lashes "+(string)ob->query_cap_name() + " with their tail!\n", ({ob, this_player()}));
  tell_object(ob, this_player()->query_cap_name()+" lashes you with their tail!\n");
  this_player()->add_skill_points("attack", attack/40);
  this_player()->add_skill_points("tail", attack/20);
  this_player()->add_sp(-(BALANCE3_D->get_cost(attack, 1, "sp")));
  ob->do_damage("target", attack, this_player()->query_unarmed_damage_type() | DAMAGE_SLASH,
    this_player()->query_unarmed_damage_flags(), this_player() );

  return 1;
}

void help() {
  write("Syntax: <tailwhip [living]>\n\n"
   "The dragon can lash out with the tip of its tail, whipping its victim badly.");
}

int abil() {
  object r;
  r = this_player();
  if (!r) return 0;
  if (r->query_race() != "dragon") return 0;
  if (r->query_level() < 4) return 0;
  return 1;
}
