// Room: /u/beyond/ningbo/tianyige.c 天一阁
// Beyond make 1997.6.8
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "天一阁");
	set("long", @LONG
天一阁名字相传为《易经》中“天一生水，地六成之”之说而来，取以
水火克之意。阁旁垒石为山，环植竹木，依墙立一半亭，旁边池中小桥穿越
林石之间，垒石似狮、象、羊、虎等动物，山似“福”、“禄”、“寿”之
型。令人遐想，意趣无穷。
LONG
	);

	set("exits", ([
"northwest" : __DIR__"qsddao",
		"west" : __DIR__"shilu",
                "southeast" : __DIR__"aywsi",
	]));
	setup();
        replace_program(ROOM);
}
