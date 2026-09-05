// Rewrote by iszt@pkuxkx, 2007-02-11
#include "dong.h"
inherit ROOM;

void create()
{
	setshort();
	setlong();
    set("no_task",1);
	set("exits", ([
		"east" : __DIR__"dong"+(random(16)+5),
		"south" : __DIR__"dong"+(random(11)+5),
		"west" : __DIR__"dong"+(random(6)+5),
		"north" : __DIR__"dong"+(random(1)+5),
	]));

//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
