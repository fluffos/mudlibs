// /d/mingjiao/mchukou.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short","秘道出口");
       set("long", @LONG
这里是明教秘道出口。
LONG
     );
    
	set("exits", ([
		"up" : __DIR__"bidao7",
	]));    

        setup();
}

void init()
{
	object me,room;
	me=this_player();
	room=this_object();
	message_vision(YEL"\n$N终于走出了秘道。\n\n"NOR,me);
}
