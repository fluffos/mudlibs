
// Room: /d/snow/hockshop2.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "储藏室");
	set("long",
"这里是丰登当铺的储藏室，有时候当铺里的大朝奉会把铺里存不下的死当货物拿出来拍卖，\n"
"不过你现在只能看见一个个锁著的箱子。往西边穿过一道布就可以回到当铺店面。\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"hockshop",
]));

	setup();
	replace_program(ROOM);
}
