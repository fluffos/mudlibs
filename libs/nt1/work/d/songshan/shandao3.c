// Room: /d/songshan/shandao3.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
你走在嵩山山道，青松翠柏，山风岚雾，时来飘荡。远望山下
犬吠鸡啼，顿起仙凡之感。
LONG );
	set("exits", ([
		"northup"   : __DIR__"songyuesi",
		"southeast" : __DIR__"shuyuan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	setup();
	replace_program(ROOM);
}

