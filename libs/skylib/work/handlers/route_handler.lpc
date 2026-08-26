/**
 * Figures out the route between two destinations for an npc to travel.
 * @author Wodan
 */
/* routes handler */

int use_count;

/**
 * Try and figure out a route between two locations.  It figures out
 * the route bwteen the two locations and then calls the
 * call_back function with the found route, or not found route.
 * If the route is not found, an empty array will be returend.  The
 * function in the npc object move_me_to() handles the call
 * to this function transparently.
 * @param end the end location
 * @param start where to start from
 * @param call_back the function to call when finished
 * @see /obj/monster->move_me_to()
 * @example
 * // Find how to get from here back to the drum.
 * // Then print the route out.
 * ROUTE_HANDLER->get_route("/d/am/am/mendeddrum",
 *                          file_name(environment(this_object())),
 *                          (: printf("%O\n", $1) :));
 */
varargs void get_route(string end, string start, function call_back, int count) {
  string *result;

  if(!function_owner(call_back))
    return; //don't bother

  if ((end == start) || (count > 3)){
    call_out((: evaluate($(call_back), ({ })) :), 1);
    if(end != start)
      log_file("ROUTEHANDLER","route for %s from %s to %s failed\n",
               file_name(function_owner(call_back)), start, end);
    return;
  }

  result = "/handlers/clusters"->get_route(start, end);
  
  if(!result){
    call_out((:get_route($(end), $(start), $(call_back), $(count + 1)):), 10);
    return;
  }

  use_count++;
  call_out((: evaluate($(call_back), $(result)) :), 1);
  return;
} /* get_route */

/** @ignore yes */
void dest_me() {
  destruct(this_object());
} /* dest_me() */

/** @ignore yes */
mixed *stats() {
  return  ({
    ({ "routes done", use_count }),
  });
}
