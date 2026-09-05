#include <ansi.h>
#include <weapon.h>
inherit F_GEMS;
inherit EQUIP;

void create()
{
        int flag;
        int dmg=random(10)+1;
	set_name(HIY"北侠一柱擎天杖"NOR, ({ "nx qingtian", "qingtian"}));
        set_weight(5000);
        set("unit", "把");
        set("no_sell",1);
        set("no_pawn",1);
        set("long", "一把泛着银色光芒的长杖，看似轻巧，握在手中竟是极为沉重。\n"NOR);
        set("value", 200000);
        set("material", "steel");
        set("rigidity",2000);
        set("wield_msg", "$N从背后抽出一把"HIY"北侠一柱擎天杖"NOR"，“嗡嗡”之声犹如龙吟。\n"NOR);
        set("unwield_msg", "$N把手中的"HIY"北侠一柱擎天杖"NOR"藏回身后，身形也跟着矮了一截似的。\n"NOR);
        set("weapon_prop/damage", 200+dmg);
        set("flag", 2 | (int)flag | EDGED);
        set("skill_type", "staff");
        set("taozhuang", "nx");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "slash", "slice", "thrust" }) );
                                }
        setup();
}
