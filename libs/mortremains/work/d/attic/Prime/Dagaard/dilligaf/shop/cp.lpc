#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short" , "Claddagh Street");
  set( "long" , @EndText
EndText
  );
  set( "exits", ([
    "start" : START,
    "void"  : VOID,
  ]) );
  set("item_desc" , ([
  ]));
}
