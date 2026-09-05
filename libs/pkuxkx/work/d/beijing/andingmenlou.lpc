
// Room: /d/beijing/east/andingmenlou.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"安定门城楼"NOR);
	set("long",
HIY"这是安定门城门上的望楼，一队队壮健的守城军丁盔甲鲜
明，手持大刀长矛，强弓利箭，警惕的注视着城下过望行人；
城门两边是长长的北京外城墙。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
  	"west" : __DIR__"chengqiang1",
  	"down" : __DIR__"andingmen",
  	"east" : __DIR__"chengqiang2",
]));
	set("objects", ([
		__DIR__"npc/wujiang": 1,
		]));

	setup();

}
void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/andingmenlou",1);
      }

}
int valid_leave(object me, string dir)
{
	if(dir == "down" && me->query("id") == "wu jiang")
	return 0;

    	return ::valid_leave(me, dir);
}