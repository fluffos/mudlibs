#include <areas.h>

#define GDIR "/guilds/thieves/"
#define GDIR2 "guilds/thieves/"

#define	GUILD_LOCATION	(AREA_FARAWAY+"mountain/path7")

#define THIEF_LOG(f, x) \
call_other("/guilds/thieves/rooms/guild", "thief_log", (f), (x))
