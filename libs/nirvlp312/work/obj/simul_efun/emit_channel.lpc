/******************************************************************************
 * Program: emit_channel.c
 * Path: /obj/simul_efun
 * Type: Include file for player.c and channel_daemon.c
 * Updated: July 8, 2014 by Dragnar
 *
 * Purpose: Simul Efun for sending channel messages.  Not sure why we need
 *          this as well as /obj/user/one_chan.c ?
 *
 * History:
 *          07/08/2014 - Gnar
 *            Updated to use the channel daemon.
 ******************************************************************************/
#pragma strict_types
#pragma save_types

#ifndef CHAN
#define CHAN "/bin/channel_daemon"
#endif

/*
// This function accepts the channel name to emit to, and
// the message to emit.  It returns the number of people echoed to.
*/

int
emit_channel(string channel, string message) {
  CHAN->channel_message(channel, message, "");
  return 1;
}
