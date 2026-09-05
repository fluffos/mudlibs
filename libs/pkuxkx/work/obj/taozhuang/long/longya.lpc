#include <ansi.h>
#include <weapon.h>
inherit EQUIP;
void create()
{
        int bonus;
        int flag;
        if (random(100)<90) bonus = random(50)+1;
        else if (random(100)<99) bonus = random(30)+51;
        else bonus = random(20)+81;	
        set_name(HIY"龙 牙"NOR, ({ "long ya", "ya"}));
        set_weight(5000);
        set("weapon_prop/magic", bonus);
        set("unit", "把");
        set("no_sell",1);
        set("no_pawn",1);
        set("long", "一把泛着微弱光芒的巨剑，看似厚重，握在手中竟是轻巧之极。\n剑柄上用隶书刻着几个字：虫牙第"+bonus+"号，甚是怪异。\n"NOR);
        set("value", 200000);
        set("material", "steel");
        set("rigidity",700);
        set("wield_msg", "$N从背后抽出一把"HIY"龙 牙"NOR"，“嗡嗡”之声犹如龙吟。\n"NOR);
        set("unwield_msg", "$N把手中的"HIY"龙 牙"NOR"藏回身后，身形也跟着矮了一截似的。\n"NOR);
        set("weapon_prop/damage", 100+bonus);
        set("attribute", bonus);
        set("flag", 2 | (int)flag | EDGED);
        set("skill_type", "sword");
        set("taozhuang", "long");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "slash", "slice", "thrust" }) );
                                }
        setup();
}