// Modified by iszt@pkuxkx, 2007-04-03

#include <ansi.h>

inherit ROOM;

void create ()
{
	set("short",BLK"黑松寨山门"NOR);
	set("outdoors","xiangyang");
	set("long",CYN @LONG
前面突然出现了一片空地，迎面是一座破旧的山寨，寨门只剩下半扇，门口
有座石碑，隐约可辨有几个字：黑松寨。
LONG NOR);
	set("objects", ([
		__DIR__"npc/tufei" : 1,
        ]));  
	set("exits", ([
		"westdown" : __DIR__"eroad5",
                "north"  : __DIR__"hszhai",
	]));
        setup();
	replace_program(ROOM);
}