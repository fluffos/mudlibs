// Room: /d/dali/qsjie1.c
// By River 98/12/01
#include <wanted.h>
inherit ROOM;

void create()
{
        set("short", "青石街");
        set("long", @LONG
这是一条宽阔的青石板街道，向南北两头延伸。这里来来往往的大理臣民
你推我挤，热闹非常。北边是一个广场，也就是大理的中心了。南边是一个客
店，远远地看见上面挂着「迎宾馆」三个字。
LONG
        );
        set("outdoors", "大理");

        set("exits", ([ 
                "north" : __DIR__"dalics",
                "south" : __DIR__"kedian",
                "east" : __DIR__"doufufang",
        ]));
 
        set("coor/x",-310);
  set("coor/y",-400);
   set("coor/z",-20);
   setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "south" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
