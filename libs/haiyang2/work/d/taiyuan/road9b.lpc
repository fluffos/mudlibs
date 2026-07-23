// /d/taiyuan/road7.c
// Room in 太原
// modify by yang

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条土路。这里风沙很大，你一不小心就迷了眼睛。这里已经
进入了回民集中居住的地方，路上不时的能见到头戴白帽，蓄着山羊胡
子的回人。
LONG );
	set("exits", ([
		"west"  : __DIR__"suoqiao",
 		"east"  : __DIR__"yinchuan",
    
		
	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



