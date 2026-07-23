// xiao.c 箫

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("铁箫",({"tie xiao", "tie", "xiao"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else{
                set("unit", "支");
                set("value", 600);
                set("material", "iron");
                set("long","这是一支用乌铁做的箫，做工十分精细。\n");
                set("wield_msg","$N伸手轻轻一招，一支$n已出现在$N手中。\n");
                set("unwield_msg","$N一声清啸，将$n插回腰间。\n");
        }
        init_sword(30);
        setup();
}

int wield() 
{
        object me = environment();
        if (userp(me) && living(me) && !me->query_skill("yuxiao-jian", 1)){
            message_vision("$N拿起"+name()+"，但是不会使用。\n", me);
            return 0;
        }           
        if(!query("weapon_prop/damage")) return 0;
        return ::wield();
}
