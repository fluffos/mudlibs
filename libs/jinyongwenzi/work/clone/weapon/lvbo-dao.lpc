// /clone/weapon/lvbo-dao 绿波香露刀

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name(GRN"绿波香露刀"NOR, ({ "lvboxianglu dao","lvboxianglu","dao", "blade" }));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("rigidity", 9);
                set("sharpness", 5);
                set("material", "steel"); 
                set("weapon_prop/parry", 8);
                set("long", "这是一把浑身透着暗绿色宝刀，刀身隐隐发出腥臭的气味，却偏偏以香露命名，真是奇怪。\n");
                set("value", 1);
                set("unique", 1);
                set("wield_neili", 500);
                set("wield_maxneili", 1000);
                set("wield_str", 22);
                set("wield_msg", HIG"$N从背后抽出一把宝刀拿在手里，舞了个刀花，但见刀光闪闪，幻出点点寒光。\n"NOR);            
                set("unwield_msg", HIG"$N双手一挥，闪电般将刀插回刀鞘内。\n"NOR);
                set("treasure",1);
                set("poisoned", "lvbo_poison");
               set("poison_number", 200);
        }
 init_blade(120);
        setup();
}
