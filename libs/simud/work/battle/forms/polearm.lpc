#include <form.h>
#include <battle.h>

string query_name() { return "polearm"; }

string * query_weapon_types() { return ({"polearm"}); }

string query_action_desc(string name) {
  switch (name) {
    case "thrust":      return "Stab the enemy with your polearm.";
    case "slash":    return "A horizontal slash.";
    case "dodge":    return "Avoid an attack.";
    case "parry":    return "Block attack with your weapon.";
  }
  return "No such action.";
}

string *query_default_actions()
{
   return ({"thrust","slash","dodge","parry"});
}

string *query_actions()
{
   return ({"thrust","slash","dodge","parry"});
}

string *query_reactions()
{
   return ({"dodge","parry"});
}

string query_change_message() {
  return "~Name ~verbtwirl ~poss polearm in ~poss hands menacingly.";
}

string on_attack( object target, object actor, mapping wc ) {
  if ( target->query_reaction_enabled("parry") )
    return "/battle/reactions/parry";
  else if ( target->query_reaction_enabled("dodge") )
    return "/battle/reactions/dodge";
  else
    return 0;
}
