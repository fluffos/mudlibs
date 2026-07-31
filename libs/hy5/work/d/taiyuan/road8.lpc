// /d/taiyuan/road7.c
// Room in 太原
// modify by yang

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这里是一条土路。这里风沙很大，你一不小心就迷了眼睛。东边就
是黄河的渡口了。从这里可以听到黄河流水的声音。
LONG );
	set("exits", ([
		"southwest"  : __DIR__"road8b",
 		"east"  : __DIR__"dukou2",
   	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



