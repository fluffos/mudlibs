// Room: /d/songshan/dadian.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "中岳大殿");
	set("long", @LONG
大殿面阔九间，进深五间，重檐庑殿式屋顶，座落在七尺高的台
基上，气势雄伟。大殿中供奉岳神天中王。
LONG );
	set("exits", ([
		"northup" : __DIR__"shandao1",
		"south"   : __DIR__"chongsheng",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

