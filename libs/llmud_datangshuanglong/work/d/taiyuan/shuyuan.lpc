// /d/taiyuan/shuyuan.c
// Room in 太原
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "书院");
	set("long", @LONG
这是一位大儒晚年开的书院，门前的书架上放满了四书五经，子经
典集之类的书集，两旁的柱上有一幅对联，后壁上挂着一幅“竹幽图”
是那位大儒晚年之作。
LONG
	);
set("exits", ([
                "east" : __DIR__"nandajie1", 
	]));
	set("objects",([
	__DIR__"npc/zhao":1,
	]));
       setup();
	replace_program(ROOM);
}	
