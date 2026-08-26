/* snoop command, trial out by Turrican for a commands daemon. */
inherit COMMAND_BASE;

int do_snoop_cancel() {
  seteuid(geteuid(this_player()));
  if (!query_snooping(this_player()))
    write("You aren't snooping anyone.\n");
  else  {
    snoop(this_player(), 0);
    write("Ok, snoop cancelled.\n");
  }
  return 1;
} /* do_snoop_cancel() */

int do_snoop(object *obs) {
  object targ;

  targ = obs[0];
  if(!snoop(this_player(), targ)) {
    notify_fail("You fail to snoop " + targ->the_short() + ".\n");
    return 0;
  }
  write("Ok, snooping "+targ->the_short()+".\n");
  return 1;
} /* do_snoop() */

mixed *query_patterns() {
  return ({ "<indirect:player>", (: do_snoop($1) :),
            "", (: do_snoop_cancel() :) });
} /* query_patterns() */
