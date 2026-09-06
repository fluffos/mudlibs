#include <form.h>
#include <battle.h>

string query_name() { return "whip"; }

string * query_weapon_types() { return ({"whip"}); }

string query_action_desc(string name) {
  switch (name) {
    case "whip":      return "A basic attack.";
    case "lacerate":    return "A really strong whip strike.";
    case "dodge":    return "Avoid an attack.";
    case "parry":    return "Catch the enemy's weapon in your whip, deflecting it.";
  }
  return "No such action.";
}

string *query_default_actions()
{
   return ({"whip","lacerate","parry","dodge"});
}

string *query_actions()
{
   return ({"whip","lacerate"});
}

string *query_reactions()
{
   return ({"dodge","parry"});
}

string query_change_message() {
  return "~Name ~verbcrack ~poss whip, getting a feel for it.";
}

string on_attack( object target, object actor, mapping wc ) {
  if ( target->query_reaction_enabled("parry") )
    return "/battle/reactions/parry";
  else if ( target->query_reaction_enabled("dodge") )
    return "/battle/reactions/dodge";
  else
    return 0;
}
