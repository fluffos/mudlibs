/*
 * Pocket watch for checking MUD time
 */

inherit "inherit/treasure";

void reset(status arg) {
  if (arg) return;
  set_short("A pocket watch");
  set_alias("watch");
  set_weight(0);
}

status drop() {
  destruct(this_object());
  return 1;
}

status query_domain_safe() { return 1; }

void long() {
  string long_descr, post_time;
  int hour, minute;

  long_descr = "Australian eastern time is : " + ctime(time()) + "\n" +
               "The time in Nirvana is : " +
               environment(this_player())->query_time() + "\n";
  write(long_descr);
  return (long_descr);
}

object query_auto_load() { return ("/objects/watch:"); }

