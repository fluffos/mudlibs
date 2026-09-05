
// Room: /d/beijing/west/huangqiongyu.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"皇穹宇"NOR);
	set("long",
HIC"这是存放祭祀神牌位的地方。外面有一道圆形磨砖对缝的围墙，是著名的
“回音壁”。南面大厅入口处放着三块石头。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"huanqiu",
  	"north" : __DIR__"danbiqiao",
]));

	setup();

}
void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/huangqiongyu",1);
      }

}