// watch2.c	手表(not autoload)
// by bing

#include <armor.h>
#include <ansi.h>

inherit WRISTS;

void create()
{
	set_name(HIR +"名字"+ NOR, ({ "ＩＤ" }));
	set("long","LONG\n");
	set_weight( 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
              set("no_sell",1);
		set("no_drop",1);
		set("value",250000);
		set("no_store",1);
	        set("no_give",1);
		set("owner", "OWNER");
		set("material", "gold");
		set("wear_msg",HIR "$N将"+query("name")+"戴在手腕上，得意地晃了晃。\n" NOR);
		set("armor_prop/armor", 1);
	}
	setup();
}	

void init()
{

        add_action("do_time","watch");
}

int do_time()
{
	write("现在的标准时间是：" + ctime(time()) + "\n");
	write("你已经在这个世界里成长了" + FINGER_D->age_string( (int)this_player()->query("mud_age")) + "。\n");
	return 1;
}

