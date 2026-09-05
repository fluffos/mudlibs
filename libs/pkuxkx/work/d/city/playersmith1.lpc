// Room: /city/playersmith1.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "虫二的地下城铁铺");
        set("long", @LONG
这是地下城一家简陋的打铁铺，中心摆着一个巨大的熔炉，你从来没见过这么牛逼
的熔炉，显然是件宝物。你不禁把注意力转向这件宝贝的拥有者，只见炉边站着
一个又黑又壮的铁匠，正满头大汗得挥舞着铁锤，根本没注意到你的闯入。
LONG);
        set("exits", ([
                "north" : __DIR__"undergrounde1",
        ]));
        set("objects", ([
            "/d/city/obj/furnace":1,
            "/d/city/npc/smith":1,
        ]));
        set("owner_id","becool");
        set("owner_name","虫二");
        set("balance",0);
        set("rate_gold",10);
        setup();
}

int valid_leave(object me, string dir)
{
        object obj = present("rong lu", environment(me));
        if (me->query_temp("is_forging") && obj->query("in_use") == me->query("id"))
          {
            message_vision(HIR"你正在锻造中，离开铁铺的话可要小心别人偷熔炉里面你的东西哦！\n"NOR,me);
            me->delete_temp("is_forging");
            obj->delete("in_use");
          }
        return ::valid_leave(me, dir);
}