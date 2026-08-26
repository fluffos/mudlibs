/*
// reply.c
// Command to send a message to the last person who sent you a tell.
// There was a very old version of this that was wrecked by the move
// to 0.9.0. Prydain and Blackpool played with it. Someone got it
// working but didn't add a header, probably Prydain.
// Mobydick added this header and the help, 11-20-92
// Pallando re-wrote the whole command from new (92-12-12)
// Watcher modified it for use with the new body system (93-03-26)
// 93-08-18 Grendel@tmi-2 added input_to option to get rid of those
//                        crossed lines.
// 94-11-10 Leto@Earth fixed return types related to notify_fail
// 95-10-03 Leto@Earth fixed it for I3. Basically make it use
//           the tell command as it should
*/

#include <net/daemons.h>
#include <mudlib.h>
#include <commands.h>

inherit DAEMON ;

#define SYNTAX "Syntax: reply [<message>]\n"

void got_reply(string msg, string who);

int cmd_reply( string msg ) {
  string who;

  who = (string)this_player()-> query( "reply" );
 
  if(!who) {
  notify_fail("No target found for reply.\n");
  return 0; }
 
  if( !msg ) {
     printf( "Your last tell was from '%s'.\n", who );
    input_to("got_reply", 0, who);
    write("reply> ");
    return 1;
  }
  got_reply(msg, who);
  return 1;
}
 
void got_reply(string msg, string who)
{
  object user;
  string target, mud;
  int emote;

  if( !msg || msg == "" ) {
    write("Aborted.\n");
    return;
  }

  who = lower_case( who );
   if( sscanf( msg, ":emote %s", msg ) ) emote = 1;
 
 
  user = find_player(who);
if (emote) {
     notify_fail( "Emotes are valid only with intermud tells/replies.\n" );
  return 0;
}
 
  if(!user && strsrch(who,"@")==-1) {
  write(capitalize(who) + " is no longer around.\n");
  return; }
 
  //if((int)this_player()->query("npc") && !wizardp(user))
  //write( TS_D-> tell_user( this_player()-> query( "name" ),
	//0, who, msg) );
 
   CMD_TELL->cmd_tell(who+" "+msg);
 
return; }

int help() {
  write( SYNTAX + "\n" +@HELP
Effect: tells <message> to the last person to send you a tell.  If
you omit message, you will be given a prompt to enter the message.
This allows you to reply without worrying if someone else will send
you a tell while you are typing.
HELP
			       );
  return 1;
}
