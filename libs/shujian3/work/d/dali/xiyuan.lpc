// Modify By River 98/12/
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"戏园子"NOR);
        set("long", @LONG
这是一座大理城里鼎鼎有名的戏园，台下不时地传来票友们的叫跃，喝彩
声。场中一个大戏台，台上正演的精彩，是「武松打虎」，你也忍不住想坐下
来看看戏，放松一下筋骨。
LONG
);
        set("exits", ([ 
             "east" : __DIR__"xijie6",
	]));
        set("objects",([
              __DIR__"npc/piaoyou" : 1,
        ]));
        set("coor/x",-340);
  set("coor/y",-440);
   set("coor/z",-20);
   setup(); 
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/xiyuan",1);
      }
}
