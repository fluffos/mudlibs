#include <form.h>
#include <battle.h>

string query_name() { return "dragon"; }

string *query_default_actions()
{
    return ({"dragon_claw","dragon_bite","dragon_breath","dragon_tail"});
}

string *query_actions()
{
    return ({"dragon_claw","dragon_bite","dragon_tail","dragon_wing","dragon_breath"});
}

string *query_reactions()
{
    return ({"dragon_hide"});
}
string query_action_desc(string name) {
  switch (name) {
    case "dragon_claw":   return "Execute up to 4 claw attacks";
    case "dragon_bite":   return "Bite that burns";
    case "dragon_tail":   return "Smash victim with tail";
    case "dragon_wing":   return "Beat target down with wings";
    case "dragon_breath": return "Breathe flame";
    case "dragon_hide":   return "Dragon's hide is remarkably tough";
  }
  return "No such action.";
}

string query_change_message() {
  return "~Name ~verbbare ~poss teeth and ~verblet out a mighty ROAR!.";
}

string on_attack( object target, object actor, mapping wc ) {
  return "/battle/reactions/dragon_hide";
}
