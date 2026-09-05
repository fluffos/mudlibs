// Rewrote by iszt@pkuxkx, 2007-02-11
#include "dong.h"
inherit ROOM;

void create()
{
	setshort();
	setlong();
    set("no_task",1);
	set("exits", ([
		"east" : __DIR__"dong"+(random(17)+4),
		"south" : __DIR__"dong"+(random(12)+4),
		"west" : __DIR__"dong"+(random(7)+4),
		"north" : __DIR__"dong"+(random(2)+4),
	]));

//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
