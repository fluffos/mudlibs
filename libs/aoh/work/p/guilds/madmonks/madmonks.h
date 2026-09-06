/* This is an include file for the files in the madmonk guild*/
// made by magictcs

#include <rooms.h>
#include <secure/wizlevels.h>
#pragma verbose_errors
#pragma combine_strings

// name of the guild - move this to the sys dir!!
#define GC_MADMONKS "madmonks"

// pathes:
#define BASISROOM         "/p/guilds/madmonks/room/basis"

#define GUILD(x)          "/p/guilds/madmonks/"+x
#define GUILDOBJ(x)       "/p/guilds/madmonks/obj/"+x
#define MONKROOM(x)       "/p/guilds/madmonks/room/"+x
#define MAINGUILD         "/p/guilds/madmonks/room/madmonks"
#define MONKNPC(x)        "/p/guilds/madmonks/npc/"+x

#define GUILDOBJ2 GUILDOBJ("mm")

// some alias
#define TP                this_player()
#define NAME              this_player()->QueryName()
#define REALNAME          this_player()->QueryRealName()
#define TO                this_object()
#define PO                previous_object()
#define CAP(x)            capitalize(x)
#define ENV(x)            environment(x)

// logfile:
#define MADMONKLOG        "/p/guilds/madmonks/log/mm.log"

