// Room: /d/huashan/hole-1.c
// Date: Look 99/03/25

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "窄道");
	 set("long", @LONG
这里非常黑暗，伸手不见五指，你什么也看不见。
LONG);
        set("no_clean_up", 0);
        setup();
}
 
int init()
{
	add_action("do_use","use");
}

int do_use(string arg)
{
	object me;
	object room;
	object fire;
	me = this_player();
       if (!(fire=present("fire", me)))  return 0;
	if ( !arg || arg =="") return 0;
	if ( arg != "fire" ) return 0;
	write(	"你点燃了火折，只见这是一条窄窄的孔道，你继续往前走了十余丈，孔\n"
		"道仍然未到尽头。再行数丈，顺着甬道转而向左，眼前出现了一个极大\n"
		"的石洞。\n");
	if ( !(room == find_object(__DIR__"hole-2")) )
		room = load_object(__DIR__"hole-2"); 
	set("exits/west", __DIR__"hole-2");
	set("exits/out", __DIR__"hole");
	call_out("close_out",10);

	return 1;
}

int close_out()
{
	object room;
        if (! (room == find_object(__DIR__"hole-1")) )
		room = load_object(__DIR__"hole-1"); 
	room->delete("exits/out");
	room->delete("exits/west");
	return 0;
}