// hongshongm.c 松木红

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR "红松木" NOR, ({ "hongshong wood" }) );
        set_weight(5000);
        if (clonep())
        {
                set_default_object(__FILE__);
        } else
        {
                set("value", 20000);
                set("unit", "捆");
                set("long", 
                        "红松，又称海松，大多分布在中国东北林区。红松木材质软硬适中，纹理\n"
                        "通直，色泽美观，不翘不弯，容易加工，耐腐耐蛀，是北方最主要的木材\n"
                        "原料。\n");
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

