/* tell_object_wblock(object to, string what)
 * It's a tell block....
*/
int tell_object_wblock(object to, string what) {
  object from;

  if (this_player())
    from = this_player();
  if (!from) {
    efun::tell_object(to,what);
    return 1;
  }
  if (from->query_level() < 21 && !from->query_npc()) {
    efun::tell_object(from, to->query_name() + " is blocking your tells.\n");
    return 1;
  }
  efun::tell_object(to,what);
  return 0; /* Rumplemintz */
}

