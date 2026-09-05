//yitianjian.c
#include <weapon.h>

#include <ansi.h>
inherit HAMMER;

void create()
{

    set_name(HIY"破天锤"NOR, ({ "potian chui", "hammer", "chui"}) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
        	set("value", 50000);
                set("no_pawn", 1);
                set("no_sell", 1);
//        	set("no_drop", "1");
        	set("material", "iron");
               set("long","这是当年李逍遥使用的破天锤，上面刻着感人肺腑的诗句：\n"+HIM"翩翩潇洒美少年，灵岛求药结仙缘。千里崎岖不辞苦，仗剑江湖为红颜。\n"NOR);
                set("wield_msg",CYN"$N拿出一把$n"+CYN"握在手中，脸上骤然透出一股杀气。\n"NOR);
                set("unwield_msg", CYN"$N将手中的$n"+CYN"别到腰后，脸色似乎安详了许多。\n"NOR);
	}
        init_hammer(135);
	setup();
}
