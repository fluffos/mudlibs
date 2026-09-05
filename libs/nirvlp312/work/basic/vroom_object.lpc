/*
 * /basic/vroom_object.c
 *
 */

#include <prop/vroom.h>

/* This function is queried by the standard implementation of
 * /complex/vroom.c to determine which clone of the vroom
 * this object should be moved into upon entering.
 *
 * Objects that should get their own virtual rooms should overload
 * this function and return a unique identifier like their 
 * real_name or object_name.
 */
public string query_vroom_owner() {
  return this_object()->query_property(P_VROOM_OWNER); 
}

void create() {
  string h;
  if (!query_vroom_owner() &&
      (h = previous_object()->query_vroom_owner()))
    this_object()->set_property(P_VROOM_OWNER, h);
}

