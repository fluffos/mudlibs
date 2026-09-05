inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "山坡");
  set ("long", @LONG

一条小路的尽头是一个小小的山坡，开满了五彩的花儿。山坡
上有几棵大树，顺着山坡蜿蜒而下，山坡的下面是一个山
谷，再远一些就看不大清楚了。
LONG);
   set("exits", 
      ([ 
                "westdown": __DIR__"ynv_shanlu3",
                "northdown": __DIR__"ynv_shangu",
      ]));
  set("objects", 
      ([ /* sizeof() == 2 */
                 __DIR__"npc/ynj_bgg" : 1,
      ]));

        set("outdoors", 1);
  setup();
}

int valid_leave(object me, string dir)
{       
        object a;
        if( wizardp(me)) return ::valid_leave(me, dir);

        if (dir == "northdown") {
                if(objectp(a=present("bai yuan", environment(me))) && living(a) )
                return notify_fail("白猿哼的一声，挡在你的前面！\n");
        return ::valid_leave(me, dir);
        }

        return 1;
}
