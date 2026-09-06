#include <form.h>
#include <battle.h>

string query_name() { return "archery"; }

string * query_weapon_types() { return ({"bow", "crossbow"}); }

varargs string *query_allowed_actions(object who) {

  return ({/*"punch","kick",*/"shoot"});
}

string query_action_desc(string name) {
  switch (name) {
    case "shoot":    return "Fire an arrow into your enemy.";
    /*case "punch":    return "Weak, while holding a bow.";
    case "kick":     return "Like it sounds, but weaker than with your hands free.";*/
    case "dodge":    return "Avoid attack.";
  }
  return "No such action.";
}

varargs string *query_allowed_reactions(object who) {
    return ({"dodge"});
}

int query_num_attitudes() { return 2; }

string *query_attitude_names() { return ({"attack","counter"}); }

int *query_attitude_bases() { return ({0,0}); }

int *query_attitude_caps() { return ({7,3}); }

string query_change_message() {
  return "~Name ~verbheft ~poss bow and ~verbprepare to fire it.";
}

string on_attack( object target, object actor, mapping wc ) {
  if ( target->query_reaction_enabled("shove") &&
       random(100) < (3*target->query_speed()+
                      2*target->query_form_level("brawl")) )
    return "/battle/reactions/shove";
  else if ( target->query_reaction_enabled("dodge") &&
            random(100) < 50 )
    return "/battle/reactions/dodge";
  else
    return 0;
}

string on_miss( object target, object actor, mapping wc ) {
  if ( target->query_form_level("brawl") >= 3 &&
       target->query_reaction_enabled("throw") &&
       random(100) < (2*target->query_speed()+
                      2*target->query_form_level("brawl")+
                      target->query_skill("combat.grappling")) )
    return "/battle/reactions/throw";
  else
    return 0;
}

