/*
// This file is part of the TMI distribution mudlib.
// Please include this header if you use this code.
// Written by Sulam, 91-12-16
// Help added by Mobydick, 92-11-13
// Delay stuff added by Pallando, 93-01-10
// Cancel option suggested by Mobydick and written by Pallando, 93-04-02
*/

#include <config.h>
#include <daemons.h>
#include <mudlib.h>
#include <logs.h>

inherit DAEMON;

#define SYNTAX	"Syntax: shutdown [reason]\n" + \
		"        shutdown [delay] because [reason]\n" + \
		"        shutdown cancel\n"
 
int cmd_shutdown(string str) {
    string name, reason;
    mixed tmp;
    int delay, sd_time;
    string s_delay;

    sd_time = (int)SHUTDOWN_D->query_shutdown();
 
    name = geteuid( previous_object() );
 
    if(!str || str == "" || intp(str)) {
	if(sd_time) 
	  notify_fail("There is presently a shutdown scheduled in " +
		      (sd_time-time())/60 + " minutes.\n" +
		      SYNTAX );
	else notify_fail( SYNTAX ) ;
        return 0;
    }
 
    if( !adminp(name) )    {
        notify_fail( "You are not permitted to shutdown the game.\n" );
 
#ifdef SHUTDOWN_LOG
   log_file(SHUTDOWN_LOG, wrap((string)this_player()->query("cap_name") +
	" attempted shutdown with \"" + str + "\" [" +
	extract(ctime(time()),4,15) + "]"));
#endif
 
        return 0;
    }
 
    if( str == "cancel" || str == "stop") {
 
	if(!sd_time) {
	write("There is no shutdown presently scheduled.\n");
	return 1; }
 
	if(SHUTDOWN_D->stop_shutdown()) {
            write( "You cancel the shutdown.\n" );
 
#ifdef SHUTDOWN_LOG
   log_file(SHUTDOWN_LOG, wrap((string)this_player()->query("cap_name") +
	" cancelled the pending shutdown [" + extract(ctime(time()),4,15) +
	"]"));
#endif
	
	}
        else
            write( "You fail to cancel the shutdown.\n" );
        return 1;
    }

    if (str == "now") {
        write("Please specify a reason for the shutdown.\n");
        return 1;
    } else if (sscanf(str, "%s %s", s_delay, reason) == 2 ||
          sscanf(str, "%s because %s", s_delay, reason) == 2) {
        if (s_delay == "now")
            delay = 0;
        else if (sscanf(s_delay, "%d", delay) != 1)
            delay = 15;
        // else delay was set by sscanf() above
    } else {
        delay = 15;
        reason = str;
    }
 
#ifdef SHUTDOWN_LOG
   log_file(SHUTDOWN_LOG, wrap((string)this_player()->query("cap_name") +
	" started shutdown " + (reason ? "because \"" + reason + "\" " : "") +
	"[" + extract(ctime(time()),4,15) + "]"));
#endif

    tmp = SHUTDOWN_D-> start_shutdown( 0, delay, reason );
    if( !tmp || tmp == time() ) write( "Shutting down now.\n" );
    else write( "Shutdown will happen in " + ((tmp-time())/60) + " minutes.\n");
    return 1;
}

string help() {
    return( SYNTAX + "\n" +
"The shutdown command shuts down the game. Only admins can use it. Doing\n" +
"this causes all objects in the game to be dested. If you do not give the\n"+
"delay argument (an integer number of minutes) it will default to 15 as this\n"+
"starts the apocalypse daemon which gives a warning to players to sell their\n"+
"items and other wizards to save their files.\n" +
"NB a <delay> of \"0\" or \"now\" will shut the game down immediatly.\n"+
"You must provide a reason why you are shutting down the game. All attempts\n" +
"to shut the game down are logged and the reasons noted.\n"+
"NB2 To cancel a shutdown, use \"shutdown cancel\".\n"+
    "" );
}
/* EOF */
