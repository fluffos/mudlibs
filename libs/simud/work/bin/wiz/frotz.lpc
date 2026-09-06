int main(string arg) {
  object who, victim;
		
  WIZ_CHECK

  if( !arg )
    return notify_fail("==> [Format] frotz victim\n");

  victim = find_player(arg);
  if( !victim )
    return notify_fail("I can't find any such player '"+arg+"' to zap.\n");

  AUDIO_DAEMON->sfx_mud("thunder.wav");

  foreach( who : users() ) {
    set_actor( this_player() );
    set_target( victim );
    set_listener( who );
    msg_object(who,"~CTITFROTZ! ~CBRT~Name ~verbstrike ~targ with lightning.~CDEF");
  }

  victim->set_env_var( "cause_of_death", "was frotzed by "+capitalize(this_player()->query_name())+"." );
  victim->add_hp( this_player()->query_level() / -4);

  return 1;
}
