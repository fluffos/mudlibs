/*
 * complex/lamp.c -- a configurable lamp/torch or whatever radiates light
 *   in a non-magical way.
 *
 * HISTORY
 *  Foslay & Magor 14-Jul-1993 Created this file
 *  Fangorn        23-Jul-1993 Fixed a bug: `light' and `extinguish' without
 *                           arguments didn't work properly
 *  Magor          26-Jul-1993 Completed Fangorns bugfix to work with the
 *                           other commands of the lamp, too
 * Coogan, 16-Jun-1998: replaced nearly all current_fuel with query_fuel(),
 *                    the same for max_fuel.
 * Coogan, 03-Jun-1999: adapted for NEW_LIGHT
 * Alfe, 2001-Aug-02: took out old code which was disabled due to NEW_LIGHT
 */

#ifndef NEW_LIGHT  // Alfe 2001-Aug-02
 This file depends greatly on NEW_LIGHT and cannot be used without it.
#endif

#pragma strong_types

#include <persistence.h>
#include <prop/elements.h>
#include <prop/item.h>
#include <describe.h>
#include <grammar.h>
#include <message.h>
#include <light.h>

inherit "complex/item";

private string *fill_levels, *light_levels;
private int current_fuel, max_fuel;
private int current_level, max_level;
private int wetness;
private int light_strength;

int query_max_fuel() {
  return max_fuel;
}

int query_fuel() {
  if (current_fuel > query_max_fuel())
    return query_max_fuel();
  return current_fuel;
}

string *query_fill_levels() {
  return fill_levels;
}

int query_light_strength() {  // Coogan, 03-Jun-1999
  return light_strength;
}

void set_light_strength(int ls) {  // Coogan, 03-Jun-1999
  if (ls > 0)
    light_strength = ls;
}

string query_lamp_long(string str) {
  return item::query_long(str);
}

// this function returns 0 if no fill levels are known,
// the only fill level if just one is known,
// the first level if the lamp is empty,
// the last fill level if the lamp is full or if just two levels are known,
// if more than two fill levels are known and the lamp is neither completely
// full nor completely empty, one of the intermediate levels is returned.
string fill_level_string() {
  int fill_level_size, fuel, max_fuel;
  fill_level_size = fill_levels && sizeof(fill_levels);
  if (!fill_level_size)
    return 0;
  fuel = query_fuel();
  if (fuel == 0)
    return fill_levels[0];
  if (fill_level_size <= 2 || fuel == (max_fuel=query_max_fuel()))
    return fill_levels[<1];
  return fill_levels[1 + fuel * (fill_level_size-2) / (max_fuel+1)];
}

string query_long(string str) {
  string s;
  s = fill_level_string();
  return (query_lamp_long(str)+
          "It is " + (wetness?
                      "wet, and therefore currently unusable":
                      light_levels[current_level/query_light_strength()]) +
          (s? ", and " + s : "") + ".\n");
}

status id(string str) {   // Alfe 1996-Mar-01
  string fill_level;
  if (!str) // Chameloid, 12-Oct-1997
    return 0;
  if (!(fill_level=fill_level_string()))
    return item::id(str);
  return (item::id(str) ||
          (str[0..strlen(fill_level)] == fill_level + " " &&
           item::id(str[strlen(fill_level)+1..])));
}

int query_lamp_value() {
  return item::query_value();
}

int query_value() {
  if (wetness || current_level)
    return 0;
  return (query_lamp_value() * query_fuel())/query_max_fuel();
}

string *query_light_levels() {
  return light_levels;
}

int query_lighted() {
  return current_level;
}

string query_lighted_description(status in_output) {
  if (query_lighted())  // lamp is lighted
    if (in_output)
      return query_light_levels()[current_level/query_light_strength()];
    else  // in input
      return ("lit\\>|\\<" +
              query_light_levels()[current_level/query_light_strength()]);
  else  // lamp is not lighted
    if (in_output)
      return 0;  // no output for simple not lighted lamps
    else  // in input
      return ("unlit\\>|\\<not lit\\>|\\<unlighted\\>|\\<" +
              query_light_levels()[current_level/query_light_strength()]);
}

int query_wetness() {
  return wetness;
}

mixed query_wetness_description(status in_output) {
  if (query_wetness())
    return "wet";
  if (in_output)
    return 0;  // don't mention explicitly that it is dry
  else
    return "dry";  // only in input accept this description
}

int prevent_insert() {
  if (current_level) {
    message("Oh, no! It is still lighted!\n");
    return 1;
  }
  return 0;
}

// changes the light level of the lamp according to 'change', produces
// messages describing the behaviour of the lamp (not the actor!) and
// returns the current light level of the lamp.
int adjust_light(int change) {
  int prev_light, post_light;
  object room;
  mixed t;

  status see_before, see_after;
  object *who_can_see_before, *who_can_see_after, *people;
  object *who_cant_see_before, *who_cant_see_after;

  if (!change || current_level + change < 0 ||
      current_level + change > max_level)
    return current_level;
  if (remove_call_out("burn_down") != -1) {
    current_fuel -= 15 * (current_level / query_light_strength());
    if (current_fuel < 0 ) {
      current_fuel = 0;
      change = -current_level;
    }
  }
  if (environment())
    room = get_room(this_object());
  if (room) {  // Coogan, 01-Nov-1999
    people = filter(all_inventory(room), #'living);
    // added args silently to test_sight(), Coogan, 18-Dec-2000
    who_can_see_before = filter_objects(people, "test_sight", 0, 1);
    who_cant_see_before = people - who_can_see_before;
  }
  prev_light = query_light(room);
  if ((current_level+=change) > 0)
    call_out("burn_down", 30);
  set_light(change);
  if (!room)
    return current_level;
  post_light = query_light(room);
  change = post_light - prev_light;  /* this way all absorptions
                                      * etc are taken into account.
                                      */
  who_can_see_after = filter_objects(people, "test_sight", 0, 1);
  who_cant_see_after = people - who_can_see_after;
  if (change > 0) {  // it got lighter
    if (!environment() || !living(environment()) || environment()->short())
      // torch isn't invisible (due to being carried by invis living)
      message(({ ({ M_ROOM, room,      // !before && after
                    M_EXCLUDE, who_can_see_before + who_cant_see_after,
                    M_ME_THE, M_ME_VERB, "light", " this dark place." }),
                 ({ M_ROOM, room,      // before && !after
                    M_EXCLUDE, who_cant_see_before + who_can_see_after,
                    "As ", M_ME_THE, M_ME_VERB, "light",
                    ", this place becomes too bright to see." }),
                 ({ M_ROOM, room,      // before && after
                    M_EXCLUDE, who_cant_see_before + who_cant_see_after,
                    M_ME_THE, M_ME_VERB, "light", " up this place." })
                 /* people who can't see before nor after
                  * do not receive any messages.
                  */
      }));
    else  // torch itself is invis because it is carried by an invis living
      message(({ ({ M_ROOM, room,      // !before && after
                    M_EXCLUDE, who_can_see_before + who_cant_see_after,
                    "Suddenly, it is bright enough to see." }),
                 ({ M_ROOM, room,      // before && !after
                    M_EXCLUDE, who_cant_see_before + who_can_see_after,
                    "Suddenly, it is too bright to see." }),
                 ({ M_ROOM, room,      // before && after
                    M_EXCLUDE, who_cant_see_before + who_cant_see_after,
                    "The light here is even brighter now." }) }));
  }
  else if (change < 0) {  // it got darker
    if (!environment() || !living(environment()) || environment()->short())
      // torch isn't invisible (due to being carried by invis living)
      message(({ ({ M_ROOM, room,      // !before && after
                    M_EXCLUDE, who_can_see_before + who_cant_see_after,
                    "As ", M_ME_THE, M_ME_VERB, "go",
                    " dark, you can see again." }),
                 ({ M_ROOM, room,      // before && !after
                    M_EXCLUDE, who_cant_see_before + who_can_see_after,
                    "Deep shadows surround you, as ",
                    M_ME_THE, M_ME_VERB, "go", " dark." }),
                 ({ M_ROOM, room,      // before && after
                    M_EXCLUDE, who_cant_see_before + who_cant_see_after,
                    M_ME_THE, M_ME_VERB, "go", " dark." }),
                 // no message for people who can't see before nor after
      }));
    else  // torch itself is invis because it is carried by an invis living
      message(({ ({ M_ROOM, room,      // !before && after
                    M_EXCLUDE, who_can_see_before + who_cant_see_after,
                    "Suddenly, it is not too bright to see anymore." }),
                 ({ M_ROOM, room,      // before && !after
                    M_EXCLUDE, who_cant_see_before + who_can_see_after,
                    "Suddenly, it gets completely dark." }),
                 ({ M_ROOM, room,      // before && after
                    M_EXCLUDE, who_cant_see_before + who_cant_see_after,
                    "It gets a little darker." }) }));
  }
  // else: no change: no message
  return current_level;
}

status lamp_light() {
  if (wetness) {
    message(({ ({ M_TARGETS,M_CAN_SEE + ({ this_player() }),
                  M_PL_THE,M_PL_VERB,"fail"," to light ",M_OBJECT,M_ME_THE,
                  ", because ",M_ME_PRONOUN,M_ME_VERB,"are"," wet." }),
               ({ M_EXCLUDE,M_CAN_SEE + ({ this_player() }),
                  "You hear someone doing something but cannot see"
                  " anything." }) }));
    return 1;
  }
  if (current_level)
    return notify_fail(({ ({ M_WRITE,
                             M_THE,this_object(),M_VERB,"are",this_object(),
                             " already lighted." }) })), 0;
  if (current_fuel == 0)
    return notify_fail(({ ({ M_WRITE,
                             M_THE,this_object(),M_VERB,"are",this_object(),
                             " " + fill_levels[0] +
                             " and cannot be lighted." }) })), 0;
  message(({ ({ M_TARGETS,M_CAN_SEE + ({ this_player() }),
                M_PL_THE,M_PL_VERB,"light",M_OBJECT,M_ME_THE,"." }),
             ({ M_EXCLUDE,M_CAN_SEE + ({ this_player() }),
                "You hear someone doing something but cannot see"
                " anything." }) }));
  adjust_light(light_strength);  // 1 -> to light_strength, Coogan, 02-Jun-1999
  return 1;
}

status lamp_extinguish() {
  if (current_level == 0)
    return notify_fail(({ ({ M_WRITE,
                             M_THE,this_object(),M_VERB,"are",this_object(),
                             " not lighted." }) })), 0;
  message(({ ({ M_TARGETS,M_CAN_SEE + ({ this_player() }),
                M_PL_THE,M_PL_VERB,"douse",M_OBJECT,M_ME_THE,"." }),
             ({ M_EXCLUDE,M_CAN_SEE + ({ this_player() }),
                "You hear someone doing something but cannot see"
                " anything." }) }));
  adjust_light(-current_level);
  return 1;
}

status lamp_adjust(string direction) {
  int old_level;
  if (current_level == 0)  // not on at all?
    return notify_fail("You should light it first!\n"), 0;
  old_level = current_level;
  if (max_level == light_strength)  // not adjustable (just on/off)?
    return notify_fail(({ ({ M_WRITE,
                             M_PL_THE,M_PL_VERB,"cannot"," adjust ",
                             M_OBJECT,M_THE,this_object(),"." }) })), 0;
  switch (direction) {
  case "up":
    message(({ ({ M_TARGETS,M_CAN_SEE + ({ this_player() }),
                  M_PL_THE,M_PL_VERB,"adjust",M_OBJECT,M_ME_THE," up." }),
               ({ M_EXCLUDE,M_CAN_SEE + ({ this_player() }),
                  "You hear some noises." }) }));
    if (adjust_light(light_strength) == old_level)
      send_message(({ M_SAY, "But nothing happens.",
                      M_WRITE,
                      "But ",M_ME_THE,M_ME_VERB,"are",
                      " already as bright as possible." }));
    return 1;
  case "down":
    send_message(({ M_PL_THE,M_PL_VERB,"adjust",M_OBJECT,M_ME_THE," down." }));
    if (adjust_light(-light_strength) == 0)
      send_message(({ M_TARGETS,M_CAN_SEE,
                      M_ME_THE,M_ME_VERB,"extinguish","." }));
    return 1;
  default:
    return notify_fail(({ ({ "Adjust ",M_OBJECT,M_THE,this_object(),
                             " up or down, please." }) })), 0;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

void set_fuel(int fuel) {
  if (fuel > max_fuel)
    fuel = max_fuel;
  current_fuel = fuel;
}

int add_fuel(int fuel) {
  if (current_fuel + fuel > max_fuel) {
    fuel -= max_fuel-current_fuel;
  }
  current_fuel += fuel;
  return fuel;
}

void set_max_fuel(int fuel) {
  max_fuel = fuel;
}

void set_fill_levels(string *levels) {
  fill_levels = levels;
}

void set_light_levels(string *levels) {
  light_levels = levels;
  max_level = (sizeof(levels) - 1) * query_light_strength();
  if (current_level > max_level)
    adjust_light(current_level - max_level);
}

void burn_down() {
  current_fuel -= 15 * (current_level / query_light_strength());
  if (current_fuel <= 0) {
    current_fuel = 0;
    adjust_light(-current_level);
  }
  else
    call_out("burn_down", 30);
}

void wet_lamp(int time_to_dry) {
  remove_call_out("dry_it");
  if (time_to_dry <= 0)
    return;
  adjust_light(-current_level);
  wetness = time_to_dry;
  call_out("dry_it", wetness);
}

void dry_it() {
  wetness = 0;
}

mixed do_action(string action,mapping args) {
  if (args[G_OBJECT] && args[G_OBJECT] != this_object())
    return 0;
  switch (action) {
  case "light":
    return lamp_light();
  case "extinguish":
    return lamp_extinguish();
  case "adjust":
    return lamp_adjust(args[G_WORD]);
  }
  return 0;  // Coogan, 26-Mar-2011
}

void configure() {   // create -> configure, Carador, Oct-1996
  item::configure();
  set_persistence("complex/lamp", 
                  PER_KEEP_VARS,
                  ({ "fill_levels", "light_levels", "fuel", "max_fuel",
                     "light_strength",
                     ({ "value", "set_value", "query_lamp_value" }),
                     ({ "long",  "set_long",  "query_lamp_long" })
                  }));  // Carador, Oct-1996
  set_light_strength(LIGHT_LAMP);
  set_fill_levels(({ "empty","rather empty","rather full","full" }));
  set_light_levels(({ "not lighted", "lighted" }));
  set_short("a lamp");
  set_long("A simple lamp.\n");
  set_id(({ "lamp" }));
  set_encumbrance(2000);
  set_value(20);
  set_max_fuel(2000);
  set_fuel(2000);
  add_to_property(P_STATE_DESCRIPTION, ({ 0, "query_lighted_description" }));
  add_to_property(P_STATE_DESCRIPTION, ({ 0, "query_wetness_description" }));
  add_action_error_message("light",      "Light what?\n");
  add_action_error_message("douse",      "Douse what?\n");
  add_action_error_message("extinguish", "Extinguish what?\n");
  add_action_error_message("adjust",     "Adjust what up or down?\n");
}

void init() {
  item::init();
  add_action_rule("light "G_OBJECT,           "light");
  add_action_rule("douse "G_OBJECT,           "extinguish");
  add_action_rule("extinguish "G_OBJECT,      "extinguish");
  add_action_rule("adjust "G_OBJECT" "G_WORD, "adjust");
  add_action_rule("adjust "G_OBJECT,          "adjust");
}
