// jianshi.c

inherit ROOM;
#include <ansi.h>

void create()
{
      set("short", HIC"剑室"NOR);
      set("long", @LONG
一间摆满兵器的石室，很多种剑都整齐地堆放在地上。周围的火把照的整
个石室灯火通明，几个古墓弟子正站在室中仔细挑选自己合手的兵刃。墙角放
着一个木制的护具架，上面挂着些古墓弟子平时防身用的护具。
LONG
        );

      set("exits", ([
          "south" : __DIR__"gmqs",
      ]));

      set("objects", ([
               "/d/village/obj/zhujian" : 4,
//            "/u/csy/kunlun/obj/sword" : 2,
//            "/u/csy/kunlun/obj/zhujian" : 2,
              __DIR__"obj/huju-jia" : 1,
      ]));
        
      setup();
}

int valid_leave(object ob, string dir)
{
        string* jian = keys(query("objects"));
        object* sword = deep_inventory(ob);
        int i = sizeof(sword), count = 0;
        while (i--)
                if (member_array(base_name(sword[i]), jian) != -1) count++;
        if (count > 1) return notify_fail("你一下子拿这么多剑，别人不要用了吗？\n");
        return ::valid_leave(ob, dir);
}


