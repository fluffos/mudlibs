//ykufang.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "库房");
    set("long", @LONG
燕子坞的库房，里面放满了各种杂物，有个老仆正在进行整理，
看到你闯进来，很惊诧的看着你。
LONG
    );

    set("exits", ([
		"east" : __DIR__"yyuan3",
    ]));

	set("objects", ([
		__DIR__"npc/laopu" : 1,
		]));

    set("outdoors", "murong");
    setup();

}
