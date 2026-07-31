// zitanm.c 紫檀木

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(MAG "紫檀木" NOR, ({ "zitan wood" }) );
        set_weight(5000);
        if (clonep())
        {
                set_default_object(__FILE__);
        } else
        {
                set("value", 20000);
                set("unit", "捆");
                set("long", 
                        "紫檀又称青龙木，木材呈棕红色，坚重细致，通称红木。后世岳阳楼上。\n"
                        "著名的《岳阳楼记》便是刻在十五块紫檀木上。\n");
        }
        setup();
}

int fire(object me, object ob)
{
        object fire;

        if (environment()->query_temp("warm") >= 40)
                return notify_fail("这里已经够热的了，你还是换个地方点火吧。\n");

        message_vision("$N用" + ob->name() + "点燃了" + name() +
                       "，一片红红的火光映红了四周。\n", me);

        fire = new("/clone/misc/needfire");
        fire->move(environment(me));

        destruct(this_object());
        return 1;
}

