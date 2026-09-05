// gangdao.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(CYN"劣质陌刀"NOR, ({ "mo dao", "blade" }));
        set_weight(5000);
        set("unit", "柄");
        set("long", "这是一柄亮晃晃的陌刀，普通官兵的常备武器。\n");
        set("value", 5000);
        set("material", "steel");
        set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
        set("weapon_prop/strength", 30);
        set("weapon_prop/attack", 30);
        set("weapon_prop/deep_injure", 5);
        set("weapon_prop/dodge", -30);
        set("weapon_prop/damage", 120);
        set("rigidity", 200);
        set("max_rigidity", 200);
        set("no_give",1);
        set("no_get",1);
        set("no_put",1);
        set("no_sell",1);
        set("no_drop",1);
        set("no_store",1);
        set("no_sell_in_playershop",1);
        set("owner", "datang");
        init_blade(120);
        setup();
}

#include "/quest/changan/equip.h"