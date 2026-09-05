// Room: /d/beijing/west/baihuayuan.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"百花园"NOR);
	set("long",
HIC"这里种满了名花异草，尤以月季为盛。一花未谢，一花
又开。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
  	"south" : __DIR__"shibanlu1",
  	"east" : __DIR__"penshuichi",

]));
        set("outdoors", "beijing");
	setup();

}
void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/baihuayuan",1);
      }

}