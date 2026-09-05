#include <ansi.h>
inherit ROOM;

void create ()
{
    set("short",GRN"荒原"NOR);
set("outdoors","xiangyang");
set("occupied",1);
    set("long",
  GRN"南宋和蒙古长期的拉锯战，让襄阳北面一片荒芜。\n看来快到蒙古人的驻地了.\n"NOR

       );
 
    set("exits", ([/*sizes of 3*/
        "north" :   __DIR__"mgbao1",
        "south" :   __DIR__"caoyuan3", 
        ])); 
    set("objects",([
		__DIR__"npc/myren" : 1,
		__DIR__"npc/mudog" : 1,
                __DIR__"npc/sheep" : 2,
	]));
        setup();
}
