// hhtanm.c 黑黄檀木

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "黑黄檀木" NOR, ({ "hhtan wood" }) );
        set_weight(5000);
        if (clonep())
        {
                set_default_object(__FILE__);
        } else
        {
                set("value", 20000);
                set("unit", "捆");
                set("long", 
                        "黑黄檀多产于中国西南的山地。材质坚硬，纹理美观典雅，结构细致，入\n"
                        "水即沉，不开裂，不变形，是各种工具的极品。\n");
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

