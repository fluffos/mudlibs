//OBJ:/d/lingshedao/obj/tlblade.c
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(HIC"屠龙刀"NOR, ({ "tulong dao", "dao" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("treasure",1);
                set("unit", "把");
                set("long", "这便是号称武林至尊的屠龙刀,刀身黑黝无光,
相传是郭靖黄蓉夫妇所造,是武林中人梦寐以求的神物.\n");
        set("value", 100000);
                set("material", "steel");
                set("no_get",1);
                set("no_put",1);
                set("no_drop","天下不知有多少人觊觎这把宝刀,你怎能把它扔了?\n");
                set("no_give","搞错没?这么好的宝物怎能送人?\n");
                set("wield_msg", HIC"屠龙刀悄无声息的到了$N手中,四周
顿时寒气逼人,腾然升起一股杀气.\n" NOR);
                set("unwield_msg",HIC"$N还刀入鞘,刀上发出非金非木的
沉郁之声,杀气也渐渐消隐下去.\n"NOR);
             }
                init_blade(600); 
                setup();
}


void owner_is_killed()
{
       destruct(this_object());
}

int query_autoload()
{
       return 1;
}
