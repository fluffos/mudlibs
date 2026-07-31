//shilu2.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
这是一条青石板铺成的小路，两边绿树成荫，不时有些仆人和丫鬟从你身
边走来走去。往北就是西练武场了，南面传出马匹的嘶鸣声，而西面传来很吵
杂的响声，东面却是静悄悄的。
LONG);
        
	set("no_fight", 1); 
	//set("outdoors","武馆");

        set("exits", ([
               "north" : __DIR__"wuchang2",
               "south" : __DIR__"mafang",
               "east" : __DIR__"shuifang",
	       "west" : __DIR__"mufang",
        ]));          

        setup();
}
