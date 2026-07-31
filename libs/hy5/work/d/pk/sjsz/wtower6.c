//Cracked by Kafei
// sdong, 3/18/2000

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create()
{
        set("short","石阶");

        set("long",@LONG
这後山石阶蜿蜒於试剑山庄中，也不知通往何处。只见浓荫蔽天，越
走越是阴森，不时还有野兽吼声传来，令人心中发毛。
LONG);

          set("exits",([ "up" : __DIR__"wtower7",
                         "down" : __DIR__"wtower5",
                      ])
              );
          set("cost",2);
	create_room();
          set("bwdhpk",1);setup();
}

void init()
{
        init_room();
}

