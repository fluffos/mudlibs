//     /bin/user/_faithwing.c
//     A white dragon magic attack
//     Nightshade

#include <std.h> 
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
int spell();

string type() { return "attack"; }

int cmd_faithwing(string str) {

  int attack, total;
  object ob;

  if (!spell())
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

  if(environment(this_player())->query_property("no attack") ||
   environment(this_player())->query_property("no magic")) {
    notify_fail("You cannot do that here.\n");
    return 0;
  }
  if((int)this_player()->query_mp() < 50) {
    notify_fail("Your magical energies are too low.\n");
    return 0;
  }
  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }
  attack = BALANCE3_D->get_damage( this_player(), ob, 3, ({ "magic attack", "faith", "faith", "faith",  "flying" }),
   ({ "wisdom" }), ({ "magic attack", "flying" }) );
  attack = attack + attack/6;
  if (attack < 0)
  {
    write("Your faith has failed you.");
    tell_room(environment(this_player()), this_player()->query_cap_name()+" begins summoning something, but nothing happens.", ({ ob, this_player() }));
    message("info", this_player()->query_cap_name()+" tries to cast a spell on you, but fails.", ob);
    return 1;
  }
  write("Unfurling your wings, you blow a gust of %^BOLD%^%^BLUE%^m%^CYAN%^a%^WHITE%^g%^BLUE%^i%^CYAN%^c%^WHITE%^a%^BLUE%^l%^CYAN%^ a%^WHITE%^i%^BLUE%^r %^RESET%^at "+ob->query_cap_name()+".");
  tell_room(environment(this_player()), this_player()->query_cap_name()+" unfurls  "+possessive(this_player())+" wings and blows a gust of wind towards "+(string)ob->query_cap_name() + ".\n", ({ob, this_player()}));
  tell_object(ob, this_player()->query_cap_name()+" unfurls "+possessive(this_player())+" wings, blowing a gust of %^BOLD%^%^BLUE%^m%^CYAN%^a%^WHITE%^g%^BLUE%^i%^CYAN%^c%^WHITE%^a%^BLUE%^l%^CYAN%^ a%^WHITE%^i%^BLUE%^r %^RESET%^at you!");
  this_player()->add_skill_points("magic attack", attack/20);
  this_player()->add_skill_points("faith", attack/20);
  this_player()->add_mp(-(BALANCE3_D->get_cost(attack, 3, "mp")));
  this_player()->set_magic_round();
  ob->do_damage("all", attack, DAMAGE_FAITH | DAMAGE_HOLY | DAMAGE_AIR, 0, this_player());
  return 1;
}

void help() {
  write("Syntax: <faithwing [living]>\n\n"
   "Faithful dragons can blow a gust of wind imbued with magical\n"
   "energy at a target.\n");
}

int spell() {
  if (this_player()->query_subclass() != "white") return 0;
  if(this_player()->query_level() < 26) return 0;
  if(this_player()->query_skill("faith") < 140) return 0;
  return 1;
}
