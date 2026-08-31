//----------------------------------------------------------------------------
// Title:						Author:
//	Monk's guild soul/skills defs file.			Sauron.
//
// File:						Started:
//	/players/sauron/guild/soul/soul.h			180696.
//
// Purpose:
//	This soul defs file brings together all the definitions needed for
//	the guild soul and skills, and holds any global variables.
//
// History of revisions/fixes:
//
// 180696: Sauron: Started programming.
// 210696: Sauron: Moved soul handle to general guild shadow 
//                 (guild/shadows/guild_shadow.c)
//                 Revised layout of header.
//
//----------------------------------------------------------------------------

#ifndef __GUILD_SOUL_H__

#define __GUILD_SOUL_H__

// Preprocessor directives:

#include "/players/sauron/guild/soul/soul_basic.h"

// End preprocessor directives.


// Prototypes:

string valid_guild_command(string verb,object ob);
string valid_guild_skill_cmd(string verb,object ob);

// End prototypes.


string valid_guild_command(string verb,object ob) {
  string ret;

  if(query_GM(ob))
    ret=G_BIN_GM+verb;

  if((!ret || ret=="" || file_size(ret+".lpc")<0) && APPR(ob))
    ret=G_BIN_WIZ+verb;

  if((!ret || ret=="" || file_size(ret+".lpc")<0) && query_creator(ob,1))
    ret=G_BIN_CR+verb;

  if((!ret || ret=="" || file_size(ret+".lpc")<0) && query_protector(ob,1))
    ret=G_BIN_PROT+verb;

  if((!ret || ret=="" || file_size(ret+".lpc")<0) && query_advanced(ob,1))
    ret=G_BIN_AD+verb;

  if(!ret || ret=="" || file_size(ret+".lpc")<0)
    ret=G_BIN_PL+verb;

  if(!ret || ret=="" || file_size(ret+".lpc")<0)
    return 0;

  else
    return ret;
}

string valid_guild_skill_cmd(string verb,object ob) {
  string bin,ret;
  int cmd;

  cmd=(int)G_SM->assoc_guild_cmd(verb);
  bin=SPECS[(int)G_SM->query_cmd_info(verb,CMD_SPEC)];
  ret=G_BIN+bin+"/"+verb;

  if(cmd==-1 || file_size(ret+".lpc")<0 ||
     query_guild_level(ob)<(int)G_SM->query_cmd_info(verb,CMD_LEVEL))
    return 0;

  else
    return ret;
}

#endif // __GUILD_SOUL_H__
