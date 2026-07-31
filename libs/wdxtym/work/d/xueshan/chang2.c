// chang.c 练武场
// Designed by secret (秘密)
// 97/04/09

inherit ROOM;

void create()
{
	set("short", "大练武场");
	set("long", @LONG
这里是雪山寺的大练武场，树着好多木桩和沙袋，僧
人们日常均在此刻苦习武。往东就是广场，西边一直穿过
大连武场有个小库房。
LONG );
	set("outdoors", "xueshan");

	set("exits", ([
		"east" : __DIR__"guangchang",
		"west" : __DIR__"chang",
	]));

	set("objects", ([
		    __DIR__"npc/x_lama" : 1,
	    "/clone/npc/mu-ren" : 4,
	]));

	setup();
}

