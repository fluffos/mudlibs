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
		
		set_name(HIY"织女的彩裳"NOR, ({ "zncloth", "cloth"}) );
        set_weight(100);
        set("unit", "件");
        set("no_sell",1);
        set("no_pawn",1);
        set("long", "这件粉红色的绸衫上面绣著几只黄鹊，闻起来还有一股淡淡幽香。\n");
        set("value", 100000);
        set("armor_type","cloth");
        set("material", "cloth");
//		set("female_only", 1);
        set("wear_msg","$N脱了个精光，把"HIY"织女的彩裳"NOR"贴身穿上，四周隐隐现出一圈白色光环。\n");
        set("remove_msg","$N找了个没人的角落把"HIY"织女的彩裳"NOR"脱了下来。\n");
        set("armor_prop/armor", 100+random(100));
		set("armor_prop/magic", bonus);
        set("taozhuang", "zn");
        setup();
}