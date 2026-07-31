// lbook2.c
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(YEL"百家姓"NOR, ({ "literateb2", "shu2", "book2" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);				   
	else
	{ 
	       set("unit", "本");
		set("long","读书人必读的百家姓。\n");
		set("value", 5000);
		set("material", "paper");
		set("skill",
		([
			"name": "literate",      // name of the skill
			"jing_cost":    25,      // jing cost every time study this
			"difficulty":   20,      // the base int to learn this skill
			"max_skill":    49,      // the maximum level you can learn
			"min_skill":    30,      // minimun level required
		]) );
	}
}
