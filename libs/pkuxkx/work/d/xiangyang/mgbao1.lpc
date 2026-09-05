#include <ansi.h>
inherit ROOM;

void create ()
{
    set("short",YEL"蒙古营前"NOR);
set("outdoors","menggu");
    set("long",
  YEL"这里是一座蒙古军营之前,几个蒙古牧民正在里面忙碌着。\n草原上的民族平时为民，战时为兵，几乎全面皆兵。\n"NOR
       );
 
    set("exits", ([
        "north" :   __DIR__"mgbao2",
        "south" :   __DIR__"caoyuan4", 
        ])); 
    set("objects",([
		__DIR__"npc/mumin" : 1,
	]));
    setup();
}
