/*****************************************************************************
  leave <guild> 
  Coded by: Germ
  Last modified: 13/13/97 by Chopin

*****************************************************************************/

#include <guild.h>

status leave_cmd( string arg )
{
    object mark;
    string guild_name;

    if ( !( this_player()->query_coder_level() ))
	return 0;

    if ( arg != "guild" ) {
	notify_fail("Usage: leave guild\n");
	return 0;
    } 

    if(!(guild_name = this_player()->query_guild())) {
	notify_fail("But you are not a member of any guild.\n");
	return 0;
    }

    mark = this_player()->query_guild_object();
#ifdef GN_FIGHTER
    if(this_player()->query_guild() == GN_FIGHTER) {
	if(mark) {
	    mark->resign3("yes"); //Let Fighters guild symbol do the dirty job
	    //of reducing Fighter skills etc etc
	}
    }
    else
#endif
    if(mark) {
	destruct(mark);
    }

    this_player()->tell_me(sprintf("You leave the %s guild.",
	guild_name));

    /** reset player guild info **/

    this_player()->set_guild(0);
    this_player()->set_guild_object(0);
    this_player()->set_guild_object_name(0);
    this_player()->set_guild_commands(0);
    this_player()->set_guild_hook( ([]) );

    return 1;
}
