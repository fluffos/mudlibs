// /guanwai/huagai.c

inherit ROOM;
#include "/d/changbai/caishen.h";

void create()
{
	set("short", "华盖峰");
	set("long", @LONG
长白东侧最高峰，自古以来，华盖峰就是风雨云雾的故道。云雾起处，
恰似掀开锅盖一般，雾气翻滚，池水云天，一脉相连，气壮华夏，故名华盖
峰。据说在这周围的杂草之中就生长着人参，不知道搜索一下能否有所发现。
LONG );
	set("exits", ([
		"west"     : __DIR__"tianhuo",
//		"westdown"  : __DIR__"tianchi1",
	]));

	set("outdoors", "changbai");

        set("count", random(3) + 1);
        set("beast", random(5) + 1);

	setup();

}
