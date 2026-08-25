#define MAX_SIZE 50000

varargs void say(string str, mixed avoid) {
  if (!pointerp(avoid))
    avoid = ({ this_player(), previous_object() }) + ({ avoid });
  else
    avoid += ({ this_player(), previous_object() });
  if (!environment(previous_object()))
    if (this_player() && environment(this_player()))
      event(environment(this_player()), "say", str, avoid);
    else
      event(previous_object(), "say", str, avoid);
  else
    event(environment(previous_object()), "say", str, avoid);
} /* say() */

varargs void tell_room(object ob, string str, mixed avoid) {
  if (!ob || !objectp(ob))
    return ;
  event(ob, "say", str, avoid);
} /* tell_room() */

void tell_object(object ob, string str) {
  if (objectp(ob))
    ob->event_write(previous_object(), str);
} /* tell_object() */

object find_living(string str) {
  string nick;
  object ob;

  if (this_player() && (nick = (string)this_player()->expand_nickname(str)))
    str = nick;
  if ((ob = efun::find_living(str)))
    if ((int)ob->query_invis() == 2)
      return 0;
  return ob;
} /* find_living() */

object find_player(string str) {
  object ob;
  if ((ob = efun::find_player(str)))
    if ((int)ob->query_invis() == 2)
      return 0;
  return ob;
} /* find_player() */

