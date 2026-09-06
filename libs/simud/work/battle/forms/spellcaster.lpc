#include <form.h>
#include <battle.h>

string query_name() { return "spellcaster"; }

string query_action_desc(string name) {
  switch (name) {
    case "bolt":     return "Cast a bolt spell.";
	case "blast":    return "Cast a blast spell.";
	case "beam":     return "Cast a beam spell.";
	case "mana":     return "Use mana spells.";
	case "fire":     return "Use fire spells.";
	case "ice":      return "Use ice spells.";
	case "dark":     return "Use dark spells.";
	case "shock":    return "Use shock spells.";
	case "frost":    return "Use frost spells.";
    case "dodge":    return "Avoid attack.";
	case "counterspell": return "Counter offensive spells.";
  }
  return "No such action.";
}

string *query_default_actions() {
   return  ({ "dodge","bolt","mana" });
}

string *query_actions() {
   return  ({ "bolt", "blast", /*"beam"*/ });
}

string *query_reactions() {
   return  ({ "dodge", "mana", "fire", "ice", "dark", "shock", "frost", /*"counterspell"*/ });
}

string query_change_message() {
  return "~Name ~verbbegin to focus ~poss mental arsenal.";
}

string on_attack( object target, object actor, mapping wc ) {
  if ( target->query_action_enabled("dodge") &&
       target->skill_check("magic.intuition", actor->query_stat("spd")) * 2 )
    return "/battle/reactions/dodge";
  else
    return 0;
}
