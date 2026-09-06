#include <form.h>
#include <battle.h>

string query_name() { return "bludgeon"; }

string * query_weapon_types() { return ({"hammer","mace"}); }

string query_action_desc(string name) {
  switch (name) {
    case "hit":      return "Basic thump.";
    case "pound":    return "Strong thump.";
    case "bash":     return "Ram with shoulder/shield. Chance of stunning.";
    case "smash":    return "Freaking hard thump.";
    case "dodge":    return "Avoid an attack.";
    case "block":    return "Use a shield.";
    case "parry":    return "Block attack with your weapon.";
  }
  return "No such action.";
}

string *query_default_actions()
{
   return ({ "hit", "pound", "bash", "smash", "block", "parry"});
}

string *query_actions()
{
   return ({ "hit", "pound", "bash", "smash"});
}

string *query_reactions()
{
   return ({ "block", "parry"});
}

string query_change_message()
{
   return "~Name ~verbget ready to thump heads.";
}

string on_attack( object target, object actor, mapping wc )
{
   if ( target->query_reaction_enabled("block") )
      return "/battle/reactions/block";
   else if ( target->query_reaction_enabled("parry") )
      return "/battle/reactions/parry";
   else
      return 0;
}
