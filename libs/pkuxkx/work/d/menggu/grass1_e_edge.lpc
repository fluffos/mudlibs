// Room: grass.c 草原
// created by Zine 30 Aug 2010

inherit ROOM;
#include "/d/menggu/entry_migong.h",
void create()
{
	set("short", "草原");
	set("long", @LONG
一望无际的草原，和天边连成一片。北面是一片蒙古包。
LONG
	);

	set("exits", ([
		"west" : __DIR__"grass1",
        "south" : __DIR__"grass3",
		"northeast" : __DIR__"grassedge",
	]));
	
	set("entry_direction","northeast");
    set("migong","/d/menggu/caoyuan1");
    set("migong_posi","west");
    set("look_refuse_msg","科尔沁草原上刮起了大风，你什么都看不清了。\n");
    set("enter_refuse_msg","科尔沁草原上刮起了大风，这会儿进去太危险了。\n");
    set("objects", ([
        	__DIR__"npc/leader" : 1,
	    ]));
    set("outdoors", "menggu_e");
	setup();
}
void init()
{
    add_action("do_look","look");
}
