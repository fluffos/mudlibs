// 小宝的防身三宝 套装 by westernd 201503
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

        set_name(HIY"小宝的墨匕首"NOR, ({ "xb dagger", "dagger"}));
        set_weight(5000);
        set("unit", "把");
        set("no_sell",1);
        set("no_pawn",1);
        set("long", "劍身如墨，半點光澤也沒有，只覺極是沉重，那匕首連柄不過一尺二寸，套在鯊魚皮的套子之中，份量竟和尋常的長刀長劍無異。\n"NOR);
        set("value", 200000);
        set("material", "steel");
        set("rigidity",2000);
        set("wield_msg", "$N从靴中抽出一把"HIY"小宝的墨匕首"NOR"，只覺一股寒氣撲面而至。\n"NOR);
        set("unwield_msg", "$N把手中的"HIY"小宝的墨匕首"NOR"藏回靴中。\n"NOR);
        set("weapon_prop/damage", 200+random(30));
        set("flag", 2 | (int)flag | EDGED);
        set("skill_type", "dagger");
        set("taozhuang", "xb");
		set("weapon_prop/dodge",bonus);
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "slash", "slice", "thrust" }) );
                                }
        setup();
}
