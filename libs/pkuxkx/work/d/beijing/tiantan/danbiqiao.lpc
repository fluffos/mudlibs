
// Room: /d/beijing/west/danbiqiao.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"丹陛桥"NOR);
	set("long",
HIC"这条大道高出周围平地数尺，如同一座桥将北面的祈年殿和
南面的圜丘连接在一起。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
  	"south" : __DIR__"huangqiongyu",
  	"north" : __DIR__"qiniandian",
  	"westdown" : __DIR__"shibanlu2",
  	"eastdown" : __DIR__"shibanlu3",
]));
        set("outdoors", "beijing");
	setup();

}
void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/danbiqiao",1);
      }

}