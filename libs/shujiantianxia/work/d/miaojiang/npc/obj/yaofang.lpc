#include <ansi.h>

inherit ITEM;

void create()
{
      set_name(HIY"药方" NOR, ({ "yao fang"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "份");
		set("long", "一份药方，明显出自高人之手：\n"
		            +HIG"蓝色药花、七星海棠、藏红花、金银花、人参。\n\n"NOR
		            +"另外，上面还记录关于药炉的使用方法：\n"
		            +RED"开炉（open）、加药（add）、加水（pour）、\n"
                            +"关炉（close）、点火（dianhuo）、扇风（burn）、\n"
		            +"熬药（aoyao）、灭火（miehuo）、取药（qu）。\n"NOR);
		set("value", 10000);
		set("material", "paper");
    set("no_give",1);
    set("no_drop",1);
    set("no_sell",1);
  }
	setup();
}
