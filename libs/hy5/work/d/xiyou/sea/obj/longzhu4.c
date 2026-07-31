# include <skill.h>

inherit ITEM;

void create()
{
        set_name("橙龙珠", ({"cheng longzhu", "longzhu", "pearl"}));
	set_weight(100);
	if( clonep() )
    		set_default_object(__FILE__);
  	else {
		set("no_sell",1);
		set("value",0);
		set("unit","颗");
		set("long",
"一颗斗大圆润的珍珠，传说只有得道的真龙才会有。
内有光影游动，似乎触摸(touch)之下会发出异彩。\n");
	}
	setup();
}
