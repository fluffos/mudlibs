
// Room: /d/beijing/west/shibanlu3.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"石板路"NOR);
	set("long",
HIC"这是一条青石板路，两边种了不少柏树，显得庄严肃穆。
往东走是东天门，西面是条大道，一阵阵浓郁的花香扑鼻
而来。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"westup" : __DIR__"danbiqiao",
  	"east" : __DIR__"dongtianmen",
]));
        set("outdoors", "beijing");
	setup();

}
void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/shibanlu3",1);
      }

}