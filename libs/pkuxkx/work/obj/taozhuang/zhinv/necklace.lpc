// 织女套装 by westernd 201507
#include <ansi.h>
#include <armor.h>
inherit F_GEMS;
inherit EQUIP;

void create()
{
        int bonus;
		if (random(100)<90) bonus = random(10)+1;
        else if (random(100)<99) bonus = random(10)+5;
        else bonus = random(20)+8;
		
		set_name(HIY"织女的金项链"NOR, ({ "znnecklace", "necklace"}) );
        set_weight(100);
        set("unit", "条");
        set("no_sell",1);
        set("no_pawn",1);
        set("long", "一条沉甸甸的项链，连着一枚心形坠饰，像是999纯金打造而成。\n");
        set("value", 100000);
        set("armor_type","neck");
        set("material", "gold");
        set("wear_msg","$N把"HIY"织女的金项链"NOR"挂在颈上，闪闪发光。\n");
        set("remove_msg","$N把"HIY"织女的金项链"NOR"摘了下来，偷偷藏在怀中。\n");
        set("armor_prop/armor", 50+random(100));
		set("armor_prop/magic", bonus);
        set("taozhuang", "xb");
        setup();
}