#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

inherit OBJECT;

int rounds;
object owner;

void next_round();
void setup(object tp);
int do_extinguish(string str);
string get_short();
string get_long();

void create() {
  ::create();
  set_id(({"wall","flame","flamewall","flames",
           "ring","ring of flames","fire","flamewallobj"}));
  set_prevent_get("It is too hot!");
  set_short( (: get_short :) );
  set_long( (: get_long :) );
}

void init() {
  ::init();
  add_action("do_extinguish","extinguish");
}

void next_round() {
  int i;
  object *burnthem;

  if (!owner) { remove(); return; }
  
  if (present(owner)) {
    owner->add_mp(-(40+random(10)));
    owner->add_magic_protection( ({0, 2, 2}) );
    owner->clean_up_attackers();
    burnthem=owner->query_attackers();
    i=0;
    foreach (object tgt in burnthem) {
      int dmg;
      if (!tgt) continue;
      dmg = BALANCE3_D->get_damage(owner, tgt, 1,
          ({"pyromancy", "pyromancy", "magic defense"}),
          ({"intelligence"}) );
      dmg = dmg*3/10;
      tgt->do_damage("random", dmg, DAMAGE_MAGIC | DAMAGE_FIRE, DAMAGE_NO_SEVER, owner);
      message("magic","%^ORANGE%^The wall of flame around "+owner->query_cap_name()+
        " burns you!%^RESET%^",tgt);
      i++;
    }
    if (i) {
      message("magic","%^ORANGE%^The wall of flame around you burns your enemies!%^RESET%^",owner);
      message("magic","%^ORANGE%^The wall of flame around "+owner->query_cap_name()+" burns "
        +owner->query_possessive()+" enemies!%^RESET%^",environment(), ({owner})+burnthem);
    }
  }
  else
    rounds-=2;
  
  if (--rounds <= 0 || owner->query_mp() < 100) {
    message("magic","%^ORANGE%^The wall of flame burns itself out.%^RESET%^", environment());
    this_object()->remove();
  }
  else
    call_out("next_round", 2);
}

void setup(object tp) {
  owner=tp;
  rounds=  owner->query_skill("pyromancy")/30;
  rounds+= owner->query_skill("magic defense")/25;
  rounds+= 7+random(3);
  next_round();
}

int do_extinguish(string str) {
  object tp=this_player();
  if (tp != owner) return 0;
    if(!str) {
        notify_fail("Extinguish what?\n");
        return 0;
    }
  if (present(str, environment(tp)) != this_object())
    return 0;
  tp->set_disable(1);
  message("magic","You extinguish the wall of flames, absorbing a bit of their power.",tp);
  message("magic",tp->query_cap_name()+" extinguishes the wall of flames.",
    environment(), tp);
  if (rounds > 0) tp->add_mp(rounds*4);
  remove_call_out("next_round");
  this_object()->remove();
  return 1;
}

string get_short() {
  string s;
  s="%^RED%^a wall of flame";
  if (owner && present(owner, environment())) s+=" that encircles "+owner->query_cap_name();
  s += "%^RESET%^";
  return s;
}

string get_long() {
  string l;
  l="A magically hot wall of pure %^RED%^fl%^ORANGE%^a%^RED%^me%^RESET%^.";
  if (owner) {
    l += " It is completely encircling ";
    if (this_player() && this_player() == owner)
      l+= "you. You can <extinguish flamewall> to reclaim some of its energy.";
    else
      l+= owner->query_cap_name()+".";
  }
  return l;
}
