#include <room.h>

inherit ROOM;

void create()
{
	set("short", "物品房");
	set("long", @LONG
这是物品房，一个大架子。上面放的整整齐齐，看来这里的管家是
很认真负责的，一些人正在跟管物品工具的管家说着什么。
LONG);
        set("exits", ([
	       "south" : __DIR__"lang4",
	       "north" : __DIR__"lang6",
	       "west" : __DIR__"shilu-1",
	]));
set("roomif","$botten#工具|交工:ask li about 工具|give <物品> to li$#");  
     set("no_fight",1);
        set("objects", ([
           __DIR__"npc/laoli" : 1,
           __DIR__"npc/tlsdizi" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

