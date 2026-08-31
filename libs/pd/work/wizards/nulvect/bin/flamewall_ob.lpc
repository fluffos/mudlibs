#include <std.h>
#include <daemons.h>

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
  set_id(({"wall","flame","flamewall","flames","ring","ring of flames","fire","flamewallobj"}));
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

  if (!owner) remove();
  
  if (present(owner)) {
    owner->clean_up_attackers();
    burnthem=owner->query_attackers();
    i=0;
    foreach (object tgt in burnthem) {
      int dmg, cost;
      if (!tgt) continue;
      dmg = BALANCE3_D->get_damage(owner, tgt, 2,
          ({"pyromancy", "pyromancy", "magic defense"}),
          ({"intelligence"}) );
      dmg = dmg*3/10;
      cost = dmg/5;
      owner->add_mp(-(cost+random(cost/10)));
      tgt->do_damage(dmg);
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
  else if (!(rounds%5))
    message("magic","%^ORANGE%^The flames burn and crackle.%^RESET%^",environment());
  
  if (!(--rounds) || owner->query_mp() < 100) {
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
  if (present(str, environment(tp)) != this_object())
    return 0;
  message("magic","You extinguish the wall of flames, absorbing a bit of their power.",tp);
  message("magic",tp->query_cap_name()+" extinguishes the wall of flames.",
    environment(), tp);
  tp->add_mp(rounds*25);
  remove_call_out("next_round");
  this_object()->remove();
  return 1;
}

string get_short() {
  string s;
  s="%^RED%^a wall of flame";
  if (owner) s+=" that encircles "+owner->query_cap_name();
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
