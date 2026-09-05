/*
 * /basic/breakable.c
 * 
 * The basic functionality of a breakable object
 */

#include <damage.h>

inherit "basic/damageable";

private mapping damage_limits;  // a mapping of damage type pointing to
                                // a limit. if one of these limits is
                                // exceeded, then this object breaks.
                                // if you want a different behaviour, you
                                // have to overload the lfun
                                // object_breaks(mapping damage).

private mixed break_rules;  // either a closure which is called when the
                            // object breaks and which's result will re-
                            // place this object if it isn't 0 or an
                            // object which will replace this object or
                            // a string which will be cloned and replace
                            // this object or an array of those things
                            // which will all be processed in this fashion.
                            // in case that the array consists only of
                            // 0s then this object isn't replaced but left
                            // where it was.

private mixed break_message;  // the break message to be given out when this
                              // object breaks.

void set_damage_limits(mapping dl) { damage_limits = dl; }
mapping query_damage_limits() { return damage_limits; }

void set_break_rules(mixed br) { break_rules = br; }
mixed query_break_rules() { return break_rules; }

void set_break_message(mixed bm) { break_message = bm; }
mixed query_break_message() { return break_message; }

/*
 * semantics: say whether this object breaks at this damage. it does nothing.
 * actual implementation: returns whether at least one of the damage types
 *                       given exceeds the limit.
 */
status object_breaks(mapping damage) {
  mixed h;
  int i;
  if (!damage_limits)
    return 0;  // don't break if no limits are set.
  h = m_indices(damage);
  for (i=sizeof(h); i-->0; )
    if (damage[h[i]] > damage_limits[h[i]])
      return 1;
  return 0;
}

private mixed produce_break_result(mixed rule,mapping damage) {
  rule = funcall(rule,this_object(),damage);
  if (pointerp(rule))
    return map(rule,#'produce_break_result,damage);
  if (objectp(rule))
    return rule;
  if (stringp(rule))
    return clone_object(rule);
  return 0;
}

/*
 * semantics: is called when the object actually breaks and shall send a
 *            message about it.
 * actual implementation: sends the break_message.
 */
void send_message_object_breaks(mapping damage,object *break_results) {
  message(({ damage + ([ 1: break_results ]) }) + break_message);
}

/*
 * semantics: is called when the object breaks. it shall do exactly this.
 * actual implementation: it replaces this object by the results of the
 *                        evaluation of break_rules).
 * the argument damage is just given as information, but even if all
 * damage types are of value 0, the object shall still break.
 */
void break_object(mapping damage) {
  mixed h;
  if (pointerp(break_rules))
    h = map(break_rules,#'produce_break_result,damage);
  else
    h = ({ produce_break_result(break_rules,damage) });
  h = flatten_array(h) - ({ 0 });
  send_message_object_breaks(damage,h);
  map(h,#'move_object,environment());
  map(all_inventory(this_object()),#'move_object,environment());
  destruct(this_object());
}

/*
 * semantics: is called when a damage shall be inflicted. it shall do exactly
 *            this.
 * actual implementation: if object_breaks() says that this object breaks at
 *                        this damage, it calls break_object().
 */
void inflict_damage(mapping damage) {
  if (object_breaks(damage))
    break_object(damage);
}

