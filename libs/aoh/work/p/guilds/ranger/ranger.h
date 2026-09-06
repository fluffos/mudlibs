// the configuration file of the ranger guild in OSB
//
// [S] 29jun98: Initial creation and basic stuff
//
// Wizards:
// [E] Eilan
// [S] Softbyte

#ifndef _RANGER_H_
#define _RANGER_H_

#define TP this_player()
#define TI this_interactive()
#define TO this_object()
#define PO previous_object()
#define CAP(x) capitalize((x)||"Something")


#define RANGER_MAIN       "/p/guilds/ranger/"
#define RANGER_STD(x)     RANGER_MAIN "std/" +x
#define RANGER_OBJ(x)     RANGER_MAIN "obj/" +x
#define RANGER_NPC(x)     RANGER_MAIN "npc/" +x
#define RANGER_ROOMS(x)   RANGER_MAIN "rooms/" +x
#define RANGER_SAVE(x)    RANGER_MAIN "save/" +x
#define RANGER_HELP(x)    RANGER_MAIN "help/" +x
#define RANGER_QUEST(x)   RANGER_MAIN "quest/" +x
#define RANGER_LOG(x)     "/log/guilds/ranger/" +x


#define RANGER_GUILD      RANGER_ROOM( "guild" ) 
#define RANGER_ERRORLOG   "/log/guilds/ranger/error.log"

#define RANGER_NEWS RANGER_HELP("news")

/* ------------------- Internal Stuff ---------------------------- */
#endif
