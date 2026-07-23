#include <ansi.h>
#include <weapon.h>

inherit F_HAMMER;
inherit F_EQUIP;
inherit COMBINED_ITEM;
inherit F_UNIQUE;

void set_amount(int count)
{
    unequip();
        set("weapon_prop/damage", 50*count);
    ::set_amount(count);
}


void create()
{
       set_name( HIY "金轮" NOR,({ "jin falun" ,"lun" ,"jinlun" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
             set("value", 1000000);
             set("unique", 5);
             set("rigidity", 9);
             set("base_weight", 15000);
             set("base_unit", "只");
             set("unit", "些");
             set("long",HIY"这金轮径长尺半，乃黄金铸成，轮上铸有藏文的密宗真言，中藏九个小球，随手一抖，响声良久不绝。\n" NOR);
             set("material", "gold");
             set("weapon_prop/dodge", -10);
             set("weapon_prop/parry", 3);
             set("wield_neili", 100);
             set("wield_maxneili", 1500);
             set("wield_str", 23); 
             set("wield_msg", HIY"\n当□□一阵响亮，$N从怀中取出黄金法轮。这金轮径长尺半，乃黄金铸成，轮上铸有藏文的密宗真言，
中藏九个小球，随手一抖，响声良久不绝。\n\n"NOR);
             set("unwield_msg",HIY"$N将$n"HIY"一摆，当哐哐一阵响，放回腰间。\n"NOR);
        }
      set_amount(1);
        init_hammer(50);
        setup();
}

int wield()
{
        object ob = environment();
        int ret;

        if(!living(ob)) return 0;
        if((ob->query_str() < 26 && query_amount() == 2)
           || (ob->query_str() < 29 && query_amount() == 3)
           || (ob->query_str() < 32 && query_amount() == 4)
           || (ob->query_str() < 35 && query_amount() == 5)
           || query_amount() > 5)
                return 0;
          
        else if (ret=::wield())
        return ret;
}

