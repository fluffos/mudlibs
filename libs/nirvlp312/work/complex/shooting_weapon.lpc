/****************************************************************************
      fire_weapon.c -- written by Alfe, Chameloid and Ugh for Tubmud
****************************************************************************/

// ATTENTION: This file is still in work and will probably still change a lot
// in the nearer future. Please don't use it in your code, yet

#include <combat.h>
#include <event.h>
#include <skilltree.h>
#include <grammar.h>
#include <action.h>
#include <message.h>

inherit "complex/weapon";

mapping ready_ammunition, magazines;
int max_ready_ammunition = 1, max_magazines = 1;
mapping aim;

int
query_max_ready_ammunition()
{
  return max_ready_ammunition;
}

int
query_max_magazines()
{
  return max_magazines;
}

object *
query_ready_ammunition()
{
  return ready_ammunition ? m_indices(m_delete(ready_ammunition,0)) : ({ });
}

object *
query_magazines()
{
  return magazines ? m_indices(m_delete(magazines,0)) : ({ });
}

mixed 
query_aim()
{
  return aim;
}

// for overloading
status
ammunition_space(object what)
{
  return sizeof(query_ready_ammunition()) < query_max_ready_ammunition(); 
}

// for overloading
status
magazine_space(object magazine)
{
  return sizeof(query_magazines()) < query_max_magazines();
}

// this function is for overloading
status
accepts_ammunition(object ammunition)
{
  return 1;
}

// for overloading
status
accepts_magazine(object magazine)
{
  return 1;
}

varargs void
remove_ready_ammunition(mixed ammunition)
{
  if (!ammunition)
    ready_ammunition = 0;
  else if (ready_ammunition)
    if (pointerp(ammunition))
      ready_ammunition -= mkmapping(ammunition);
    else 
      m_delete(ready_ammunition,ammunition);
}

status
make_ready_ammunition(object ammunition)
{
  if (!accepts_ammunition(ammunition))
    return 0;
  if (!ammunition_space(ammunition))
    return 0;
  if (!ready_ammunition)
    ready_ammunition = ([]);
  ready_ammunition += ([ ammunition ]);
  return 1;
}

status
add_magazine(object magazine)
{
  if (!accepts_magazine(magazine))
    return 0;
  if (!magazine_space(magazine))
    return 0;
  if (!magazines)
    magazines = ([]);
  magazines += ([ magazine ]);  
  return 1;
}

void
remove_magazine(mixed magazine)
{
  mixed h;
  if (!magazines)
    return;
  if (!magazine)
  {
    if (h = query_magazines())
      return remove_magazine(h);
  }
  else if (!pointerp(magazine))
    magazine = ({magazine});
  magazines -= mkmapping(magazine);
}

mapping build_missile_event(object missile, mapping action) {
  return 
    ([E_OBJECT: missile; missile->query_name(),
      E_TARGET: action[E_TARGET]; action[E_TARGET,1],
      E_FROM: this_object(); this_object()->query_name(),
      E_AGENT: action[E_AGENT]; action[E_AGENT,1],
      E_ACTION: action; 0,
      E_WEAPON: this_object(); this_object()->query_name()]);
}

void set_aim(mapping aim_attack);

// if this function should ready new ammunition from the magazines,
// it should be overloaded
void notify_shoot_action(mapping action) {
  object *missiles;

  if (action[E_SUCCESS]) {
    send_message(({M_CLASS, action,
                   M_ARG,E_AGENT,M_VERB,"shoot",M_ARG,E_AGENT,
                   M_SIMPLE_DESCRIBE, query_ready_ammunition()," with ",
                   M_THE,M_ARG,E_TOOL,
                   " at ",M_THE,M_ARG,E_TARGET,"."}),action);
  } else {
    send_message(({M_CLASS, action,
                   M_ARG,E_AGENT,M_VERB,"shoot",M_ARG,E_AGENT," ",
                   M_SIMPLE_DESCRIBE, query_ready_ammunition()," with ",
                   M_THE,M_ARG,E_TOOL,
                   " at ",M_THE,M_ARG,E_TARGET,", but misses."}),action);
  }
  missiles = query_ready_ammunition();
  for (int i = sizeof(missiles); i-->0; ) {
    send_event("missile", build_missile_event(missiles[i], action),
               ({environment(action[E_AGENT]), environment(action[E_TARGET])}));
    remove_ready_ammunition(missiles[i]);
  }
  set_aim(0);
}

void stop_aiming() {
  send_message(({M_CLASS, aim, 
                 M_ARG,E_AGENT,M_VERB,"stop",M_ARG,E_AGENT," aiming ",
                 M_THE,M_ARG,E_WEAPON,
                 " at ",M_THE,M_ARG,E_TARGET,"."}),aim);
  set_aim(0);
}

status should_stop_aiming(mapping action) {
  return aim && action[E_ACTION] != "shoot";
}

status should_shoot(mapping action) {
  return action[E_ACTION] == "shoot";
}

private void notice_prepare_other_action(mapping action) {
  mapping h;

  if (should_stop_aiming(action))
    stop_aiming();
}

private void notice_other_action(mapping action) {
  mixed h;
  if ((h = query_aim()) && should_shoot(action)) {
    notify_shoot_action(h);
  }
}

void set_aim(mapping aim_attack) {
  if (!aim && aim_attack) {
    listen_event("prepare_action",
                 EPRIO_NOTICE3,
                 #'notice_prepare_other_action);
    listen_event("action",
                 EPRIO_NOTICE3,
                 #'notice_other_action);
  }
  if (aim && !aim_attack) {
    unlisten_event("prepare_action",
                   EPRIO_NOTICE3,
                   #'notice_prepare_other_action);
    unlisten_event("action",
                   EPRIO_NOTICE3,
                   #'notice_other_action);
  }
  aim = aim_attack;
}

void
set_max_ready_ammunition(int max)
{
  if (max < sizeof(query_ready_ammunition()))
    raise_error("Bad argument 1 to set_max_ready_ammunition()\n");
  max_ready_ammunition = max;
}

void set_max_magazines(int max) {
  if (max < sizeof(query_magazines()))
    raise_error("Bad argument 1 to set_max_magazines()\n");
  max_ready_ammunition = max;
}

void configure() {
  weapon::configure();
  set_persistence(__FILE__);
  add_action_rule("shoot "G_OBJECT" at "A_G_TARGET, "shoot");
  add_action_rule("shoot "G_OBJECT, "shoot");
  add_action_rule("shoot at "A_G_TARGET, "shoot");
  add_action_rule("shoot", "shoot");
  add_action_error_message("shoot", "Shoot what at whom?\n");
  add_action_rule("fire "G_OBJECT" at "A_G_TARGET, "shoot");
  add_action_rule("fire "G_OBJECT, "shoot");
  add_action_rule("fire at "A_G_TARGET, "shoot");
  add_action_rule("fire", "shoot");
  add_action_error_message("fire", "Fire what at whom?\n");
  add_action_rule("aim "G_OBJECT" at "A_G_TARGET, "aim");
  add_action_rule("aim "G_OBJECT, "aim");
  add_action_rule("aim at "A_G_TARGET, "aim");
  add_action_rule("aim", "aim");
  add_action_error_message("aim", "Aim what at whom?\n");
  add_action_rule("stop aiming", "stop_aim");
  add_action_rule("stop aiming "G_OBJECT, "stop_aim");
  add_action_error_message("stop", "Stop aiming?\n"); 
}

status do_action(string action, mapping args) {
  if (action == "stop_aim") {
    if (query_aim() && !(args[G_OBJECT] && args[G_OBJECT] != this_object())) {
      stop_aiming();
      return 1;
    } else {
      notify_fail("Stop aiming what?\n", 2); 
    }
  }
  if (action == "aim" || action == "shoot") {
    if (args[G_OBJECT] && args[G_OBJECT] != this_object())
      return 0;
  }
  return weapon::do_action(action, args);
}

status handle_action_aim(mapping attack, string type, int p) {
  if (attack[E_SUCCESS]) {
    send_message(({M_CLASS, attack,
                   M_ARG,E_AGENT,M_VERB,"aim",M_ARG,E_AGENT,
                   M_THE,M_ARG,E_WEAPON,
                   " at ",M_THE,M_ARG,E_TARGET,"."}),attack);
  } else {
    send_message(({M_CLASS, attack,
                   M_ARG,E_AGENT,M_VERB,"try",M_ARG,E_AGENT," to aim ",
                   M_THE,M_ARG,E_WEAPON,
                   " at ",M_THE,M_ARG,E_TARGET,", but fails."}),attack);
  }
  set_aim(attack[E_SUCCESS] && attack);
  return 1;
}

status handle_action_shoot(mapping attack) {
  notify_shoot_action(attack);
  return 1;
}

mapping build_complete_action(mapping action, mapping args) {
  switch (action[E_ACTION]) {
  case "aim":
  case "shoot":
    if (args && args[A_G_TARGET])
      action += ([ E_TARGET: args[A_G_TARGET]; args[A_G_TARGET,1] ]);
    if (args && args[G_OBJECT])
      action += ([ E_OBJECT: args[G_OBJECT]; args[G_OBJECT,1] ]);
  }
  return weapon::build_complete_action(action, args);
}

mapping build_action_event(mapping action) {
  mixed skill;
  object target;
  string location;
  int difficulty;
  mixed h;

  switch (action[E_ACTION]) {
    case "aim":
      skill = S_P_SHOOT;
      if (!action[E_TARGET]) {
        if (target = action[E_AGENT]->get_opponent()) {
          target = target->get_hit_location() || target;
          location = target->query_name();
          difficulty = 10; 
        }
      } else if (target = action[E_TARGET]) {
        target =
          target->get_hit_location(this_object(),action[E_TARGET,1]) ||
          target;
        location = target->query_name() || action[E_TARGET,1];
        difficulty = 10; // should depend on the target the player gave
      }
      action += ([E_TARGET: target; location]);
      return 
        ([E_WEAPON: action[E_TOOL]; action[E_TOOL,1]]) +
        action +
        ([ E_MODE         : A_MODE_SHORT; 0,
           A_PREPARE_TIME : 10; 10,
           A_RUNTIME: 5000; 500,
           A_FINISH_TIME: 300; 300,
           E_SKILL: ([ skill : 
                       action[E_AGENT]->use_skill(skill, 10); 10 ]); 0,
           A_ABORT_ACTION : (#'running_action_aborted); 0 ]);
    case "shoot":
      if (target = action[E_TARGET]) {
        target =
          target->get_hit_location(this_object(),action[E_TARGET,1]) ||
          target;
        location = target->query_name() || action[E_TARGET,1];
        difficulty = 10; // should depend on the target the player gave
      } else if (h = query_aim()) {
        target = h[E_TARGET];
        target =
          target->get_hit_location(this_object(),h[E_TARGET,1]) || target;
        action += ([E_TARGET : target; h[E_TARGET,1]]);
      } else if (target = action[E_AGENT]->get_opponent()) {
        target = target->get_hit_location() || target;
        location = target->query_name();
        difficulty = 10; 
      }
      skill = S_P_SHOOT;
      action[E_TYPE,1] = "attack";
      return
        action +
        // let the mapping overwrite fields of the action-mapping
        ([ E_MODE         : A_MODE_SHORT; 0,
           A_PREPARE_TIME : 300; 0,
           A_RUNTIME      : 200; 200,
           A_FINISH_TIME  : 20; 0,
           A_CONCENTRATION: 10; 0,
           E_TARGET       : target; location,
           E_WEAPON       : action[E_TOOL]; action[E_TOOL,1],
           E_SKILL        : ([ skill:
                               action[E_AGENT]->use_skill(skill,difficulty);
                               difficulty ]); 0 ]);
  }
  return weapon::build_action_event(action);
}

mixed query_action_impossible(mapping action) {
  switch (action[E_ACTION]) {
    case "aim":
      if (!action[E_TARGET])
        return "Aim at whom or what?\n";
      if (query_aim())
        return "You're already aiming.\n";
      if (!sizeof(query_ready_ammunition()))
        return "You should load it first.\n";
      if (!action[E_AGENT]->query_wielding(this_object()))
        return "You should wield it first.\n";
      if (action[E_OBJECT] && action[E_OBJECT] != action[E_TOOL] &&
          member(query_ready_ammunition(), action[E_OBJECT]) < 0)
        return "Aim what?\n";
      break;
    case "shoot":
      if (!action[E_TARGET])
        return "Shoot at whom or what?\n";
      if (!sizeof(query_ready_ammunition()))
        return "You should load it first.\n";
      if (!action[E_AGENT]->query_wielding(this_object()))
        return "You should wield it first.\n";
      if (action[E_OBJECT] && action[E_OBJECT] != action[E_TOOL] &&
          member(query_ready_ammunition(), action[E_OBJECT]) < 0)
        return "Shoot what?\n";
      break;
  }
  return weapon::query_action_impossible(action);
}
