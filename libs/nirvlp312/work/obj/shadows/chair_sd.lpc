/*
 * shadow in conjunction with chair, when in same room, the player is
 * in effect invisible
 */

inherit "obj/shadows/shadow";

#define CAP (string)who->query_cap_name()

object where, who, chair;

void shadow_short() {
  where = environment(previous_object());
  chair = previous_object();
  who   = this_player();
  shadow_object(who);
}

string short(status wiz) {
  if (chair) chair->resolve_sitters();
  if (!chair || !chair->query_sitters(CAP)) {
    destruct(this_object());
    return (string)who->short(wiz);
  }
  if (environment(this_player()) == where) return 0;
  return (string)who->short(wiz);
}

