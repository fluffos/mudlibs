int cmd_gauge(string cmd) {

  int eval, a, b, c, d, e, f;
  string before, after;

  if((int)this_player()->query_level() < 21) return 0;
  if(!cmd) return (notify_fail("Gauge what?\n"), 0);
  before = rusage();
  eval = (int)this_player()->force_us(cmd);
  after = rusage();
  sscanf(before, "%d %d %d", a, b, c);
  sscanf(after,  "%d %d %d", d, e, f);

  write("The cmd took " + (d-a) + " utime, " + (e-b) + " stime, and eval cost " + eval + ".\n");
  return 1;
}
