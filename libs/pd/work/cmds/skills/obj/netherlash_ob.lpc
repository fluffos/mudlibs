
#include <std.h>

#define COL "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

inherit WEAPON;

object owner;

void set_owner(object);
object query_owner();
int special_hit(object);
string query_desc();
void enable_special();
void disable_special();

void create() {
  ::create();

  set_properties( ([ "no store" : 1, ]) );
  set_type("flail");
  set_hands(1);
  set_weight(1);
  set_curr_value("gold", 0);

  owner = 0;
  if (clonep(this_object()))
    set_heart_beat(3);
}

void heart_beat() {
  object tp = query_wielded();
  string this = query_desc();

  if (!owner) {
    message("magic", capitalize(this)+" sizzles away.", environment());
    remove();
    return;
  }
  
  if (tp && tp != owner) {
    message("magic", capitalize(this)+" sizzles away, burning you!", tp);
    message("magic", capitalize(this)+" sizzles away, burning "+
                     tp->query_cap_name()+"!", environment(tp), tp);
    tp->add_hp(-(10+random(25)));
    if (tp->query_hp() < 5)
      tp->set_hp(5);
    remove();
    return;
  }

}

void set_owner(object who) { owner = who; };
object query_owner() { return owner; }

string query_desc() {
  return definite_article(strip_color(
    replace_string(query_short(), " (wielded)", "")
  ));
}

void enable_special() { set_hit( (: special_hit :) ); }
void disable_special() { set_hit(0); }

int special_hit(object atk) {
  object tp = query_wielded();
  int chance;
  int dmg = 0;

  if (tp != owner) return 0;

  chance = 90+(tp->query_stats("dexterity")+tp->query_stats("wisdom"))/9;

  if (random(1000) < chance) {
    dmg = (query_wc()+chance)/(3+random(10));
    message("info", COL+capitalize(query_desc())+" sizzles and crackles as it strikes!"+RES,
      environment(tp) );
    atk->add_sp(-(dmg/2));
    atk->add_mp(-(dmg/2));
    atk->add_bleeding(random(dmg/2)+5);
  }

  return dmg;
}

