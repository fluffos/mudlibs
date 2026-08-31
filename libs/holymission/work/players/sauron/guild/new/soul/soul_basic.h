//----------------------------------------------------------------------------
// Title:						Author:
//	Monk's guild soul.					Sauron.
//
// File:						Started:
//	/players/sauron/guild/soul.c				100696.
//
// Purpose:
//	This soul handles guild commands and gives guild members an
//	identity/individuality.
//
// History of revisions/fixes:
//
// 100696: Sauron: Started programming.
// 180696: Sauron: Created soul.h file for soul/skill interaction.
// 200696: Sauron: Added guild_shadow functionality.
// 210696: Sauron: Added bug catch on actual command as well as bin module.
//                 Added check_guild_shadow() to handle the guild shadow.
//                 Revised layout of header.
//                 Added log notify toggle.
// 220696: Sauron: Moved extra_look() to guild/include/extra_look.h
//                 Implemented setquery.
// 230696: Sauron: Implemented skill system phase 1 (skill_master.c,
//                 skill.h and cmd_functions.c).
//
//----------------------------------------------------------------------------

#ifndef __SOUL_BASIC_H__

#define __SOUL_BASIC_H__

// Preprocessor directives:

#include "/players/sauron/guild/include/include.h"

// End preprocessor directives.


// Prototypes:

int id(string str);
void check_guild_shadow();

// End prototypes.

int id(string str) {
#ifdef TESTING
  return str=="nms" || str=="robe";
#else
  return str==guild_name+"soul" || str=="robe" ||
         str=="soul" || str=="guildsoul";
#endif
}

void check_guild_shadow() {
  object shad,tmp;  
  if(!TP->guild_shadow()) {
    G_ROOM->add_member();
    shad=clone_object(G_SHAD+"guild_shadow");
    shad->start_shadow(TP,0,"guild_shadow",0);
    set_tmp("guild_shadow",shad);
    set_tmp("guild_soul",TO);
  }
  else if(!(tmp=G_ROOM->handle_soul(TP)) || tmp!=TO) {
    G_ROOM->remove_member();
    G_ROOM->add_member();
  }
}

#endif // __SOUL_BASIC_H__
