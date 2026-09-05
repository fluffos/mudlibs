// Rewrote by iszt@pkuxkx, 2007-02-11
#include "dong.h"
inherit ROOM;

void create()
{
	setshort();
	setlong();
    set("no_task",1);
	set("exits", ([
		"east" : __DIR__"dong"+(random(18)+3),
		"south" : __DIR__"dong"+(random(13)+3),
		"west" : __DIR__"dong"+(random(8)+3),
		"north" : __DIR__"dong"+(random(3)+3),
	]));

//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
