// /guanwai/huagai.c

inherit ROOM;

void create()
{
	set("short", "华盖峰");
	set("long", @LONG
长白东侧最高峰，自古以来，华盖峰就是风雨云雾的故道。云雾起处，
恰似掀开锅盖一般，雾气翻滚，池水云天，一脉相连，气壮华夏，故名华盖
峰。
LONG );
	set("exits", ([
		"north"     : __DIR__"tianhuo",
		"westdown"  : __DIR__"tianchi1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
