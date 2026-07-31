#include <ansi.h>
#include <weapon.h>

inherit F_HAMMER;
inherit F_EQUIP;
inherit COMBINED_ITEM;

void set_amount(int count)
{
    unequip();
        set("weapon_prop/damage", 20*count);
    ::set_amount(count);
}


void create()
{
        set_name("法轮",({ "fa lun" ,"lun" ,"falun" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
             set("value", 500);
             set("rigidity", 1);
             set("base_weight", 10000);
             set("base_unit", "只");
             set("unit", "些");
             set("long","这是直径尺半的一个铅环，上面刻满了密宗伏魔真言，环内中空。\n");
             set("material", "gold");
             set("weapon_prop/dodge", -5);
             set("weapon_prop/parry", 1);
             set("wield_neili", 50);
             set("wield_maxneili", 500);
             set("wield_str", 21); 
             set("wield_msg", "$N从怀中取出$n。随手一抖，响声良久不绝。\n"NOR);
             set("unwield_msg","$N将$n随手一抖，挂在手臂上。\n");
        }
        set_amount(1);
        init_hammer(20);
        setup();
}

int wield()
{
        object ob = environment();
        int ret;

        if(!living(ob)) return 0;
        if((ob->query_str() < 24 && query_amount() == 2)
           || (ob->query_str() < 27 && query_amount() == 3)
           || (ob->query_str() < 30 && query_amount() == 4)
           || (ob->query_str() < 33 && query_amount() == 5)
           || query_amount() > 5)
                return 0;
          
        else if (ret=::wield())
        return ret;
}

