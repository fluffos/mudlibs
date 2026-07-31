// bishui-jian.c

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;
void create()
{
        set_name("碧水剑",({ "bishui jian", "sword", "jian" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 100000);
                set("treasure",1);
                set("rigidity", 5);
                set("sharpness", 3);
                set("weapon_prop/dodge", -2);
                set("weapon_prop/parry", 1);        
                set("material", "steel");
                set("long", "这是把轻巧的宝剑，剑身上隐隐的透出碧玉之光，当真锋利无比。\n");
set("wield_msg", HIC "只听见「嗡」地一声，碧光闪现，$N将腰间解下的$n抖得笔直。\n" NOR);
set("unwield_msg", HIC "碧水剑幻作一道碧玉之光，「唰」地飞入剑鞘。\n" NOR);
set("unequip_msg", HIC "碧水剑幻作一道碧玉之光，「唰」地飞入剑鞘。\n" NOR);
        }
        init_sword(80);
        setup();
}
