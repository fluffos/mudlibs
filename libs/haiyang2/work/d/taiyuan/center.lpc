// /d/taiyuan/center.c
// Room in 太原
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "太原广场");
	set("long", @LONG
这里是太原的城中心广场，钟楼二楼立在广场的两边，四面都是太
原的主要街道，商家云集，一眼望去，车水马龙，人山人人海好不热闹。
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "north" : __DIR__"beidajie2", 
                "south" : __DIR__"nandajie2", 
                "east" : __DIR__"dongdajie2", 
                "west" : __DIR__"xidajie2",       
	]));
	set("objects",([
	__DIR__"npc/xiake":1,
	]));
       setup();
	replace_program(ROOM);
}	
