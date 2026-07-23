//silver-falun.c 银法轮
//by iceland

#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
        set_name( HIW"银法轮"NOR,({ "silver falun" ,"lun" ,"falun","yin falun","yinfalun" }));
        set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
                set("long","这是一柄银铸法轮，约有尺半大小，上面铸有密宗伏魔真言，内藏九个小球，是高僧作法事用的一种法器。\n");
                set("value", 1500);
                set("unique", 1);
                set("rigidity", 5);
                set("sharpness", 3);
                set("treasure",1);  
                set("weapon_prop/dodge", -7);
                set("weapon_prop/parry", 7);     
                set("wield_neili", 300);
                set("wield_maxneili", 1200);
                set("wield_str", 30);
                set("material", "silver");
                set("wield_msg", "$N从怀中掏出一柄$n掂了掂分量，握在手中，当啷啷响声良久。\n");
                set("unwield_msg","$N将手中的$n揣回怀中。\n");
	}
        init_hammer(80);
	setup();
}
