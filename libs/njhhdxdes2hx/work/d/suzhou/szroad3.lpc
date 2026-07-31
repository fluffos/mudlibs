//ROOM: d/suzhou/szroad3.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"大驿道"NOR);
	set("long", @LONG
	    你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的行商，赶着
大车的马夫，上京赶考的书生，熙熙攘攘，非常热闹。不时还有两三骑快马从身边飞
驰而过，扬起一路尘埃。道路两旁是整整齐齐的杨树林。
LONG
	);
	set("no_sleep_room",1);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"szroad2",
		"east" : __DIR__"szroad4",
	]));
	set("objects", ([
		__DIR__"npc/ren" : 1,
	]));
	setup();
}





