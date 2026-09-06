//---------------------------------------------------------------------------
// room/cleaning.c
//
// Cleanup handling of rooms.
//---------------------------------------------------------------------------

#include <properties.h>
#include <rooms.h>
#include <driver/object_info.h>

#define THIS	   this_object()
#define ENV	   environment

//---------------------------------------------------------------------------
// Cleanup handling:
//
// ref < 0: our environment calls us to clean up.
// ref = 0: we are a clone, or a blueprint with replaced program.
// ref = 1: we are a swapped and/or unreferenced blueprint.
// ref > 1: we are a non-swapped blueprint in use.
//
// If the room has an environment() and is a cloned room, it will return 0
// and thus never clean up.
// The room won't selfdestruct if there are items which need the room
// for refresh (like REFRESH_HOME). Items which can be recreated by the
// room are ignored.
// Contained alien objects are asked to clean up themselves (by a call
// 'clean_up(-1)'), and if no such object remains, the room will destruct
// all left (non-alien) objects and itself.

public int clean_up(int ref) {
  mixed *items, rc;
  object *alien, *objs, item, *own;
  int s, i, refr;

  // If the object doesn't want to be cleaned up, don't do it.
  if (call_resolved(&rc, THIS, "QueryProp", P_CLEAN_UP) && !rc)
    return 1;

  // Objects with environment do not clean up on their own.
  if (ENV() && is_clone())
    return 0;

  // Check if there are room items which need the room to exist.

  own = ({});
  items = ({mixed *})THIS->QueryItems();
  for (s = sizeof(items); s--; ) {
    refr = items[s][RITEM_REFRESH];
    i = RITEM_OBJECT;
    if (mappingp(items[s][i]) || pointerp(items[s][i])) i++;
    if (refr & REFRESH_FUNC) i++;
    objs = items[s][i..] - ({ 0 });
    for (i = sizeof(objs); i--; ) {
      // Moving other items might have destructed this one.
      if (!(item = objs[i]))
        continue;

      if (!objectp(item))
        raise_error(sprintf("Item is no object: %O\n", item));

      // If the item exists somewhere else and needs noticeable actions
      // upon reset, don't clean up for now.
      // One might discuss if REFRESH_DESTRUCT counts for this, too.
      if ( (refr & ( REFRESH_DESTRUCT|REFRESH_RESET|REFRESH_PROPS ))
	   && ENV(item) != THIS
	 )
	return 1;

      // If the item exits somewhere else, and demands home-moving on
      // reset, simulate it. If the move fails, it fails - mostly for
      // bug reasons.
      if ( (refr & REFRESH_MOVE_HOME) && ENV(item) != THIS )
	item->move(THIS);

      // The item belongs to this room and is here - note that.
      if (item && ENV(item) == THIS)
        own += ({ item });
    }
  }

  // Compute the inventory which can't be reconstructed by the room, and
  // ask it to clean up.
  alien = all_inventory() - own;
  filter_objects(alien, "clean_up", -1);

  // If there aren't any alien objects left and we have come so
  // far, then destruct all our items and selfdestruct, because
  // the items will be recreated when we are.
  if (!sizeof(alien - ({ 0 }))) {
    filter_objects(own, "clean_up", -1);
    filter_objects(own+({ THIS })-({ 0 }), "remove");
  }
  return THIS && 1;
}

// Dummy-remove for the blueprint
public varargs int remove(int arg) {
  object *inv;
  int i, rc;
  mixed tmp;

  if (!THIS)
    return 0;
  if (!environment(THIS) && arg == -1)
  {
    inv = all_inventory(THIS);
    for (i = 0; i < sizeof(inv); i++)
    {
      if (query_once_interactive(inv[i]))
	continue;
      catch(rc = call_resolved(&tmp, inv[i], "remove", -1));
      if (inv[i] && rc)
	return 0;
    }
  }
  destruct(THIS);
  return 1;
}
