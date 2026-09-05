/*
 * /global/serve/rexplore.c by Alfe for Tubmud 98-Jun-2
 *
 * a server collecting and providing information about the amount of
 * explore flags found yet.
 */

#include <kernel.h>

inherit "basic/create";
inherit ACCESS;

#define SAVE_FILE "/save/explore"

private mapping found_flags;

void create() {
  restore_object(SAVE_FILE);
  if (!found_flags)
    found_flags = ([]);
}

void save() {
  unguarded(1,#'save_object,SAVE_FILE);
}

void add_player_data(object player) {
  mixed h;
  h = player && player->query_visits();
  if (!h || !pointerp(h))
    raise_error("Bad argument 1 to add_player_data()\n");
  found_flags += mkmapping(player->query_visits());
  save();
}
