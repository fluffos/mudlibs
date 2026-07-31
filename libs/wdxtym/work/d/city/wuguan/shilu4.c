//shilu4.c by river

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一条青石板铺成的小路，两边绿树成荫，不时有些仆人和丫鬟从你身
边走来走去。往西走就到了前院，一大群弟子围在那里，不知道在看什么。东
边过去就能到练武场了，南面是一间偏厅。
LONG);
	set("outdoors","武馆");
	set("no_fight",1);
        set("exits", ([               
		   "west" : __DIR__"dayuan",
		   "east" : __DIR__"wuchang3",
		   "south" : __DIR__"liangong",
        ]));          

        set("objects", ([
        ]));

        setup();
}
