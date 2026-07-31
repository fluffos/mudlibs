// Room: /d/fuzhou/nandajie.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "城中心");
	set("long", @LONG
这里是白云城的正中心，一个很宽阔的广场，铺着青石地面，一片萧静。
LONG );
	set("exits", ([
		"south"   : __DIR__"nanmendou",
		"north"   : __DIR__"dongjiekou",
		"east"    : __DIR__"weizhongwei",
		"west"    : __DIR__"yamen",
		"northwest" : __DIR__"jingji/enter",
	]));
	set("objects", ([
			"/kungfu/class/baiyun/bai" : 1,
	]));
	set("outdoors", "by");
	//setup();
}
	
