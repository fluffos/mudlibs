// tyroad5.c 崎岖山路
// by Marz 

inherit ROOM;

#include "feng.h"

void create()
{
	set("short", "三老峰");
	set("long", 
"你走在三老峰的山路上，一边是峭壁，一边是悬崖，高高\n"
"的天柱峰(feng)在云雾中隐约可见。身旁的进香客和游人都仔\n"
"细地盯着自己的脚下，不敢抬头望一眼，惟恐一不小心摔下去。\n"
"更有强人趁机打劫，行人无不噤声闭气，只求快点赶路。\n"
	);
	set("outdoors", "wudang");

	set("exits", ([
		"westup" : __DIR__"wulao",
		"southdown" : __DIR__"hutou",
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
