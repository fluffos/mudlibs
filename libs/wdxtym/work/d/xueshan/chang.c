// chang.c 练武场
inherit ROOM;

void create()
{
	set("short", "大练武场");
	set("long", @LONG
这里是雪山寺的大练武场，树着好多木桩和沙袋，僧
人们日常均在此刻苦习武。往东走穿过整个大练武场就是
广场，西边有个小库房，南边一大片开阔地，就是雪山闻
名海内的祭坛了。
LONG );
	set("outdoors", "xueshan");

	set("exits", ([
		"east" : __DIR__"chang2",
		"west" : __DIR__"kufang",
		"north" : __DIR__"chang3",
		"south" : __DIR__"jitan",
	]));

	set("objects", ([
		__DIR__"npc/x_lama" : 1,
	    	"/clone/npc/mu-ren" : 4,
	]));

	setup();

}
