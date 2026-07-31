// baling/yaopu
// Room in 龟兹 
// laowuwu 99/04/11

inherit ROOM;

void create()
{
	set("short", "药铺");
	set("long", @LONG
这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几
百个小抽屉里散发出来的。药铺老板坐在茶几旁，独自喝着茶，看也不
看你一眼。一名小伙计站在柜台后招呼着顾客。
LONG
	);


	set("exits", ([
		"west" : __DIR__"beidajie1",
	]));
        set("objects",([
          __DIR__"npc/wang":1,
          ]));
	setup();
	replace_program(ROOM);
}

