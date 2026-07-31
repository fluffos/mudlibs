// chang3.c 小练武场

inherit ROOM;

void create()
{
	set("short", "小练武场");
	set("long", @LONG
这里是雪山寺的小练武场，树着好多木桩和沙袋，僧
人们日常均在此刻苦习武。往南走就是大练武场，许多雪
山弟子在那里练功。
LONG );
	set("outdoors", "xueshan");

	set("exits", ([
		"north" : __DIR__"houyuan",
		"south" : __DIR__"chang",
	]));

	set("objects", ([
	    	"/clone/npc/mu-ren" : 3,
	]));

	setup();
}

