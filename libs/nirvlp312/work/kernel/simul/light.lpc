#ifdef NEW_LIGHT

#include <kernel.h>

#define LIGHT_SERVER MASTER

nomask int set_light_level(mixed amount) {
  int new_level;

  new_level = LIGHT_SERVER->add_light(amount,previous_object());
  LIGHT_SERVER->notify_server_light_change(previous_object());
  return new_level;
}

varargs int query_light_level(object ob) {
  mixed h;

  if (ob && !objectp(ob))
    raise_error("Bad argument 1 to query_light_level()\n");
  if (catch(h = LIGHT_SERVER->add_light(0,ob||previous_object())))
    return 333;  // mark for error
  else
    return h;
}

varargs int query_own_light(object ob) {
  mixed h;

  if (ob && !objectp(ob))
    raise_error("Bad argument 1 to query_own_light()\n");
  return funcall(LIGHT_SERVER->query_outward_light(ob||previous_object()));
}

int add_absorption(int amount) {
  int new_absorption;
  new_absorption = LIGHT_SERVER->add_absorption(amount,previous_object());
  LIGHT_SERVER->notify_server_light_change(previous_object());
  return new_absorption;
}

varargs int query_absorption(object ob) {
  return LIGHT_SERVER->query_absorption(ob||previous_object());
}

varargs mapping query_light_sources(object ob) {
  return LIGHT_SERVER->query_light_sources(ob||previous_object());
}

varargs mapping query_inner_light_sources(object ob) {
  return LIGHT_SERVER->query_inner_light_sources(ob||previous_object());
}

varargs mapping query_outer_light_sources(object ob) {
  return LIGHT_SERVER->query_outer_light_sources(ob||previous_object());
}

// for compatibility
int set_light(int amount) {
  return set_light_level(amount);
}

varargs int query_light(object ob) {
  return query_light_level(ob);
}

#endif

