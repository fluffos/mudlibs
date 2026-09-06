int month() {
	return gmtime()[4] + 1;
}

int main(string arg) {
  object who, victim, coconut;
		
  WIZ_CHECK

  if( !arg )
    return notify_fail("==> [Format] coconut victim\n");

  victim = find_player(arg);
  if( !victim )
    return notify_fail("I can't find any such player '"+arg+"' to bonk.\n");

  AUDIO_DAEMON->sfx_mud("hithard.wav");

  if( month() == 10 )
    coconut = clone_object("/econ/crop/pumpkin");
  else
    coconut = clone_object("/econ/seed/coconut");

  if( !coconut )
    return notify_fail("There was an error conjuring your coconut. I am sorry.\n");

  foreach( who : users() ) {
    set_actor( this_player() );
    set_target( victim );
    set_listener( who );
    msg_object(who,"~CBRT~Name ~verbconjure a flying "+coconut->query_name()+" to bonk ~targ in the head.~CDEF");
    coconut->move( environment(victim) );
  }

  victim->set_env_var( "cause_of_death", "was slain by flying coconuts." );
  victim->add_hp(-1);

  return 1;
}
