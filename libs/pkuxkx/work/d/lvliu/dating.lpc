#include <ansi.h>
#include <room.h>
#include "nodie.h"
inherit ROOM;
void create()
{
	set("short", HIG"绿柳山庄大厅"NOR);
	set("long","这里就是绿柳山庄的大厅。中堂挂着一幅「八骏图」，八驹姿态各
不相同，匹匹神骏风发。左壁悬着一幅大字文曰：「白虹座上飞，青蛇
匣中吼，杀杀霜在锋，团团月临纽。剑决天外云，剑冲日自斗，剑破妖
人腹，剑拂佞臣首。潜将辟魑魅，勿但惊妾妇。留斩泓下蛟，莫试街中
狗。」诗末题了一行小字：「夜试倚天宝剑，洵神物也，杂录说剑诗以
赞之。汴梁赵敏。」\n"NOR);
	set("exits", ([
		"north" : __DIR__"houting",
		"south" : __DIR__"gate",
		"west" : __DIR__"ceting",
		"east" : __DIR__"xiaoting",
	]));
    set("objects", ([
	    __DIR__"npc/zongguan" : 1,
        ]));
	set("no_clean_up", 1);
	setup();
}



