#include <form.h>
#include <battle.h>

string query_name() { return "swordchucks"; }

string * query_weapon_types() { return ({"swordchucks"}); }

varargs string *query_default_actions()
{
   return ({"swipe","whiplash","dodge","parry"});
}

string query_action_desc(string name) {
  switch (name) {
    case "swipe":    return "Basic attack.";
    case "whiplash":     return "Piercing damage.";
    case "dodge":    return "Sidestep an attack.";
    case "parry":    return "Knock opponents weapon away.";
  }
  return "No such action.";
}

string *query_actions()
{
   return ({"swipe","whiplash"});
}

string *query_reactions()
{
   return ({"dodge","parry"});
}

string query_change_message() {
  return "~Name ~verbbrandish ~poss swordchucks as ~pron ~verbget ready to become a walking blender.";
}

string on_attack( object target, object actor, mapping wc ) {
  if ( target->query_reaction_enabled("dodge") &&
       random(100) < 50 )
    return "/battle/reactions/dodge";
  else if ( target->query_reaction_enabled("parry") )
    return "/battle/reactions/parry";
  else
    return 0;
}
