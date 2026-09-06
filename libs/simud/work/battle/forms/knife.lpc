// Added speed practice  -- Zarylse [2004-01-30]

#include <form.h>
#include <battle.h>

string query_name() { return "knife"; }

string * query_weapon_types() { return ({"knife","dagger"}); }

string query_action_desc(string name) {
  switch (name) {
    case "slash":    return "Basic attack.";
    case "dodge":    return "Sidestep an attack.";
  }
  return "No such action.";
}

string * query_default_actions() {
   return ({ "slash", "dodge" });
}

string * query_actions() {
   return ({ "slash", "dodge" });
}

string *query_reactions() {
   return ({ "dodge" });
}

string query_change_message() {
  return "~Name ~verbflip ~poss knife around in ~poss hand.";
}

string on_attack( object target, object actor, mapping wc ) {
  target->practice_stat("spd");
  if ( target->query_action_enabled("dodge") &&
       random(100) < 50 )
    return "/battle/reactions/dodge";
  else
    return 0;
}
