// wlshongm.c 武陵松木

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW "武陵松木" NOR, ({ "wlshong wood" }) );
        set_weight(5000);
        if (clonep())
        {
                set_default_object(__FILE__);
        } else
        {
                set("value", 20000);
                set("unit", "捆");
                set("long", 
                        "武陵松又叫岩松，广泛生长于峰林石崖上，或散挂于石壁缝隙之间。它们\n"
                        "生命力旺盛，长相奇特，刚劲挺拔，木质极佳。\n");
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

