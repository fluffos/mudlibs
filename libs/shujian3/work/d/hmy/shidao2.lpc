// /d/hmy/shidao2.c

inherit ROOM;

void create()
{
	set("short", "石道");
	set("long", @LONG
一路上日月教教众把守严密，经过两处山道，来到一处水滩之前，西面有
一道石阶通往水滩。
LONG
	);
	set("outdoors", "黑木崖");
	set("exits", ([ 
          "westdown" : __DIR__"xxtan",
	  "east" : __DIR__"liangting",
	  "south" : __DIR__"shidao",
	]));

	set("objects", ([ 
		__DIR__"npc/wang" : 1,
	]));

	setup();
}
