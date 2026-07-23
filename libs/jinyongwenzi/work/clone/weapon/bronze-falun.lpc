//bronze-falun.c 铜法轮
//by iceland
#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit HAMMER;
void create()
{
        set_name( YEL"铜法轮"NOR,({ "bronze falun",  "falun","lun","tong falun", "tongfalun"}));
        set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
               	set("unit", "只");
	        set("long","这是一柄铜铸法轮，约有尺半大小，上面铸有密宗伏魔真言，内藏九个小球，是僧人们作法事用的一种法器。\n");
                set("value", 300);
                set("unique", 1);
                set("rigidity", 3);
                set("sharpness", 1);
                set("treasure",1);  
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 3);   
                set("wield_maxneili", 800);
                set("wield_str", 25);
                set("material", "bronze");
                set("wield_msg", "$N从怀中掏出一柄$n掂了掂分量，握在手中，当啷啷响声良久。\n");
                set("unwield_msg","$N将手中的$n揣回怀中。\n");
	}
        init_hammer(65);
	setup();
}
