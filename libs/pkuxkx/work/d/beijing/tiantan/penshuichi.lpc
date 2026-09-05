
// Room: /d/beijing/west/penshuichi.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"喷水池"NOR);
	set("long",
HIC"这是一个广场，正中有个水池，池中尾尾金鱼在悠闲的漫游。
水池中有块高达数丈的太湖石，数道水流从顶部向下流，行成一道
道小小的瀑布。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"west" : __DIR__"baihuayuan",
  	"south" : __DIR__"shibanlu2",
]));
        set("outdoors", "beijing");
	setup();

}
void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/penshuichi",1);
      }

}