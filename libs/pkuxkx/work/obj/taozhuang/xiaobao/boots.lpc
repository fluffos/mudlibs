// 小宝的防身三宝 套装 by westernd 201503
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

        set_name(HIY"小宝的飞马靴"NOR, ({ "xb boots", "boots"}) );
        set_weight(100);
        set("unit", "件");
        set("no_sell",1);
        set("no_pawn",1);
        set("long", "一件白色的鞋子，提了起来，入手却是甚轻，布质更是甚为柔软。\n");
        set("value", 100000);
        set("armor_type","boots");
        set("material", "cloth");
        set("wear_msg","$N脱了个精光，把"HIY"小宝的飞马靴"NOR"贴身穿上，四周隐隐现出一圈白色光环。\n");
        set("remove_msg","$N找了个没人的角落把"HIY"小宝的飞马靴"NOR"脱了下来。\n");
        set("armor_prop/armor", 100+random(50));
		set("forge/times_max",1);
		set("forge/times",0);
		set("armor_prop/kf_def_wound", bonus);
        set("taozhuang", "xb");
        setup();
}