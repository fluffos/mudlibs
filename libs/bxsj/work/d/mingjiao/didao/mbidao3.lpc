// /d/mingjiao/diechong3.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short","秘道");
       set("long", @LONG
这里是明教秘道，你似乎迷失了方向，象没头苍蝇般到处乱闯。
LONG
     );
    
	set("exits", ([
		"east" : __DIR__"mbidao4",			
		"south" : __DIR__"mbidao"+(random(5)+1),
		"west" : __DIR__"mbidao"+(random(5)+1),
		"north" : __DIR__"mbidao2",
	]));    
	
        setup();
       
}

void init()
{
	object me,room;
	me=this_player();
	room=this_object();
	message_vision(YEL"\n$N一不小心，在秘道中迷路了！看来要走出去要花很多时间。\n\n"NOR,me);
}
