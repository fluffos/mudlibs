#include <std.h>

inherit OBJECT;

int rounds, strength;
object owner;

void heart_beat();
void set_owner(object tp);
void set_time(int x);
int do_extinguish(string str);

void create() {
  ::create();
  set_id(({"wall","flame","flamewall","flames","ring","ring of flames","fire","flamewallobj"}));
  set_prevent_get("It is too hot!");
}

void init() {
  ::init();
  add_action("do_extinguish","extinguish");
}

void heart_beat() {
  int i, j, def;
  object *burnthem;
  if (!rounds || owner->query_mp() < 100) {
    message("magic","%^ORANGE%^The wall of flame burns itself out.%^RESET%^", environment());
    this_object()->remove();
    return;
  }
  if (owner && present(owner) && sizeof(burnthem=owner->query_attackers())) {
    for (i=0,j=0; i<sizeof(burnthem); i++) {
      if (!burnthem[i]) continue;
      def=burnthem[i]->query_skill("magic defense");
      burnthem[i]->add_hp(-(strength+random(26)-def*2/3));
      message("magic","%^ORANGE%^The wall of flame around "+owner->query_cap_name()+
        " burns you!%^RESET%^",burnthem[i]);
      j++;
    }
    if (j) {
      message("magic","%^ORANGE%^The wall of flame around you burns your enemies!%^RESET%^",owner);
      message("magic","%^ORANGE%^The wall of flame around "+owner->query_cap_name()+" burns "
        +owner->query_possessive()+" enemies!%^RESET%^",environment(), ({owner})+burnthem);
    }
  }
  else if (!(rounds%5))
    message("magic","%^ORANGE%^The flames burn and crackle.%^RESET%^",environment());
  
  owner->add_mp(-(strength/8));
  rounds--;
  call_out("heart_beat", 2);
}

void set_owner(object tp) {
  owner=tp;
  set_short("%^RED%^a wall of flame that encircles "+owner->query_cap_name()+"%^RESET%^");
  set_long("A magically hot wall of pure %^RED%^fl%^ORANGE%^a%^RED%^me%^RESET%^. "
    "It is completely encircling "+owner->query_cap_name()+".");
}
void set_strength(int x) { strength=x; }
void set_time(int x) { rounds=x; }

int do_extinguish(string str) {
  object tp=this_player();
  if (tp != owner) return 0;
  if (member_array(str,({"flames","flamewall","wall","flame wall","flame"})) == -1)
    return 0;
  message("magic","You extinguish the wall of flames, absorbing a bit of their power.",tp);
  message("magic",tp->query_cap_name()+" extinguishes the wall of flames.",
    environment(), tp);
  tp->add_mp(rounds*25);
  this_object()->remove();
  return 1;
}

