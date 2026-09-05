#include <ansi.h>
#include <weapon.h>
inherit F_GEMS;
inherit EQUIP;

void create()
{
        int flag;
        set_name(HIY"北侠神魔乱世斧"NOR, ({ "nx luanshi", "luanshi"}));
        set_weight(5000);
        set("unit", "把");
        set("no_sell",1);
        set("no_pawn",1);
        set("long", "一柄泛着金色光芒的斧头，斧刃上一边刻有天神的图案，另一边却是恶魔的嘴脸。\n"NOR);
        set("value", 200000);
        set("material", "steel");
        set("rigidity",2000);
        set("wield_msg", "$N从背后抽出一柄"HIY"北侠神魔乱世斧"NOR"，“呜呜”之声犹如恶鬼追魂。\n"NOR);
        set("unwield_msg", "$N把手中的"HIY"北侠神魔乱世斧"NOR"藏回身后，身形也跟着矮了一截似的。\n"NOR);
        set("weapon_prop/damage", 180);
        set("flag", 2 | (int)flag | EDGED);
        set("skill_type", "axe");
        set("taozhuang", "nx");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "slash", "slice", "thrust" }) );
                                }
        setup();
}
