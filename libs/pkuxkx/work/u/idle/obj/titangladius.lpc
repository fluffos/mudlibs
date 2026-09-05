#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(YEL"泰坦之剑"NOR, ({ "titan gladius", "sword" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("no_get", 1);
                set("no_drop", "这东西不能扔。\n");
                set("no_steal", 1);
                set("no_sell", 1);
                set("long", "这是大侠泰坦仗之纵横天下的神兵利器，散发着奇异的光芒。\n");
                set("value", 500000);
                set("material", "steel");
                set("wield_msg", HIY"突然间剑芒暴涨，$N手中已多了一把" + YEL "泰坦之剑" NOR + "。\n");
                set("unwield_msg", YEL"只见异光一闪，$N利索地将剑收入鞘中\n" NOR);
        }
        init_sword(200);
        setup();
}

void init()
{
        if (environment()->query("name") != "泰坦")
        {
                message_vision(query("name")+"委屈地叫到：「你不是我的主人！」\n",this_player());
                message_vision(query("name")+"从$N的身上掉了下来，在地上滚了滚，不见了。\n",this_player());
                destruct(this_object());
                return;
        }
}
