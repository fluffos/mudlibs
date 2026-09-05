#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",YEL"客厅"NOR);
        set("long", @LONG
          这里是襄阳守备吕文德的家,屋内家具做工考究,古香古色.
      屋边的架子上摆着许多古玩,行家一看便知,都是唐宋时代的精品.
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"neizhai1",
  "east"  : __DIR__"xynorth2",
  ]));

        set("objects", ([
                __DIR__"npc/shinv" : 2]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );
        setup();
}

