// /d/taiyuan/road7.c
// Room in 太原
// modify by yang

inherit ROOM;

void create()
{
	set("short", "索桥");
	set("long", @LONG
这是一条横跨在黄河上的索桥，九曲十八弯的黄河在这里蜿蜒向北
流去，一阵风吹来，索桥随风晃动，你不禁的抓紧了身旁的绳子。
LONG );
	set("exits", ([
		"west"  : __DIR__"road9",
 		"east"  : __DIR__"road9b",
        		
	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



