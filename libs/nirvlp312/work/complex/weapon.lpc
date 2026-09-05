/****************************************************************************
      weapon.c -- written by Alfe, Chameloid and Ugh for Tubmud
****************************************************************************/

// ATTENTION: This file is still in work and will probably still change a lot
// in the nearer future. Please don't use it in your code, yet

#include <grammar.h>
#include <message.h>
#include <describe.h>
#include <combat.h>
#include <event.h>
#include <libs.h>
#include <action.h>
#include <persistence.h>
#include <prop/item.h>

inherit "basic/type";
inherit "complex/tool";

// How big is the 'hilt' of the weapon
private mixed hilt_size;

// for piercing weapons
private mixed pointiness;

// for edged weapons
private mixed sharpness;

// for complex weapons (like nun-chaku or crossbow)
private mixed complexity;

// for breaking chances
private mixed stability;

// for a long description of the weapon (without trailing information).
private mixed weapon_long;

// for a short description (without trailing information like '(wielded)')
private mixed weapon_short;

void set_hilt_size(mixed h)    { hilt_size    = h; }
void set_pointiness(mixed p)   { pointiness   = p; }
void set_sharpness(mixed s)    { sharpness    = s; } 
void set_complexity(mixed p)   { complexity   = p; }
void set_stability(mixed p)    { stability    = p; }
void set_weapon_long(mixed l)  { weapon_long  = l; }
void set_weapon_short(mixed s) { weapon_short = s; }

mixed query_hilt_size()    { return hilt_size;    }  // Alfe 98-Sep-8
mixed query_pointiness()   { return pointiness;   }
mixed query_sharpness()    { return sharpness;    }
mixed query_complexity()   { return complexity;   }
mixed query_stability()    { return stability;    }
mixed query_weapon_long()  { return weapon_long;  }
mixed query_weapon_short() { return weapon_short; }

int get_hilt_size()    { return funcall(hilt_size);    }
int get_pointiness()   { return funcall(pointiness);   }
int get_sharpness()    { return funcall(sharpness);    }
int get_complexity()   { return funcall(complexity);   }
int get_stability()    { return funcall(stability);    }
int get_weapon_long()  { return funcall(weapon_long);  }
int get_weapon_short() { return funcall(weapon_short); }

mapping build_complete_action(mapping action, mapping args) {
  mixed h;
  int i;
  if (LIB_ACTIONS->is_arm_action(action[E_ACTION]) ||
      action[E_ACTION] == "parry") {  // an arm action?
    if (query_wielded_by(action[E_AGENT]))  // are we wielded?
      action[E_WEAPON] = this_object();  // then we are the used weapon
    h = flatten_array(map(get_holders(),#'get_holding_parts));
    for (i=sizeof(h); i-->0; )
      if (!action[A_NEEDED_USED][h[i]->query_name()])  // bodypart not yet in?
        action = h[i]->build_complete_action(action,args) || action;
  }
  return
    LIB_WEAPON->build_complete_action(action,args) ||
    tool::build_complete_action(action, args);
}

mapping build_action_event(mapping action) {
  return
    LIB_WEAPON->build_action_event(action) ||
    tool::build_action_event(action);
}

status query_wieldable_not_present(object by) {
  return LIB_WEAPON->query_wieldable_not_present(query_type());
}

status query_wieldable_not_held(object by) {
  return LIB_WEAPON->query_wieldable_not_held(query_type());
}

status query_wieldable_not_clenched(object by) {
  return LIB_WEAPON->query_wieldable_not_clenched(query_type());
}

status prevent_hold(object by, string location, mixed with) {
  if (query_wielded_by(by))
    return 1;
  return tool::prevent_hold(by,location,with);
}

status prevent_wield(object by) {
  mixed h;

  if (query_wielded_by(by)) {
    return 1;
  } else if (!query_held_by(by)) {
    if (!query_wieldable_not_held(by))
      return 1;
  } else {
    h = get_holding_parts(by);
    if (!query_wieldable_not_clenched(by) &&
        sizeof(h -= filter_objects(h,"query_clenched")))
      return 1;
  }
  if (!query_wieldable_not_present(by) && !present(this_object(),by))
    return 1;
}

void notify_action_unclench(mapping action) {
  if (!query_wieldable_not_clenched(action[E_AGENT]))
    notify_unwield(action[E_AGENT]);
}

void notify_action_let_go(mapping action) {
  if (!query_held_by(action[E_AGENT]) &&
      !query_wieldable_not_held(action[E_AGENT]))
    notify_unwield(action[E_AGENT]);
}

void notify_action_grab(mapping action) {
  if (!query_wieldable_not_clenched(action[E_AGENT]))
    notify_unwield(action[E_AGENT]);
}

void set_type(string t) {
  mixed h;
  if (query_type()) // can't change the type afterwards
    return;
  type::set_type(t);
  set_name(t);
//set_fightplan(object_name(this_object()),
//              LIB_WEAPON->get_default_fightplan(t));
//if (h = LIB_WEAPON->get_combat_actions(t))
//{
//  walk_mapping(h,#'add_combat_action);
//  update_actions();
//}
  set_hilt_size(LIB_WEAPON->get_hilt_size(t));
  set_pointiness(LIB_WEAPON->get_pointiness(t));
  set_sharpness(LIB_WEAPON->get_sharpness(t));
  set_complexity(LIB_WEAPON->get_complexity(t));
  set_stability(LIB_WEAPON->get_stability(t));
  set_encumbrance(LIB_WEAPON->get_encumbrance(t));
}

void configure() {
  tool::configure();
  set_persistence(__FILE__,PER_KEEP_VARS,
                  ({ "hilt_size","pointiness","sharpness","complexity",
                     "stability","weapon_long","weapon_short" }));
  remove_persistent_variable(({"long", "short"}));
  set_property(P_WIELDABLE);
  set_name("weapon");
  set_weapon_short("a non-descript weapon");
  set_short(#'query_weapon_short);
  set_long(#'query_weapon_long);
  set_id(({ "weapon" }));
  add_to_property(P_STATE_DESCRIPTION,({ 0,"query_hold_description" }));
  add_to_property(P_STATE_DESCRIPTION,({ 0,"query_side_description" }));
}

status drop(int silently) {
  if (this_player()->query_wielding(this_object()) &&
      !query_wieldable_not_present(this_player())) {
    return 1;
  }
  return tool::drop(silently); 
}

// next fun added because of complex/shooting_weapon, Coogan, 18-Oct-00
status handle_action_event(mapping e, string type, int p) { }

