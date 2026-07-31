//shilu3.c by river

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "小石路");
        set("long", @LONG
这是一条青石板铺成的小路，两边绿树成荫，不时有些仆人和丫鬟从你身
边走来走去。西面是练武场，很多武馆弟子正在那里发奋练功。往东走就到了
前院，一群弟子围在那里，不知道在看什么。
LONG);
	//set("outdoors","武馆");
	set("no_fight",1);
        set("exits", ([               
		   "east" : __DIR__"dayuan",
		   "west" : __DIR__"wuchang2",
        ]));          
        
        set("objects", ([
        ]));
        setup();
}
