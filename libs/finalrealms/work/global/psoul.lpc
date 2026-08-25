/*
 * Originally..
 * 'the bit of the soul that all players should have ;)'
 * By Pinkfish, presumably
 *
 * Now it really is that bit of the soul that all players should have.
 * Command queue stuff ax'd out and moved to std/living/queue.c
 *
 * By Wonderflug, 1996.
 * 
 * and now it's Baldrick's time. gonna move it out of the living object.
 * I will put it in the /cmds/cmd_handler somehow.
 * 
inherit "/global/alias";
inherit "/global/nickname";
 */

#define SOUL_OBJECT "/obj/handlers/soul"

void soul_commands() 
{
  this_object()->add_alias("soul");
} /* soul_commands() */

int soul_com_force(string str) 
{

  if ( this_object()->action_blocked() && 
       !this_object()->query_lord() )
    return 0;

  if (file_name(previous_object()) != SOUL_OBJECT)
    return 0;

  command(str);

  return 1;
} /* soul_com_force() */

void do_soul(string str, mixed bing) 
{
  say(str, bing);
} /* do_soul() */
