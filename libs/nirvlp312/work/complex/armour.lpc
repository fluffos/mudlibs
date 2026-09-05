/****************************************************************************
      armour.c -- written by Alfe, Chameloid and Ugh for Tubmud
****************************************************************************/

// ATTENTION: This file is still in work and will probably still change a lot
// in the nearer future. Please don't use it in your code, yet

#include <combat.h>
#include <message.h>
#include <event.h>
#include <prop/item.h>

inherit "complex/clothing";

private mixed protection;

void set_protection(int p) {
  protection = p;
}

int query_protection() {
  return funcall(protection);
}

void set_id(mixed id) {
  if (pointerp(id))
    ::set_id(id+({ "armour" }));
  else
    ::set_id(({ "armour",id }));
}

void set_type(mixed t) {
  clothing::set_type(t);
  // set_layer(GET_LAYER(t));
  // set_rigid(GET_RIGID(t));
  set_protection(GET_PROTECTION(t));
  set_short(t);
  set_name(t);
  set_id(t);
}

void create() {
  ::create();
  set_type("armour");
}

void modify_damage(mapping e) {
  mixed h;
  h = random(query_protection())/100;
  debug("alfe",sprintf("received: %d\n"
                       "subtract: %d\n",
                       e[E_DAMAGE],h));
  e[E_DAMAGE] -= h;
}

void set_armour_long(string desc) {
  set_long(desc);
}
