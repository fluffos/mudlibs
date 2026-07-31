#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"清虚观"NOR);
	set("long", @LONG
清虚观是京城着名的一座道观。由于唐朝的皇帝和老子同姓，
因此道教被奉为唐朝的国教。但由于佛教的传入，道教的状况已
大大不如以前。道观中已没有几个人了。
LONG         
	);

	set("exits", ([ 
 "north" :__DIR__"zhq2",
	]));
	setup();
	replace_program(ROOM);
}

