/*
    global/server/regions.c
    5/10/93, foslay
*/

#include <server.h>

#include "regions.h"

inherit "basic/create";

mapping worlds = ([]);

create ()
{
  if (clonep ()) return destruct (this_object ());
  if (!worlds = SE_MEMORY -> query_memory (REGIONKEY, 0))
      worlds = ([]);
  add_world (DEFAULTWORLD, "<dummy>");
  add_region (DEFAULTREGION, 0, 0, 0, 0); /* Please note the different meanings of all the 0's */
}

prevent_move () { return 1; }

query_prevent_shadow () { return 1; }

notify_destruct ()
{
  SE_MEMORY -> set_memory (REGIONKEY, worlds);
  SE_MEMORY -> set_mode (REGIONKEY, object_name (this_object ()));
}

/*
    Create a region in a world. If world is zero the region is
    created in the default world. world_x and world_y are
    the coordinates of the center of the region in the world.
*/
varargs int
add_region (string name, int world_x, int world_y, int timezone, string world_name)
{
  mixed *w;
    
  if (w = worlds[world_name ? world_name : DEFAULTWORLD])
      if (!w[WO_REGIONS][name]) {
	  w[WO_REGIONS][name] = ({ world_x, world_y, timezone, 0, 0 });
	  return 1;
      }
  return 0;
}

string *		
query_regions (string world_name)
{
  mixed *w;
    
  if (w = worlds[world_name ? world_name : DEFAULTWORLD])
      return m_indices (w[WO_REGIONS]);
  else
      return 0;
}

/*
    Give a name to a world and name an object
    which manages the world (time, weather, etc ...)
    Note: the manager is a dummy and isn't used yet.
*/
varargs int
add_world (string name, string manager)
{
   if (!worlds[name]) {
       worlds[name] = ({ manager, ([]) });
       return 1;
   }
   return 0;
}

string *
query_worlds () { return m_indices (worlds); }
