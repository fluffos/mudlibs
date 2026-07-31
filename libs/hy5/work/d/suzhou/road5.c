// Room: /d/suzhou/road5.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人
骑着马匆匆而过。北面就是苏州城了。西南边远远望去，波光
粼闪，白帆点缀，便是周遭五百里的太湖了。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"nanmen",
		"southwest" : "/d/mr/hubian",
		"east"     : "/p/newweapon/road1",
	]));
	setup();
	replace_program(ROOM);
}

