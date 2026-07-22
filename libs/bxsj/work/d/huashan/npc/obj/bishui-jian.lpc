// ITEM: /d/huashan/npc/obj/bishuijian.c
// Date: Look 99/03/25

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name( GRN "碧水剑" NOR, ({ "bishui jian", "jian", "sword" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", GRN "这是柄又薄又轻的软剑，剑身上隐隐的透出绿光，当真锋利无比。\n" NOR);
                set("value", 1500);
                set("rigidity", 3);
                set("sharpness", 1);
                set("no_wield",1);
                set("family_required","华山派");
                set("weapon_prop/dodge", 2);
                set("weapon_prop/parry", 2);        
                set("material", "steel");
                set("unique", 1);
		  set("treasure",1);
                set("wield_neili", 100);
                set("wield_maxneili", 500);
                set("wield_str", 22);
                set("wield_msg", GRN "只听「嗡」地一声，绿光顿现，$N在腰间解下$n"+ GRN "，「刷」的一声抖得笔直。\n" NOR);
                set("unwield_msg", GRN "只见绿光一闪，你的眼前一花，$N将手中的$n"+ GRN "缠在腰间。\n" NOR);
        }
        init_sword(70);
        setup();
}
