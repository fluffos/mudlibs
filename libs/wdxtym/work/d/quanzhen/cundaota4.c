// cundaota4.c 存道塔顶
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "存道塔顶");
	set("long", @LONG
这里是存道塔的塔顶，塔梯到这里就到了尽头。墙壁上开着几
个窗户(window)，几个中年道人正捧着书苦苦研读。
LONG
	);
	set("exits", ([
		"southdown" : __DIR__"cundaota3",
	]));
	set("objects", ([
		__DIR__"npc/zhangjing" : 1,
	]));

	set("item_desc", ([
		"【窗口】": "窗外白云飘过，似乎你一伸手就可以抓住一片。\n",
	]) );

	set("count",1);
	setup();
}

