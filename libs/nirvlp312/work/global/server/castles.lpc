/*
    global/server/castles.c
    5/14/93, foslay
*/

#pragma strong_types  // Coogan, 24-Aug-01

#include <server.h>

inherit "basic/create";

#define CASTLEKEY ({"global/server","castles"})

string *castles = ({});

string _read_castlesM (string castle) {
  return creator_file (castle);
}

int _read_castlesF (string castle) { return castle[0..0] != "#" && castle[<7..] == "/castle"; }

void read_castles() {
  castles = map (filter (explode (read_file ("/room/init_file"), "\n"), "_read_castlesF"), "_read_castlesM");
}


void create() {
  if (clonep ())
    return destruct(this_object());
  if (!(castles = SE_MEMORY -> query_memory (CASTLEKEY, 0)))
    read_castles();
}

int prevent_move () { return 1; }

int query_prevent_shadow () { return 1; }

void notify_destruct ()
{
  SE_MEMORY -> set_memory (CASTLEKEY, castles);
  SE_MEMORY -> set_mode (CASTLEKEY, object_name (this_object ()));
}

string *query_castles () { return castles[0..]; }

