#include <ansi.h>
#include <weapon.h>
inherit F_GEMS;
inherit EQUIP;

void create()
{
        int flag;
	int dmg=random(10)+5;
        set_name(HIY"北侠五雷轰顶枪"NOR, ({ "nx wulei", "wulei"}));
        set_weight(5000);
        set("unit", "把");
        set("no_sell",1);
        set("no_pawn",1);
        set("long", "一把泛着金色光芒的长枪，握在手中竟是极为沉重。\n"NOR);
        set("value", 200000);
        set("material", "steel");
        set("rigidity",2500);
        set("wield_msg", "$N从背后抽出一把"HIY"北侠五雷轰顶枪"NOR"，“轰隆”之声犹如打雷。\n"NOR);
        set("unwield_msg", "$N把手中的"HIY"北侠五雷轰顶枪"NOR"藏回身后，身形也跟着矮了一截似的。\n"NOR);
        set("weapon_prop/damage", 200+dmg);
        set("flag", 2 | (int)flag | EDGED);
        set("skill_type", "spear");
        set("taozhuang", "nx");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "slash", "slice", "thrust" }) );
                                }
        setup();
}
