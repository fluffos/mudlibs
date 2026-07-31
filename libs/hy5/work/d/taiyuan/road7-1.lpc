// /d/taiyuan/road7.c
// Room in 太原
// modify by yang

inherit ROOM;

void create()
{
	set("short", "小道");
	set("long", @LONG
你走在一条弯弯得小道上。四周人很少。小道两旁全是一根根的野
草。无名的野在草丛里开放，花西北方向就是五岳中的恒山了，向南走
不远就进入魏地许城。
LONG );
	set("exits", ([
		"north"  : __DIR__"road5",
 		"south"  : __DIR__"road7-2",
		
	]));
	
 	set("outdoors", "taiyuan");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



