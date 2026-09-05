
// Room: /d/beijing/west/huanqiu.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"圜丘"NOR);
	set("long",
HIC"圜丘坛为皇帝冬至祭天之所，坐北朝南，四周绕以红色宫墙，
上饰绿色琉璃瓦。圜丘坛是一座四周由白石雕栏围护的三层石造
圆台，洁白玉，极其壮观美丽。 。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
  	"southeast" : __DIR__"zaichufang2",
  	"north" : __DIR__"huangqiongyu",
  	"southdown" : __DIR__"shibanlu5",
]));
        set("outdoors", "beijing");
	setup();

}
void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/huanqiu",1);
      }

}