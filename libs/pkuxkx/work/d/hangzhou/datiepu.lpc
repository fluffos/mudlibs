
#include <ansi.h>
#include <localtime.h>
// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
void create()
{
        set("short", "打铁铺");
        set("long", @LONG
这是临安府里普通的一家打铁铺，以维修兵器著称。只要兵器没断，无论损
坏程度如何，都能给修好了。当然，价格也是不菲的。
LONG
        );

        set("exits", ([
               "south" : __DIR__"dongdajie2",
        ]));
        set("objects", ([
                __DIR__"npc/tiejiang":1,   
                __DIR__"npc/huoji":1,
				"/d/city/obj/furnace":1,
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