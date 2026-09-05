// 织女套装 by westernd 201507
#include <ansi.h>
#include <weapon.h>
inherit F_GEMS;
inherit EQUIP;

void create()
{
        int flag,bonus;
		if (random(100)<90) bonus = random(10)+1;
        else if (random(100)<99) bonus = random(10)+5;
        else bonus = random(20)+8;	

        set_name(HIY"织女神针"NOR, ({ "xiuhua zhen", "znzhen"}));
        set_weight(1000);
        set("unit", "根");
        set("no_sell",1);
        set("no_pawn",1);
        set("long", "这是一根银色的绣花针，是织女绣花用的工具。\n"NOR);
        set("value", 200000);
        set("material", "steel");
        set("rigidity",1000);
        set("wield_msg", "$N用拇指和食指从鬓间拈出一根"HIY"织女神针"NOR"。\n"NOR);
        set("unwield_msg", "$N把手中的"HIY"织女神针"NOR"插回鬓间。\n"NOR);
        set("weapon_prop/damage", 200+random(30));
        set("flag", 2 | (int)flag | EDGED);
        set("skill_type", "sword");
        set("taozhuang", "zn");
		set("weapon_prop/dodge",bonus);
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "thrust" }) );
                                }
        setup();
}
