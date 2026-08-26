/*
// File:     shutdownd.c
// Purpose:  Does mudlibby things before calling the shutdown() efun.
// Credits:
// 92-09-26  Truilkan @ Basis wrote the original version.
// 93-01-04  Pallando @ TMI-2 added in the delay option and Apocalypse bits.
// 93-01-14  Pallando moved the emotes to a seperate file
// Comments: (makes it easier for other muds to create their own emote files)
// 93-04-02  Pallando added stop_shutdown()
// 93-05-22  Watcher @ TMI-2 Changed shout()s to message()s
// Comments: ensures the emotes are labeled and this_player() get them.
// 93-07-08  Pallando ensured delay to shutdown isn't messaged twice.
// 93-07-08  Grendel@tmi-2 stoped two shutdowns happening at once
// 93-10-30  Inspiral@TMI-2 added the DNS_MASTER call in save_daemons().
// 94-04-30  Robocoder added query_reason(), and PRUNE_LOGDIR to save_daemons()
// 94-07-26  Blue streamlined the get_emote() function, and made the
//           function select a random file, instead of a #defined one.
//           Also added some comments to the functions.
// 94-12-04  Blue fixed the count_down() function for the new driver,
//           cause previous_object() wasn't defined any more.
*/

#include <config.h>
#include <uid.h>
#include <daemons.h>
#include <net/daemons.h>
#include <driver/origin.h>

#define log( x )
// #define EMOTE_FILE "/adm/daemons/sh_apocalypse.t"
#define EMOTE_DIR "/adm/daemons/"
// Note the trailing slash.  Saves a bit of bother.
#define EMOTE_WILD "sh_*.t"
// The format of the filenames in EMOTE_DIR with the shutdown
// sequences in them.

string *emotes;
int num_emot; // the number of emotes
int s_sec; //   The time() the shutdown is due at, in seconds.
string reason;

string query_reason() { return reason; }
int query_shutdown() { return s_sec; }
mixed query_emotes() { return copy(emotes); }

void
save_daemons()
{
// Someone commented this check below, and i enabled it again.
// It's there so that no sneaky wiz can send UDP shutdowns
// to all muds by calling this. Leto
if (previous_object()) {
   if (getuid(previous_object()) != ROOT_UID) return; // Leto
 }
   PRUNE_LOGDIR_D->backup_debug_log();
   EMOTE_D->save_data();
#ifdef INTERMUD
// Commentd out because wmhod is obsolete and the existing
// Server at Actlab is gone anyways.
// CMWHO_D->halt();
   DNS_MASTER->send_shutdown();
#endif
   users()->save_data();
}

void init_emotes() {
  // Chooses a random emote file, if it can find any.  If so,
  // loads the contents into the *emotes array.  If not, sets
  // the *emotes array to be empty.
    string *emotefiles;
    emotefiles = get_dir( EMOTE_DIR + EMOTE_WILD );
    if (!sizeof( emotefiles )) {
        emotes = ({ });
        num_emot = -1;
    }
    else {
        emotes = explode( read_file(EMOTE_DIR + emotefiles[random(sizeof(emotefiles))]), "###\n");
        num_emot = sizeof(emotes) - 1;
#ifdef DEBUG
write ("NE="+num_emot) ;
#endif
    }
}

void
do_shutdown(int how) {
  // Performs the actual shutting down, right at the end.
   if ((previous_object() && geteuid( previous_object() ) != ROOT_UID) ||
	(!previous_object() && origin()==ORIGIN_CALL_OTHER) ) return ;
   save_daemons();
   shutdown(how);
}

void count_down(int how);

varargs
int start_shutdown( int how, int delay, string reasoning ) {
  // Called by the shutdown command to start the process off.
  if( geteuid( previous_object() ) != ROOT_UID ) return s_sec;
  if( delay < 0 ) return s_sec;
  if( this_player() )
   message("shutdown", (string)this_player()->query("cap_name") +
           " cackles: The end of the world is nigh. Prepare to meet thy " +
           "DOOM!\n", users());
  reason = reasoning;
  if( !delay )
  {
    do_shutdown( how );
    return time();
  }
  // if there is another shutdown on the way then cancel it
  if(s_sec)
    remove_call_out("count_down");

  s_sec = time() + ( delay * 60 );
    init_emotes();
  count_down( how );
  return s_sec;
}

string get_emote( int delay )
{
  // Returns the appropriate emote to the number of minutes left.
  if( delay < num_emot ) return emotes[(num_emot-delay)];
  return 0; // No message except the time until shutdown, done by count_down()
}

void count_down( int how )
{
  // A rather foolishly written function (sorry :) that is
  // called every minute once the shutdown has started.
  // It calculates the remaining time to shutdown, and
  // broadcasts the appropriate messages.
  int delay;
  string msg;

  if ( (origin() != ORIGIN_LOCAL) && (origin() != ORIGIN_CALL_OUT) )
    return;
  delay = ( s_sec + 30 - time() ) / 60;
// If s_sec - time() is a multiple of 60, as it's supposed to be,
// this won't make any difference.  However, it seems that the
// call_outs are getting delayed at some point by a couple of
// seconds, so this is needed to get the number of minutes right.
  if( msg = get_emote( delay ) )
    message( "shutdown", msg, users() );

  if( delay ) message( "shutdown",
    "The mud will shut down in " + delay + " minutes.\n", users() );
  if( delay < 1 )
  {
    do_shutdown( how );
    return;
  }
  call_out( "count_down", 60, how );
}

int stop_shutdown()
{
  // Self-explanatory, I suppose.  Stops everything.
  if( geteuid( previous_object() ) != ROOT_UID ) return 0;
  s_sec = 0;
  reason = 0;
  remove_call_out( "count_down" );
  if( this_player() )
    message("shutdown", "The Mighty " + this_player()->query("cap_name") +
            " intervenes to save the world.\n", users());
// Blessed are the peacemakers, for they shall save your hard won kit.
  return 1;
}
