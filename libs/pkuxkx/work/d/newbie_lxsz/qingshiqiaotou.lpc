// D:\xkx\d\liuxiu-shanzhuang\qingshiqiaotou.c青石桥头
// labaz  2012/10/20.
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

void create()
{
    set("short", "青石桥头");
    set("long", @LONG
这是一座断了的石桥。桥下流水缓缓流过，似乎有呜咽之声。远处
深草间有座坟，想那夜晚周遭必是磷炎抖动，凄凉无比。不知道
怎么，你一来到这里，似乎就有种英雄垂泪的无奈和悲凉之感。
LONG);

    set("outdoors","liuxiu-shanzhuang");

    set("exits", ([
         "north" : __DIR__"weiminggu",
        ])
     );

	// set("objects", ([
		// __DIR__"obj/" : 10,
		// __DIR__"obj/yeguo" : 10,
		// CLASS_D("emei")+"/ji" : 1,
                // "/kungfu/class/shenlong/zhang" : 1,
	// ]));

    setup();
}

void init()
{
	object me;
	me=this_player();
	if (me->query(NEWBIE_VILLAGE_INDEX)==get_questindex("用east、west、south等方向命令来探索未明谷周围的三块地方，并回到未明谷"))
	{
		me->set_temp("newbie/qingshiqiaotou",1);
	}
	add_action("show_quest", "quest");
}

