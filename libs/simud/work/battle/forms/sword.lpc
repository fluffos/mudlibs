#include <form.h>
#include <battle.h>

string query_name() { return "sword"; }

string * query_weapon_types() { return ({ "sword" }); }

string query_action_desc(string name) {
  switch (name) {
    case "slash":    return "Basic attack.";
    case "stab":     return "Piercing damage.";
    case "dodge":    return "Sidestep an attack.";
    case "parry":    return "Block attack with your sword.";
  }
  return "No such action.";
}

string *query_default_actions() {
   return ({ "slash", "stab", "dodge", "parry" });
}

string *query_actions() {
   return ({ "slash", "stab", "dodge", "parry" });
}

string *query_reactions() {
   return ({ "dodge", "parry" });
}

string query_change_message() {
  return "~Name ~verbbrandish ~poss sword as ~pron ~verbget ready to slice and dice.";
}

string on_attack( object target, object actor, mapping wc ) {
  if ( target->query_action_enabled("dodge") &&
       random(100) < 50 )
    return "/battle/reactions/dodge";
  else if ( target->query_action_enabled("parry") )
    return "/battle/reactions/parry";
  else
    return 0;
}
