// 小宝的防身三宝 套装 by westernd 201503
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
		set_name(HIY"小宝的金丝背心"NOR, ({ "xb cloth", "cloth"}) );
        set_weight(100);
        set("unit", "件");
        set("no_sell",1);
        set("no_pawn",1);
        set("long", "一件银光闪闪的衣服，提了起来，入手却是甚轻，衣质更是甚为柔软，非丝非毛，不知是何物事所织。\n");
        set("value", 100000);
        set("armor_type","cloth");
        set("material", "cloth");
        set("wear_msg","$N脱了个精光，把"HIY"小宝的金丝背心"NOR"贴身穿上，四周隐隐现出一圈银色光环。\n");
        set("remove_msg","$N找了个没人的角落把"HIY"小宝的金丝背心"NOR"脱了下来。\n");
        set("armor_prop/armor", 500+random(100));
		set("armor_prop/magic", bonus);
        set("taozhuang", "xb");
        setup();
}