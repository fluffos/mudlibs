// Room: /city2/aobai3.c
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIY"鳌府大院"NOR);
	set("long",
HIC"你走进大院，迎面是一个假山水池，池中立着一块巨大无比的翡翠，
显然是鳌拜收刮来的宝物。水池的两旁种满了花草。北边是厨房，有一
棵槐树，郁郁葱葱，遮盖了大半个院子，显得阴森恐怖。西边一条长廊
走道通往后院，有几个官兵把守。\n"NOR
	);
	set("exits", ([
		"west" : __DIR__"aobai4",
		"east" : __DIR__"aobai2",
		"north" : __DIR__"aobai5",
	]));
	set("outdoors", "beijing");
	set("objects", ([
                __DIR__"npc/wuzhirong" : 1,
	]));
	setup();
	replace_program(ROOM);

}



