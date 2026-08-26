// Inheritable room functions to automatically have a wandering guard
// in a room.  This code makes sure each wander guard is only cloned once.
// I use it alot, so I just made a inheritable file for it. :D
#include <mudlib.h>
#include "../defs.h"   // seems pointless, but the lib says I need it. ;D

inherit ROOM ;

void create() { seteuid(getuid()) ;  ::create() ; }

object guard;

void reset() {
  if (!guard) {
    guard=clone_object(MON(wander_guard)) ;
    guard->move(TO) ;
  }
}
