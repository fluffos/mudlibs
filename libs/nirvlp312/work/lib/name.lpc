/*
 * lib/name.c
 */

#pragma strong_types
#pragma no_clone
#pragma no_inherit

#include <fingerd.h>

inherit "basic/name";

private mapping hashed_vis_names = ([]);

/*
 * to_vis_name() returns the vis_name of the given player. Therefore the
 * vis_names are hashed to reduce the number of load_player()s.
 */
varargs mixed to_vis_name(mixed name, status dont_capitalize) {
  mixed h;
  if (!name)
    return 0;
  if (pointerp(name))
    return map(name,(#'to_vis_name));
  name = to_real_name(name);
  if (h=hashed_vis_names[name])
    return h;
  h = find_player(name) || FINGERD->load_player(name);
  if (!h)
    if (dont_capitalize)
      h = name;
    else
      h = capitalize(name);
  else
    h = h->query_vis_name() || capitalize(name);
  return hashed_vis_names[name] = h;
}

/*
 * This function is called by the player object when the the vis_name is
 * changed.
 */
void change_vis_name(string real_name,string vis_name) {
  if (!interactive(previous_object()))
    return;
  hashed_vis_names[real_name] = vis_name;
}

