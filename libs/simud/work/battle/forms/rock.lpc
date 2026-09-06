#include <form.h>
#include <battle.h>

string query_name() { return "rock"; }

string * query_weapon_types() { return ({"rock"}); }

string query_action_desc(string name) {
  switch (name) {
    case "hit":      return "Basic whack.";
    case "pound":    return "Strong whack.";
    case "smash":    return "Freaking hard whack.";
    case "dodge":    return "Avoid an attack.";
  }
  return "No such action.";
}

string *query_default_actions()
{
   return ({"hit","pound","smash", "dodge"});
}

string *query_actions()
{
   return ({"hit", "pound", "smash", "dodge"});
}

string *query_reactions()
{
   return ({"dodge"});
}

string query_change_message()
{
   return "~Name ~verblift up a great big rock, grinning menacingly.";
}

string on_attack( object target, object actor, mapping wc ) {
   if ( target->query_reaction_enabled("block") )
      return "/battle/reactions/block";
   else
      return 0;
}
