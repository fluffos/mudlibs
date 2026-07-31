#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"掌门人大会"NOR);
	set("long", @LONG
这是一个练武场，由巨大的花岗岩石板铺就，正在招开掌门人比武大会。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"kang2",
	]));
	set("objects",([
                "/kungfu/class/hu/fu" : 1,
                "/kungfu/class/hu/feng2" : 1,
                "/kungfu/class/hu/wudang" : 1,
                "/kungfu/class/hu/shaolin" : 1
	]));
	set("coor/x", -179);
	set("coor/y", 4090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
