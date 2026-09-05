#include <ansi.h>
#include "snow.h"

inherit ROOM;

void create()
{
        set("short", "小屋");
	set("long", @LONG
这是桥头的一个小屋，为路过的行人提供暂时歇脚和存马的所在。
望着门外的皑皑白雪和远处雪峰上的凌霄城，你似乎感觉到了人间仙境。
LONG);

//        set("outdoors", "凌霄城");

	set("item_desc", ([
//                "snow": (: snow :),
	]));

	set("objects", ([
//                __DIR__"npc/wolf" : 1,
	]));
     set("sleep_room", 1);
     set("no_kill", 1);
     set("no_fight", 1);
     set("no_steal", 1);

	set("exits", ([
                "southwest" : __DIR__"bridgee",
	]));

	setup();

}
