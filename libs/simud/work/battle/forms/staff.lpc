#include <form.h>
#include <battle.h>

string query_name() { return "staff"; }

string * query_weapon_types() { return ({"staff"}); }

string query_action_desc(string name) {
  switch (name) {
    case "hit":      return "Basic thwack.";
    case "pound":    return "Strong thwack.";
    case "dodge":    return "Avoid an attack.";
    case "parry":    return "Block attack with your weapon.";
  }
  return "No such action.";
}

string *query_default_actions()
{
   return ({"hit","pound","dodge","parry"});
}

string *query_actions()
{
   return ({"hit","pound"});
}

string *query_reactions()
{
   return ({"dodge","parry"});
}

string query_change_message()
{
   return "~Name ~verbget a good grip on ~poss staff, adopting a combative stance.";
}

string on_attack( object target, object actor, mapping wc ) {
  if ( target->query_reaction_enabled("parry") )
    return "/battle/reactions/parry";
  else if ( target->query_reaction_enabled("dodge") )
    return "/battle/reactions/dodge";
  else
    return 0;
}
