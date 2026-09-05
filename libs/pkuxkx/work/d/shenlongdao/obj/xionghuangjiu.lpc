//雄黄酒
//by kiden

#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_drink", "drink");
}
void create()
{
        set_name(HIY"雄黄酒"NOR, ({"xionghuang jiu", "jiu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "杯");
                set("long", "这是一杯神龙教的雄黄酒，据说喝了之后可以驱邪避毒.\n");
                set("value", 100);
        }
        setup();
}
int do_drink(string arg)
{
        object me=this_player();
        if (!id(arg))
                return notify_fail("你要喝什么？\n");
/*
        if (me->query("family/family_name")!="神龙教")
        return notify_fail("你端起酒杯想喝，又害怕有什么古怪，琢磨不定，最终还是放了回去！\n");
*/
        if (me->query("shenlong/antisnake")>0)
        return notify_fail("雄黄酒喝多了对身体并没有什么好处！\n");

        me->set("eff_qi", me->query("max_qi"));
        me->set("qi", me->query("max_qi"));   
message_vision(HIY"$N端起酒杯，一口将雄黄酒喝了下去 !\n" NOR, me);
        me->set("shenlong/antisnake",1);

        destruct(this_object());
        return 1;
}

