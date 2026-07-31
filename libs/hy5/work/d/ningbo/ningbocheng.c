// Room: /u/beyond/ningbo/ningbocheng.c 宁波城
// Beyond make 1997.6.8
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "宁波城");
	set("long", @LONG
宁波城是本府的大城，立来是兵家必争之地。故州治在此驻扎重兵，盘
查南来北往的行人，并负责翦灭附近山上的草寇。城内一队队官兵来来去去，
一派森严气象。这里的海港是与外交往的重要通道。
LONG
	);
        set("objects",([
        __DIR__"npc/wujiang" : 1,
        __DIR__"npc/bing" : 3,
        ]));
	set("exits", ([
	"west" : __DIR__"ttcsi",
        "northwest" : __DIR__"aywsi",
        "south" : __DIR__"kedian",
        "east" : __DIR__"dongqianhu",
	]));
	setup();
        replace_program(ROOM);
}
