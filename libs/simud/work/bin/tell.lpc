#include <textdraw.h>

main(string str) {
  string what,list,*who,teller;
  object targ;
  int x;

  if(!str) {
    notify_fail("Erm, tell whom what?\n");
    return 0;
  }

  sscanf(str,"%s %s",list,what);
  if(!what) {
    notify_fail("Were you going to tell them something?\n");
    return 0;
  }

  who = explode(list,",");
  who = m_indices(mkmapping(who));

  for (x = 0; x < sizeof(who); x++) {
    targ = find_player( who[x] );

    if( !targ || (targ->query_invis() == 1 && this_player()->query_level() < WIZLEVEL )) {
      notify_fail("Could not find "+who[x]+"!\n");
      return 0;
    }

    if( targ == this_player() ) {
       msg( "You do know that talking to yourself excessively is a sign of insanity, right?" );
       continue;
    } //don't tell them they're ignoring you
  /*else if (targ->query_ignore(this_player()->query_name())) {
       notify_fail( targ->query_cap_name() + " is ignoring you.\n" );
       return 0;
    }*/

    what = recolor( what );

    if (this_player()->query_invis() == 1 && targ->query_level() < WIZLEVEL)
       teller = "Someone";
    else
       teller = this_player()->query_cap_name();

    // toads get their tells quietly discarded
    if (!this_player()->query_toad() && !targ->query_ignore(this_player()->query_name()))
       msg_object(targ, "~CACT" + teller + " tells you~CDEF: " + what, strlen(teller)+12);

    // add this message to the target's tell history
    if (!this_player()->query_toad() && !targ->query_ignore(this_player()->query_name()))
       targ->add_tell(teller,what);

    if (targ->query_afk())
      msg("~CACT"+capitalize(who[x])+"~CDEF is AFK: ~CLAB"+targ->query_afk()+"~CDEF",strlen(who[x])+9);
    else if (query_idle(targ)>60*5) {
       string buf = "~CLAB" + capitalize(who[x]);
       buf += "~CDEF has been idle for ~CBRT" + int_to_time(query_idle(targ));

       if(!targ->query_afk() && targ->query_env_var("idlemsg"))
          buf += "~CDEF, but left the following message: ~CLAB" + targ->query_env_var("idlemsg");
       msg(buf+"~CDEF");
    }
  }

  if (sizeof(who) > 1) {
    list = "";
    for (x = 0; x < sizeof(who); x++)
      list += capitalize(who[x])+",";
    list = list[..(strlen(list)-2)];
    this_player()->add_tell("to "+list,what);
    msg("~CACTYou tell "+ list +"~CDEF: " + what, 11 );
  } else {
    this_player()->add_tell("to "+capitalize(who[0]),what);
    msg("~CACTYou tell "+ capitalize(who[0]) +"~CDEF: " + what,
        strlen(who[0])+11 );
  }

  return 1;
}
