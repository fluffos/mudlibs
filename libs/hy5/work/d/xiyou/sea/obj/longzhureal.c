# include <skill.h>

inherit ITEM;

void create()
{
        set_name("九彩云龙珠", ({"jiucai longzhu", "pearl"}));
	set_weight(100);
	if( clonep() )
    		set_default_object(__FILE__);
  	else {
		set("no_sell",1);
//		set("no_give",1);

		set("value",0);
		set("unit","颗");
		set("long",
"一颗斗大圆润的珍珠，隐见内有九条光影游动，似乎触摸(touch)之下会发出异彩。\n");
	}
	set("is_monitored",1);
	setup();

}
