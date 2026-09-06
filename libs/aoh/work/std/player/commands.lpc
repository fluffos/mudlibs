/* -------------------------------------------------------------------------
 * /std/player/commands -- The main dispatcher for all bin-commands.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 * -------------------------------------------------------------------------
 */

#include <secure/wizlevels.h>

/* -------------------------------------------------------------------------
 * add_bin_commands - this adds all the actions defined later on
 * -------------------------------------------------------------------------
 */

void add_bin_commands() {
  /* commands for all users */

  add_action( "cmd_party",        "pstat"             );
  add_action( "cmd_party",        "party"             );
  add_action( "cmd_party",        "apply"             );
  add_action( "cmd_party",        "recruit"           );
  add_action( "cmd_party",        "leader"            );
  add_action( "cmd_party",        "pemote"            );
  add_action( "cmd_party",        "ptell"             );
  add_action( "cmd_party",        "pname"             );
  add_action( "cmd_party",        "dismiss"           );
  add_action( "cmd_party",        "protect"           );

  add_action( "cmd_score",        "score"             );
  add_action( "cmd_talents",      "talents"           );
  add_action( "cmd_score",        "sc"                );
  add_action( "cmd_equipment",    "equipment"         );
  add_action( "cmd_skills",       "skills"            );
  add_action( "cmd_skills",       "skill"             );

  add_action( "cmd_who",          "who"               );
  add_action( "cmd_whoiswho",     "whoiswho"          );
  add_action( "cmd_finger",       "finger"            );
  add_action( "cmd_finger",       "tfinger"           );

  add_action( "cmd_chmsg",        "=",              1 );
  add_action( "cmd_chemote",      "==",             1 );
  add_action( "cmd_chon",         "chon"              );
  add_action( "cmd_choff",        "choff"             );
  add_action( "cmd_chwho",        "chwho"             );
  add_action( "cmd_channels",     "channels"          );
  add_action( "cmd_chhis",        "chhis"             );

  add_action( "cmd_ask",          "ask"               );
  add_action( "cmd_say",          "say"               );
  add_action( "cmd_say",          "'",              1 );
  add_action( "cmd_converse",     "converse"          );
  add_action( "cmd_tell",         "tell"              );
  add_action( "cmd_tell",         "reply"             );

  add_action( "cmd_rpeers",       "rpeers"            );
  add_action( "cmd_rpeers",       "muds"              );
  add_action( "cmd_rwho",         "rwho"              );
  add_action( "cmd_rlocate",      "rlocate"           );

  add_action( "cmd_color",        "color"             );
  add_action( "cmd_color",        "colour"            );
  add_action( "cmd_color",        "colours"           );
  add_action( "cmd_color",        "colors"            );
  add_action( "cmd_messages",     "messages"          );
  add_action( "cmd_dict",         "dict"              );
  add_action( "cmd_muffle",       "muffle"            );
  add_action( "cmd_config",       "config"            );
  add_action( "cmd_time",         "time"              );

  /* wizard commands from here */
  if ( ! IS_IMMORTAL( this_object() ) )
    return;

  add_action( "cmd_people",       "people"            );
  add_action( "cmd_man",          "man"               );
  add_action( "cmd_netstat",      "netstat"           );
}

/* -------------------------------------------------------------------------
 * combat commands
 * -------------------------------------------------------------------------
 */

public int cmd_party( string arg ) {
  return ({int})"/std/player/bin/party"->cmd_party(arg);
}

/* -------------------------------------------------------------------------
 * who commands
 * -------------------------------------------------------------------------
 */

public int cmd_who( string arg ) {
  return ({int})"/std/player/bin/who"->main( arg );
}

public int cmd_whoiswho( string arg ) {
  return ({int})"/std/player/bin/whoiswho"->main( arg );
}

public int cmd_people( string arg ) {
  return ({int})"/std/player/bin/people"->main( arg );
}

public int cmd_finger( string arg ) {
  return ({int})"/std/player/bin/finger"->main( arg );
}

/* -------------------------------------------------------------------------
 * status commands
 * -------------------------------------------------------------------------
 */

public int cmd_score( string arg ) {
  return ({int})"/std/player/bin/score"->main( arg );
}

public int cmd_talents( string arg ) {
  return ({int})"/std/player/bin/talents"->main( arg );
}

public int cmd_equipment( string arg ) {
  return ({int})"/std/player/bin/equipment"->main( arg );
}

public int cmd_skills( string arg ) {
  return ({int})"/std/player/bin/skills"->main( arg );
}

/* -------------------------------------------------------------------------
 * channel commands
 * -------------------------------------------------------------------------
 */

public int cmd_chmsg( string arg ) {
  return ({int})"/std/player/bin/channel"->tell( arg );
}

public int cmd_chemote( string arg ) {
  return ({int})"/std/player/bin/channel"->emote( arg );
}

public int cmd_chon( string arg ) {
  return ({int})"/std/player/bin/channel"->chon( arg );
}

public int cmd_choff( string arg ) {
  return ({int})"/std/player/bin/channel"->choff( arg );
}

public int cmd_chwho( string arg ) {
  return ({int})"/std/player/bin/channel"->chwho( arg );
}

public int cmd_channels( string arg ) {
  return ({int})"/std/player/bin/channel"->channels( arg );
}

public int cmd_chhis( string arg ) {
  return ({int})"/std/player/bin/channel"->chhis( arg );
}

/* -------------------------------------------------------------------------
 * communication commands
 * -------------------------------------------------------------------------
 */

public int cmd_ask( string arg ) {
  return ({int})"/std/player/bin/ask"->main( arg );
}

public int cmd_say( string arg ) {
  return ({int})"/std/player/bin/say"->main( arg );
}

public int cmd_converse( string arg ) {
  return ({int})"/std/player/bin/say"->converse( arg );
}

public int cmd_tell( string arg ) {
  return ({int})"/std/player/bin/tell"->main( arg );
}

/* -------------------------------------------------------------------------
 * intermud commands
 * -------------------------------------------------------------------------
 */

public int cmd_rpeers( string arg ) {
  return ({int})"/std/player/bin/rpeers"->main( arg );
}

public int cmd_rwho( string arg ) {
  return ({int})"/std/player/bin/rwho"->main( arg );
}

public int cmd_rlocate( string arg ) {
  return ({int})"/std/player/bin/rlocate"->main( arg );
}

/* -------------------------------------------------------------------------
 * help commands
 * -------------------------------------------------------------------------
 */

public int cmd_man( string arg ) {
  return ({int})"/std/player/bin/man"->main( arg );
}

/* -------------------------------------------------------------------------
 * miscellaneous commands
 * -------------------------------------------------------------------------
 */

public int cmd_color( string arg ) {
  return ({int})"/std/player/bin/color"->main( arg );
}

public int cmd_messages( string arg ) {
  return ({int})"/std/player/bin/messages"->main( arg );
}

public int cmd_dict( string arg ) {
  return ({int})"/std/player/bin/dict"->main( arg );
}

public int cmd_muffle( string arg ) {
  return ({int})"/std/player/bin/muffle"->main( arg );
}

public int cmd_time( string arg ) {
  return ({int})"/std/player/bin/time"->main( arg );
}

public int cmd_config( string arg ) {
  return ({int})"/std/player/bin/config"->main( arg );
}

public int cmd_netstat( string arg ) {
  return ({int})"/obj/socketd"->netstat( arg );
}

/* ********************************************************************** */
