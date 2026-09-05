// hutou.c 虎头岩
// by Marz 

inherit ROOM;

#include "feng.h"

void create()
{
	set("short", "虎头岩");
	set("long", 
"你走在虎头岩山路上，一边是峭壁，一边是悬崖。高高的\n"
"天柱峰(feng)笼罩在云雾中，隐约可见。可是身旁的进香客和\n"
"游人都仔细地町着自己的脚下，不敢抬头望一眼，惟恐一不小\n"
"心摔下去。更有强人趁机打劫，行人无不噤声闭气，只求快点\n"
"敢路。\n"
	);
	set("outdoors", "wudang");

	set("exits", ([
		"eastdown" : __DIR__"shijie16",
		"northup" : __DIR__"sanlao",
	]));

    set("item_desc", ([
        "feng" : (:look_feng:),
    ]));

	setup();
}

void init()
{
        add_action("look_feng", "look");
}
