// fenghuangm.c 望天木

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW "望天木" NOR, ({ "wangtian wood" }) );
        set_weight(5000);
        if (clonep())
        {
                set_default_object(__FILE__);
        } else
        {
                set("value", 20000);
                set("unit", "捆");
                set("long", 
                        "望天树在傣语称为麦撑伞。生长于滇南及滇东的勐腊。木质极佳，是当地\n"
                        "常见木材原料。\n");
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

