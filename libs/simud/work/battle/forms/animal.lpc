#include <form.h>
#include <battle.h>

string query_name() { return "animal"; }

string *query_default_actions()
{
    return ({"bite","claw","rend","dodge"});
}

string *query_actions()
{
    return ({"bite","claw","rend","hamstring","throatbite","poisonbite","acidbite","sting","grab"});
}

string *query_reactions()
{
    return ({"dodge","counter"});
}
string query_action_desc(string name) {
  switch (name) {
    case "claw":       return "Basic edged attack. Very fast.";
    case "bite":       return "Stronger than claw. Slower.";
    case "hamstring":  return "Slow enemy down.";
    case "rend":  return "Very strong attack. Causes enemy to start bleeding.";
    case "throatbite": return "Chance of instant kill.";
    case "poisonbite": return "Chance of instant kill.";
    case "acidbite": return "Chance of instant kill.";
    case "dodge":      return "Avoid attack.";
    case "counter":    return "Bite or claw back when attack misses.";
  }
  return "No such action.";
}

string query_change_message() {
  return "~Name ~verbbare ~poss teeth.";
}

string on_attack( object target, object actor, mapping wc ) {
  if ( target->query_action_enabled("combat.dodge") && random(100) < 70 )
    return "/battle/reactions/dodge";
  else
    return 0;
}

string on_miss( object target, object actor, mapping wc ) {
  if ( target->query_action_enabled("counter") &&
       random(100) < (2*target->query_speed()+
                      2*target->query_form_level("animal")+
                      target->query_skill("combat.technique.counter")) )
    return "/battle/reactions/animal-counter";
  else
    return 0;
}
