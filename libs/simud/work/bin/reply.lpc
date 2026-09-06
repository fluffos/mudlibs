#include <textdraw.h>

main(string what) {
  object targ;
  int x;

  for (x = sizeof(this_player()->query_tell_history())-1; x >= 0; x--) {
    targ = find_player(lower_case(this_player()->query_tell_history()[x][0]));
    if (targ)
      break;
  }

  if ( !targ ) {
    notify_fail("Could not find anyone to reply to.\n");
    return 0;
  }

  if ( !what ) {
    notify_fail("Were you going to tell them something?\n");
    return 0;
  }

  what = recolor( what );

  msg_object(targ, "~CACT" + this_player()->query_cap_name() +
    " tells you~CDEF: " + what, strlen(this_player()->query_cap_name())+12);

  // add this message to the target's tell history
  targ->add_tell(this_player()->query_cap_name(),what);

  if (targ->query_afk())
    msg("~CACT"+targ->query_cap_name()+" is AFK~CDEF: "+targ->query_afk(),
        strlen(targ->query_cap_name())+9);

  // add this message to the actor's tell history
  this_player()->add_tell("to "+targ->query_cap_name(),what);

  msg("~CACTYou tell "+targ->query_cap_name()+"~CDEF: "+what,
      strlen(targ->query_cap_name())+11 );

  return 1;
}
