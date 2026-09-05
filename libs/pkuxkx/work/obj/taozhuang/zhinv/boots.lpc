// 织女套装 by westernd 201507
#include <ansi.h>
#include <armor.h>
inherit F_GEMS;
inherit EQUIP;

void create()
{
		int bonus;
		if (random(100)<90) bonus = random(1)+1;
        else if (random(100)<99) bonus = random(2)+2;
        else bonus = random(4)+4;	

        set_name(HIY"织女的绣花鞋"NOR, ({ "znboots", "boots"}) );
        set_weight(100);
        set("unit", "双");
        set("no_sell",1);
        set("no_pawn",1);
        set("long", "一双织女穿的缝制得很精美的绣花鞋。\n");
        set("value", 100000);
        set("armor_type","boots");
        set("material", "cloth");
//		set("female_only", 1);
        set("wear_msg","$N脱了个精光，把"HIY"织女的绣花小鞋"NOR"贴身穿上，竟似脚踩云朵。\n");
        set("remove_msg","$N找了个没人的角落把"HIY"织女的绣花小鞋"NOR"脱了下来。\n");
        set("armor_prop/armor", 100+random(50));
		set("armor_prop/kf_def_wound", bonus);
        set("taozhuang", "zn");
        setup();
}