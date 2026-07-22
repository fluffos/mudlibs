// Modify By River 98/12/
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"大富之家"NOR);
        set("long", @LONG
这是一家大理城内的富贵人家，这家主人经商一辈子，攒了不少钱，在大
理城内盖了这么个大宅子，门口立着两个大石狮子，站着两个家丁。
LONG
       );
        set("exits", ([ 
           "north" : __DIR__"nanjie4", 
	]));

        set("objects", ([
             __DIR__"npc/jiading" : 2, 
             __DIR__"npc/mawude" : 1,
        ]));
        set("coor/x",-300);
  set("coor/y",-470);
   set("coor/z",-20);
   set("coor/x",-300);
  set("coor/y",-470);
   set("coor/z",-20);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/dafujia",1);
      }
}
