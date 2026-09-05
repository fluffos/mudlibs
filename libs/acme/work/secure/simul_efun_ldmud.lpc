/**
 * The simulated efun object.
 *
 * @author devo@eotl
 * @alias SimulEfunObject
 */

#include <sys/functionlist.h>
#include <capability.h>

/**
 * Move an object and return success or failure.
 * 
 * @param  item          the item to move
 * @param  dest          the environment to move to
 * @return 0 for failure, 1 for success
 */
int move_resolved(mixed item, mixed dest) {
  move_object(item, dest);
  if (!objectp(item)) { item = find_object(item); }
  if (!objectp(dest)) { dest = find_object(dest); }
  return (item && dest && (environment(item) == dest));
}

/**
 * Return an object's capabilities map.
 * 
 * @param  ob           the object to query
 * @return a mapping of all the object's capabilities
 */
mapping query_capabilities(object ob) {
  mapping result = ([ ]);
  mixed *vars = variable_list(ob, RETURN_FUNCTION_NAME
                                  | RETURN_VARIABLE_VALUE);
  int i = 0;
  while ((i = member(vars, CAPABILITIES_VAR_STR, i)) != -1) {
    mixed val = vars[++i];
    if (mappingp(val)) {
      result += val;
    }
    i++;
  }
  return result;
}

/**
 * Allows you to target an object for the efun binary_message().
 * 
 * @param  who           the object to receive message
 * @param  message       the message to send
 * @param  flags         message flags
 * @return the number of characters written
 */
varargs int send_binary_message(object who, mixed message, int flags) {
  object old = previous_object();
  set_this_object(who);
  int result = binary_message(message, flags);
  set_this_object(old);
  return result;
}

nomask void write(varargs mixed *args) {
  raise_error("write() efun is deprecated, use MessageLib");
}

nomask void tell_room(varargs mixed *args) {
  raise_error("tell_room() efun is deprecated, use MessageLib");
}

nomask void say(varargs mixed *args) {
  raise_error("say() efun is deprecated, use MessageLib");
}

void tell_object(varargs mixed *args) {
  raise_error("tell_object() efun is deprecated, use MessageLib");
}

nomask void printf(varargs mixed *args) {
  raise_error("printf() efun is deprecated, use MessageLib");
}
