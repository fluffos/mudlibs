// shuzhi.c
// Created by Numa 1990805

#include <ansi.h>
#include <weapon.h>
inherit F_SWORD;
inherit F_EQUIP;
inherit COMBINED_ITEM;

void set_amount(int count)
{
    unequip();
        set("weapon_prop/damage", 10*count);
        set("long", "这是"+CHINESE_D->chinese_number(count)+"枝松枝。\n");
       :: set_amount(count);
}

void create()
{
        set_name( MAG"松枝"NOR, ({ "shu zhi", "zhi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
               set("base_unit", "根");
               set("base_value", 0);
               set("base_weight", 100);
                set("long", "这是一枝树枝。\n");
                set("value", 0);
                set("material", "wood");
                set("wield_msg", "$N拿出$n，握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        set_amount(1);
        setup();
}

void init()
{
        object me = this_player();
        if (present("shu zhi",me))
                add_action("do_cuo","cuo");
}

int do_cuo(string arg)
{
        object me = this_player();
        if (!arg)
                return notify_fail("什么？\n");
        if (arg == "songzhi" || arg == "shuzhi" || arg == "shu zhi" || arg == "zhi")
        {
                if (this_object()->query_amount() <2)
                        return notify_fail("就这点松枝，撮的出来松绳末？\n");
                new(__DIR__"sheng")->move(me);
                message_vision("$N用足力气，几下就将手中的松枝撮成了一根松绳。\n",me);
                call_out("destroy",1,this_object());
               return 1;
        }
        else
                return notify_fail("你要撮什么？\n");
}

void destroy(object ob)
{
        destruct(ob);
}
