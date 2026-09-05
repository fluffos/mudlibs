/* follower */

inherit "obj/shadows/shadow";

object who;
object follower;
status follow_self_stop;

void follow(object arg1, object arg2) {
  who = arg1;
  follower = arg2;
  shadow_object(who);
}

status move_player(string dest, mixed opt, status safe) {
  status flag;
  string tmp;

  if (follow_self_stop) {
    destruct(this_object());
    return 0;
  }
  follow_self_stop = 1;
  flag = (status)who->move_player(dest, opt, safe);
  if (!follower) {
    destruct(this_object());
    return flag;
  }
  if (dest) {
    sscanf(dest, "%s#%s", dest, tmp);
    command(dest, follower); /* why this instead of follower->move_player() */
                             /* there may be extra things to do. eg. pub    */
  }
  follow_self_stop = 0;
  if (!present(follower, environment(who))) {
    destruct(this_object());
  }
  return flag;
}

object query_follow_object() { return this_object(); }

