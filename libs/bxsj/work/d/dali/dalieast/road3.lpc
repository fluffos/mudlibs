// Modify By River 98/12
#include <ansi.h>
#include <room.h>;
inherit ROOM;

void create()
{
        set("short", HIW"山间小路"NOR);
        set("long", @LONG
你前面一个山岗，路开始逐渐平坦，但是仍不好走，你不断的拨开挡在路
上的杂草，荆棘。偶尔听到一阵阵的野兽叫声，头顶有一些不知名的小鸟在跳
来跳去，四周丛林密布，鲜花绿草若隐若现。
LONG);
        set("outdoors", "大理");
        set("exits", ([             
               "southeast" : __DIR__"road4",   
               "westdown" : __DIR__"road2",   
        ]));

        set("coor/x",-240);
  set("coor/y",-410);
   set("coor/z",0);
   setup();
}

void init()
{
      object me = this_player();
      if (me->query_temp("xuncheng") && random(20) < 3 ){
      me->move(__DIR__"road"+(random(3)+1));
      }
}
