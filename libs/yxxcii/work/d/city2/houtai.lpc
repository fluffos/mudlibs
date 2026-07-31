//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "戏院后台");
	set("long", @LONG
这里是戏院后台，几个戏子正在化妆。一个个大花脸，让人倍感新鲜
。东边墙上挂满了许多戏服，长袍短袍，大褂等等，一应俱全。从北边可
以上台。
LONG
);
	set("outdoors", "city2");
	set("exits", ([
		"west" : "/d/city2/xiyuan",
		"northup" : "/d/city2/stage",
	]));
	set("objects", ([
		"/d/city2/npc/xizi" : 2,
	]));

	setup();
	replace_program(ROOM);
}
