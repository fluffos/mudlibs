// tulong-dao.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{

        set_name(HIM"鬼头刀"NOR, ({ "guitou dao","guitou","dao", "blade" }));
        set_weight(35000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("rigidity", 9);
                set("sharpness", 9);
                set("long", "这是一柄亮晃晃的鬼头刀。\n");
                set("value", 1);
                set("unique", 1);
                set("weapon_prop/dodge", -10);
                set("weapon_prop/parry", 5);
                set("material", "steel"); 
                set("wield_neili", 500);
                set("wield_maxneili", 1000);;
                set("wield_str", 25);;
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");

        }
         init_blade(300);
        setup();
}
