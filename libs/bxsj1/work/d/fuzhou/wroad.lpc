// /d/fuzhou/wroad.c 山路
// Lklv modify 2001.9.10

inherit ROOM;

void quarter_pass();

void create()
{
        set("short","山路");
        set("long",@LONG
这是西门外的一条山路。时值春日，路旁的山坡上到处开满了金黄色的油
菜花。一阵阵山风吹来，空气里弥漫着油菜花的香味。由这里向北则进入福建
武夷山区。西北方向有条小路。
LONG);
	set("outdoors", "福州");
	set("exits", ([
                "northwest" : __DIR__"wroad2",
		"east" : __DIR__"ximen",
	]));
	set("no_clean_up", 0);
	setup();
        quarter_pass();
}

void quarter_pass()
{
	string local;
	local = NATURE_D->query_daytime();

	switch(local){
		case "event_night":
		case "event_midnight":
		set("long", @LONG
这是福州城西门外的一条山路。由于是晚上，现在城门已经关了，所以来
往的过路人只能等到天亮才能进城了。由此向北则进入福建武夷山区。西北方
向还有条小路。
LONG);
		delete("exits/east");
		break;
		default: set("long", @LONG
这是西门外的一条山路。时值春日，路旁的山坡上到处开满了金黄色的油
菜花。一阵阵山风吹来，空气里弥漫着油菜花的香味。由这里向北则进入福建
武夷山区。西北方向有条小路。
LONG);
		set("exits/east", __DIR__"ximen");
		break;
	}
	call_out("quarter_pass", 60);
}
