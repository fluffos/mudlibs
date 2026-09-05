//gate.c


#include <ansi.h>
#include <room.h>

inherit ROOM;

void init();

void create()
{
      set("short", "云中城");
        set("long", @LONG
这是一座雄伟壮观的城堡，四周云雾缭绕。城堡的大门两旁分别站着一位年轻貌美的姑娘,/n
背后竟然长着一对翅膀！哇，这就是传说中的天使！你这才明白,你已经来到了向往已久的/n
--云中城!你迫不及待地想进去看看，其中一位天使热情地引领你进去。/n
LONG
        );

        set("exits", ([
		"enter" : __DIR__"hall",
                "
        ]));



       set("objects", ([ /* sizeof() == 2 */
 __DIR__"npc/angel" :2,

       
        setup();
	//create_door("south", "云之门", "north", DOOR_CLOSED);
}

