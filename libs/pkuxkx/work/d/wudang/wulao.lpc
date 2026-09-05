// tyroad6.c 崎岖山路
// by Marz 

inherit ROOM;

#include "feng.h"

string* npcs = ({
        "tufei2",
        "guest",
        "xiao_tufei",
        "guest",
        "xiao_louluo",
        "guest",
});

void create()
{
    int i = random(sizeof(npcs));

	set("short", "五老峰");
	set("long", 
"你走在五老峰的山路上，一边是峭壁，一边是悬崖。高高\n"
"的天柱峰(feng)笼罩在云雾中，隐约可见。可是身旁的进香客\n"
"和游人都仔细地町着自己的脚下，不敢抬头望一眼，惟恐一不\n"
"小心摔下去。更有强人趁机打劫，行人无不噤声闭气，只求快\n"
"点敢路。\n"
	);
	set("outdoors", "wudang");

	set("exits", ([
		"eastdown" : __DIR__"sanlao",
		"westup" : __DIR__"wuya",
		"northup" : __DIR__"taizi",
	]));

    set("item_desc", ([
        "feng" : (:look_feng:),
    ]));

    set("objects", ([
    __DIR__"npc/"+npcs[i] : 2,
    ]));

	setup();
}

void init()
{
        add_action("look_feng", "look");

}
