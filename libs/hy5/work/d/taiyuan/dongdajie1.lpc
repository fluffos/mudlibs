// /d/taiyuan/dongdajie1.c
// Room in 太原
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "东大街");
	set("long", @LONG
大街有两辆马车那么宽，再向东走就是太原的东门了，北面是太原
的皇宫，南面是太原的国宾馆。
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "north" : __DIR__"huanggong", 
                "south" : __DIR__"guobingguan", 
                "east" : __DIR__"dongmen", 
                "west" : __DIR__"dongdajie2",       
	]));
	set("objects",([
	__DIR__"npc/yegou":1,
	]));
       setup();
	replace_program(ROOM);
}	
