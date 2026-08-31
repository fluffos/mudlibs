//     /bin/user/_swipe.c
//     Nightshade

#include <std.h> 
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
int abil(); 
string type() { return "attack"; }
int cmd_swipe(string str) {
  int attack, total;
  object ob;
  if (!abil())
    return 0;
  if(!str)
    ob = (object)this_player()->query_current_attacker();
  else {
    ob = present(str, environment(this_player()));
    if(!ob) ob = parse_objects(environment(this_player()), str);
  }
  if(!ob || !living(ob)) {
    notify_fail("That is not here.\n");
    return 0;
  }
  if(ob == this_player())
    return notify_fail("Why would you want to do a thing like that?\n");
  if(this_player()->query_ghost()) {
    notify_fail("You're a ghost.\n");
    return 0;
  }
  if (this_player()->query_busy()) {
    return notify_fail("You are busy.");
  }
  if(environment(this_player())->query_property("no attack")) {
    notify_fail("You cannot do that here.\n");
    return 0;
  }
  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }
  if((int)this_player()->query_sp() < 30) {
    notify_fail("You are too tired.\n");
    return 0;
  }
  this_player()->set_disable();
  if (ob->query_stats("constitution")+ob->query_skill("defense")/2 > this_player()->query_skill("melee")/2+this_player()->query_stats("strength")*2+this_player()->query_skill("attack")/2) {
    write("You swipe into the air, but miss "+ob->query_cap_name()+".");
    tell_room(environment(this_player()), this_player()->query_cap_name()+ " swipes at the air, missing "+ob->query_cap_name()+".", ({ ob, this_player() }));
    message("info", this_player()->query_cap_name()+" swipes his claws at you, but misses!", ob);
    return 1;
  }

  write("You swipe "+ob->query_cap_name()+"!\n");
  attack = BALANCE3_D->get_damage( this_player(), ob, 4, ({ "melee", "attack" }),
   ({ "strength" }), ({ "strength" }) );
  tell_room(environment(this_player()), this_player()->query_cap_name()+ " swipes "+(string)ob->query_cap_name() + " with "+possessive(this_player())+" claws.\n", ({ob, this_player()}));
  tell_object(ob, this_player()->query_cap_name()+" swipes you with "+possessive(this_player())+" claws!\n");
  this_player()->add_skill_points("attack", attack/30);
  this_player()->add_sp(-BALANCE3_D->get_cost(attack, 4, "sp"));
  ob->do_damage("target", attack, this_player()->query_unarmed_damage_type() | DAMAGE_PIERCE,
    this_player()->query_unarmed_damage_flags(), this_player() );

  return 1;
}
void help() {
  write("Syntax: <swipe [(living)]>\n\n"
   "Some clawed races are able to swipe their claws in a large arc, causing much damage.");
}
int abil() {
  if (!this_player()->query("bear")) return 0;
  return 1;
}
