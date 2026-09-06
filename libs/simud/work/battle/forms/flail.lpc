#include <form.h>
#include <battle.h>

string query_name() { return "flail"; }

string * query_weapon_types() { return ({"flail"}); }

string query_action_desc(string name) {
  switch (name) {
    case "flail":      return "Basic attack.";
    case "crush":    return "Strong attack.";
    case "smash":    return "Freaking hard attack.";
    case "dodge":    return "Avoid an attack.";
    case "block":    return "Use a shield.";
    case "parry":    return "Wrap flail around opponents weapon, deflecting it.";
  }
  return "No such action.";
}

string *query_default_actions()
{
   return ({"flail","crush","smash","block","parry"});
}

string *query_actions()
{
   return ({"flail", "crush", "smash"});
}

string *query_reactions()
{
  return ({"block","parry"});
}

string query_change_message()
{
   return "~Name ~verbbrandish ~poss flail.";
}

string on_attack( object target, object actor, mapping wc ) {
  if ( target->query_reaction_enabled("block") )
    return "/battle/reactions/block";
  else if ( target->query_reaction_enabled("parry") )
    return "/battle/reactions/parry";
  else
    return 0;
}
