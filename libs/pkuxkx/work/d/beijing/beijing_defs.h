#ifndef __BEIJING_DEFS_H__
#define __BEIJING_DEFS_H__

#define HELPER "/d/beijing/helper.lpc"	// chu's helper functions
#define HELPER2 "/d/beijing/helper2.lpc"	// ssy's helper functions
#define TRAVERSER "/clone/obj/traverser.lpc"

#define IS_SHIWEI(player) (player->query("class") == "officer")
#define PIN(player) (player->query("pin"))
#define day_event() (NATURE_D->outdoor_room_event())

#endif
