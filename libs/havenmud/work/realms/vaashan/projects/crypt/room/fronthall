
/*  fronthall.c
 *  The front hall to the desert crypt.
 *  Vaashan@Haven 9/14/09
 */
#include <lib.h>
#include "../crypt.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetAmbientLight(30);
  SetClimate("indoors");
  SetShort("the front hall");
  SetLong();
  SetSmell();
  SetListen();
  SetItems();
  SetItemAdjectives();
  SetEnters( ([
     "south" : CRYPT_ROOM + "gate",
     "west" : CRYPT_ROOM + "room1",
     "east" : CRYPT_ROOM + "room9"
     ]) );
}