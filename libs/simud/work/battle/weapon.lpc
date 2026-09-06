#include <battle.h>
#include <item.h>
#include <object.h>
#include <const.h>
#include <inven.h>
#include <weapon.h>
#include <condition.h>

/// \todo Document this file

ICON( '(', 7, 1 )

mapping query_aspects() {
   return ([ C_WEAPON ]);
}

GETTABLE( 1 )
DROPPABLE( 1 )
HOLDABLE( 1 )
CONDITION( 500 )

int on_drop( object actor ) {
  if( !query_droppable() ) return 0; // Can't drop
  if( !query_held() ) return MOVE_OK_FLAG; // Nothing special happens
  set_held(0);
  if (query_held())
    return 0; // Cannot be dropped. Should give an error.
  return MOVE_OK_FLAG; // All ok
}

int on_give( object actor ) {
  if( !query_droppable() ) return 0; // Can't drop OR give
  if( !query_held() ) return MOVE_OK_FLAG; // Nothing special happens, just give it.
  set_held(0);
  if (query_held())
    return MOVE_SILENCE_FLAG; // No error, do not move it
    // Note: I disagree with the 'no error'! but what kind of error should it give?
  return MOVE_OK_FLAG;
}
