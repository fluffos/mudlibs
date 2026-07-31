
// Room: /d/snow/school2.c

#include <room.h>

inherit ROOM;

void create()
{
        set("coor",({-200,4750,10}));
	set("short", "关宁总督府");
        set("long",
"你现在正站在一个宽敞的教练场中，地上铺著黄色的细砂，许多人正在这里努力地操练著，\n"
"宁远是军事重镇，天下精兵尽聚于此。\n"
);
 set("exits", ([ /* sizeof() = 2 */
    "north" : __DIR__"txgate",

]));
	set("objects", ([
  __DIR__"npc/wujiang" : 2,
		__DIR__"npc/txtrainer2": 1]) ); 
        set("outdoors", "ny");
        set("clean_up",1);


        setup();
}

