#include <std.h>
#include <daemons.h>

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^MAGENTA%^"

inherit OBJECT;

object owner;

void set_owner(object tp);
string get_short();
string get_long();

void create() {
  ::create();
  set_id( ({
    "blades", "blade", "collection of blades", "collection",
    "psiblades", "psiblade", "psi blades", "psi blade",
    "psionic blades", "psionic blade", "collection of psionic blades",
    "collection of psiblades", "collection of psi blades",
    "psiblade_ob",
  }) );
  set_prevent_get("The blades are made of energy!");
  set_short( (: get_short :) );
  set_long( (: get_long :) );
  set_heart_beat(1);
}

void heart_beat() {
  object env = environment();
  object o_env;

  if (!owner || !(o_env = environment(owner)) || !env) {
    set_heart_beat(0);
    return;
  }

  if (o_env != env)
    move(o_env);
}

void set_owner(object tp) {
  owner=tp;
}

string get_short() {
  string s;
  s= COL+"a whirling collection of psionic blades";
  if (owner && present(owner, environment())) s+=" protecting "+owner->query_cap_name();
  s += "%^RESET%^";
  return s;
}

string get_long() {
  string l;
  l="Blades of pure "+COL+"psionic"+RES+" energy.";
  if (owner) {
    l += " They are circling around protecting ";
    if (this_player() && this_player() == owner)
      l+= "you.";
    else
      l+= owner->query_cap_name()+".";
  }
  return l;
}
