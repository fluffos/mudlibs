// mhshongm.c 梅花松木

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM "梅花松木" NOR, ({ "mhshong wood" }) );
        set_weight(5000);
        if (clonep())
        {
                set_default_object(__FILE__);
        } else
        {
                set("value", 20000);
                set("unit", "捆");
                set("long", 
                        "梅花松生长在秦岭海拔二千五百米以上部分山林中，树杆挺直，树形美观\n"
                        "整齐，姿态十分秀丽，是松柏中的珍品。\n");
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

