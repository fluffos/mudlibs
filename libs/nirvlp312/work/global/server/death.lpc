/* Jun-19-1995 by Ugh -- default handler for the death event */

#include <kernel.h>
#include <event.h>
#include <server.h>
#include <time_units.h>
#include <libs.h>

inherit ACCESS;
inherit "basic/create";

mapping killed_players;

void create() {
  set_global_listening_event("death",1);
  listen_event("death");
  killed_players = ([]);
}

void place_death_trace(mapping e) {
  int delay;
  object trace;
  if (query_once_interactive(e[E_TARGET]))  // did a player die?
    delay = ONE_DAY;
  else
    delay = ONE_HOUR;
  trace = unguarded("@traces",#'call_other,
                    ({ SE_TRACES,"create_trace",e,delay }));
  unguarded("@traces",#'call_other,({ SE_TRACES,"place_trace",
                                      trace,environment(e[E_TARGET]),delay }));
}

void receive_event(mapping e,string t,int p) {
  object victim;
  object *drops;

  if (e[E_HANDLED])  // Alfe 95-Jun-20
    return;
  e[E_HANDLED] = 1;  // Alfe 95-Jun-20
  switch (t) {
  case "death":
    victim = e[E_TARGET];
    if (!objectp(victim))
      return;
#if 0
// this is now directly called from obj/living
    SE_MONSTERS->monster_killed(e); // Carador, 20-Aug-97
#endif
    if (interactive(victim))
      killed_players[victim->query_real_name()] = time();
    else
      drops = LIB_RACE->query_death_drops(e);  // Coogan, 12-Nov-2002
    place_death_trace(e);  // Alfe 98-Jan-2
    victim->receive_death_event(e,t,p);
    if (drops && sizeof(drops)) {  // Coogan, 12-Nov-2002
      if (e[E_TO] && !first_inventory(e[E_TO]))
        map(drops, #'move_object, e[E_TO]);
      else
        map(drops, #'destruct);
    }
    break;
  default:
    return;
  }
}

int query_last_kill(object pl) {
  return killed_players[pl->query_real_name()];
}

