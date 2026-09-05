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
		
		set_name(HIY"织女的金戒指"NOR, ({ "znring", "ring"}) );
        set_weight(100);
        set("unit", "件");
        set("no_sell",1);
        set("no_pawn",1);
        set("long", "一个金光闪闪的金指环，透射出无法掩饰的光芒。"\n");
        set("value", 100000);
        set("armor_type","finger");
        set("material", "gold");
        set("wear_msg","$N把"HIY"织女的金戒指"NOR"套在手指上，闪闪发光。\n");
        set("remove_msg","$N把"HIY"织女的金戒指"NOR"摘了下来，偷偷藏在怀中。\n");
        set("armor_prop/armor", 50+random(100));
		set("armor_prop/magic", bonus);
        set("taozhuang", "xb");
        setup();
}