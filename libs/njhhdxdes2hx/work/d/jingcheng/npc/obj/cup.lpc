// cup.c 

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"翡翠杯"NOR, ({ "feicui cup", "cup" }) );
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
                set("long", CYN"这是一个用翡翠做成的酒杯，大富豪，大酒客都喜欢拿它盛酒。\n
古人云，葡萄美酒夜光杯，就是指它了。\n"NOR);
		set("value", 100000);
		set("material", "greysteal");
		set("no_get",0);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}

