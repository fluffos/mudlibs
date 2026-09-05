
// Room: /d/beijing/west/zaichufang2.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"宰牲房"NOR);
	set("long",
HIC"这里是宰杀祭祀用的牲畜的地方。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
  	"northwest" : __DIR__"huanqiu",
]));

	setup();

}
void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/zaichufang2",1);
      }

}