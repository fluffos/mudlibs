#include <weapon.h>
#include <ansi.h>

inherit WHIP;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"金龙鞭"NOR,({ "jinlong bian", "whip","bian","jinlong" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 1500000);
                set("unique", 1);
                set("rigidity", 3);
                set("material", "steel");
                set("weapon_prop/dodge", 1);
                set("weapon_prop/parry", 1);
                set("treasure",1);
                set("wield_neili", 200);
                set("wield_maxneili", 800);
                set("wield_str", 22);
                set("long", "这条金龙鞭上珠光宝气，通体镶满了宝石、金刚钻、白玉之属！\n");
                set("unwield_msg", "$N随手一抖，将$n盘回腰间。\n");
                set("wield_msg", "$N随手一抖，抽出一条$n握在手中。\n");
        }
        init_whip(70);
        setup();
}
