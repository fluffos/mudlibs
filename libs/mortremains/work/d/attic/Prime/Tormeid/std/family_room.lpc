// This inheritable room simple creates a randomly generated family
// in the room that will reset differently than a std room.  
// The wife/mother will only reset if there isn't one already in the room
// but the kids will reset over and over again.
// oh yeah.. 10% chance the daddy will show up.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {  seteuid(getuid());  ::create() ;
}
void reset() {
   if (!present("mother", TO)) clone_object(MON(family_wife))->move(TO) ;
  if (!random(3)) clone_object(MON(family_baby))->move(TO) ;
  if (!random(3)) clone_object(MON(family_girl))->move(TO) ;
  if (!random(3)) clone_object(MON(family_boy))->move(TO) ;
  if (!random(10)) clone_object(MON(guard2))->move(TO) ;
  ::reset() ;
}
