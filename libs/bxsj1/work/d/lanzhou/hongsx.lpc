//By River@Sj

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "红山峡");
	set("long", @LONG
红山峡是个非常险峻的峡谷，两边是数十丈的黄土坡，很是陡峭，中间只
有一条可以通行一人一马的窄道，俗称“一线天”。附近没有什么生物，却有
商旅常在这里失踪。
LONG );
	set("exits", ([
		"north"     : __DIR__"shimen",
		"southeast"     : __DIR__"jintai",
	]));
	set("objects", ([
		__DIR__"npc/mazei" : 1,
	]));

	set("outdoors", "西夏");
	setup();
}
