
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"大门"NOR);
	set("long", @LONG
你正站在一座豪华的府门前，门前有两只极大的石狮子，门
上高悬一块横匾，上书「恭亲王府」四个金字。门外有官兵把
守，戒备森严。
LONG
	);

	set("exits", ([
        "east" : __DIR__"tingyuan",
	]));
    set("password","TZD1H");
    set("max_contain_items",1);
	setup();
}

