// Rewrote by iszt@pkuxkx, 2007-02-11
#include "dong.h"
inherit ROOM;

void create()
{
	setshort();
	setlong();
    set("no_task",1);
	set("exits", ([
		"east" : __DIR__"dong"+(random(20)+1),
		"south" : __DIR__"dong"+(random(15)+1),
		"west" : __DIR__"dong"+(random(10)+1),
		"north" : __DIR__"dong"+(random(5)+1),
	]));
	setobject();

//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
