#include <form.h>
#include <battle.h>

string query_name() { return "axe"; }

string * query_weapon_types() { return ({"axe"}); }

string query_action_desc(string name) {
  switch (name) {
    case "chop":     return "Basic chop.";
    case "hack":     return "Strong chop.";
    case "hew":      return "Freaking hard hack.";
    case "bash":     return "Ram with shoulder/shield. Chance of stunning.";
    case "block":    return "Use a shield.";
    case "dodge":    return "Avoid an attack.";
  }
  return "No such action.";
}

string *query_default_actions() {
   return ({ "chop", "hack", "block" });
}

string *query_actions() {
   return ({ "chop", "hack", "bash", "hew", "block", "dodge" });
}

string *query_reactions() {
   return ({ "block", "dodge" });
}


string query_change_message() {
  return "~Name ~verbget ready to hack something to bits.";
}

string on_attack( object target, object actor, mapping wc ) {
  if ( target->query_reaction_enabled("block") && random(100) < 50 )
    return "/battle/reactions/block";
  else if ( target->query_action_enabled("dodge") )
    return "/battle/reactions/dodge";
  else
    return 0;
}
