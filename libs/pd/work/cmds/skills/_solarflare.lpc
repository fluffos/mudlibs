//     /bin/user/_solarflare.c
//     A white dragon magic attack
//     Nightshade

#include <std.h> 
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
int spell();

string type() { return "attack"; }

int cmd_solarflare(string str) {

  int attack, total;
  object ob;

  if(!spell())
    return 0;
  if(this_player()->query_ghost()) {
    notify_fail("You cannot do that as a ghost.\n");
    return 0;
  }
  if(!str)
    ob = (object)this_player()->query_current_attacker();
  else
    ob = present(str, environment(this_player()));
  if(!ob || !living(ob)) {
    notify_fail("That is not here.\n");
    return 0;
  }
  if (this_player()->query_busy())
  {
    write("You are off balance.");
    return 1;
  }

  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }
  if(environment(this_player())->query_property("no attack") ||
   environment(this_player())->query_property("no magic")) {
    notify_fail("You cannot do that here.\n");
    return 0;
  }
  if((int)this_player()->query_mp() < 70) {
    notify_fail("Your magical energies are too low.\n");
    return 0;
  }
  attack = BALANCE3_D->get_damage( this_player(), ob, 4, ({ "magic attack", "faith" }),
   ({ "wisdom", "wisdom", "wisdom", "intelligence" }), ({ "faith" }) );
  attack = attack + attack/5;
  if (attack < 0)
  {
    write("You fail to strike your opponent.");
    tell_room(environment(this_player()), this_player()->query_cap_name()+" begins summoning something, but nothing happens.", ({ ob, this_player() }));
    message("info", this_player()->query_cap_name()+" tries to cast a spell on you, but fails.", ob);
    return 1;
  }
  write("You spread your wings to the sky and call forth a %^BOLD%^mighty flare%^RESET%^ that streaks towards your opponent.");
  tell_room(environment(this_player()), this_player()->query_cap_name()+" spreads "+possessive(this_player())+" wings to the sky and a %^BOLD%^mighty flare%^RESET%^ erupts from the sky, heading straight towards "+(string)ob->query_cap_name() + ".\n", ({ob, this_player()}));
  tell_object(ob, this_player()->query_cap_name()+" spreads "+possessive(this_player())+" wings to the sky and a %^BOLD%^mighty flare%^RESET%^ erupts from the sky, heading straight towards you!");
  this_player()->add_skill_points("magic attack", attack/20);
  this_player()->add_skill_points("faith", attack/20);
  this_player()->add_mp(-(BALANCE3_D->get_cost(attack, 4, "mp")));
  this_player()->set_magic_round();
  ob->do_damage("all", attack, DAMAGE_FAITH | DAMAGE_FIRE, 0, this_player());
  return 1;
}

void help() {
  write("Syntax: <solarflare [living]>\n\n"
   "White dragons are able to call forth the powers of goodness, \n"
   "causing them to flare up into a powerful ball of energy.\n");
}

int spell() {
  if (this_player()->query_subclass() != "white") return 0;
  if(this_player()->query_level() < 42) return 0;
  if(this_player()->query_skill("faith") < 140) return 0;
  return 1;
}
