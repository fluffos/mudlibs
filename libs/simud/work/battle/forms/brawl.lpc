#include <form.h>
#include <battle.h>

string query_name() { return "brawl"; }

string query_action_desc(string name) {
  switch (name) {
    case "punch":    return "Quick, weak, attack.";
    case "kick":     return "Stronger than punch, but slightly slower.";
    case "headbutt": return "Stronger than kick, but slower.";
    case "bite":     return "Edged damage.";
    case "uppercut": return "Stronger than punch, chance of stunning enemy.";
    case "dodge":    return "Avoid attack.";
    case "shove":    return "Counter when damage is taken.";
    case "throw":    return "Counter when enemy attack misses. Stun enemy.";
    case "bash":     return "Powerful punching attack, but tends to throw you off balance.";
  }
  return "No such action.";
}

string *query_default_actions() {
   return  ({ "punch", "kick", "headbutt", "dodge", "shove" });
}

string *query_actions() {
   return  ({ "punch", "kick", "headbutt", "bite", "uppercut", "bash", "dodge", "shove", "throw" });
}

string *query_reactions() {
   return  ({ "dodge", "shove", "throw" });
}

string query_change_message() {
  return "~Name ~verbput up ~poss fists and ~verbget ready to brawl.";
}

string on_attack( object target, object actor, mapping wc ) {
  if ( target->query_action_enabled("shove") &&
       random(100) < (3*target->query_speed()+
                      2*target->query_form_level("brawl")) )
    return "/battle/reactions/shove";
  else if ( target->query_action_enabled("dodge") &&
            random(100) < 50 )
    return "/battle/reactions/dodge";
  else
    return 0;
}

string on_miss( object target, object actor, mapping wc ) {
  if ( target->query_form_level("brawl") >= 3 &&
       target->query_action_enabled("throw") &&
       target->skill_check("combat.grappling", actor->query_skill("combat.dodge")))
    return "/battle/reactions/throw";
  else
    return 0;
}
