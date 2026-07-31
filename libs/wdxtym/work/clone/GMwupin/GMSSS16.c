// god_eyes.c 生命之源

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIG "生命" + HIM + "之源" NOR, ({ "yan s2" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIC"一块闪烁着"HIY"夺目光芒"HIC"的"HIG"宝石"HIC"，据说此物并非来自人间，让人敬畏之心油然而生。"NOR"\n");
		set("base_value", 200);
		set("base_weight", 1);
		set("base_unit", "块");
	    set("tianji1", 30);
  		set("no_get",1);
		set("no_give",1);
  		set("no_drop",1);
  		set("no_sell",1);
  		set("no_steal",1);
		set("can_be_enchased", 1);
		set("magic/type", "all");
		set("magic/power", 350);
	}
	set_amount(1);
	setup();
}
