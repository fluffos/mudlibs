#include <ansi.h>

inherit ITEM;

void create()
{
      set_name(GRN "徐霞客游记" NOR, ({ "xuxiake youji","youji" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "一本厚厚的书，是徐霞客对各地风景名胜和地理的记载。\n");
		set("value", 10000);
		set("material", "paper");
             }
	setup();
}
