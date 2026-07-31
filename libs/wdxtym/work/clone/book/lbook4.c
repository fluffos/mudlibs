// literateb4.c 论语
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(YEL"论语"NOR, ({ "literateb4", "shu4", "book4"}));
	set_weight(300);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "本");
	    set("long","一本孔夫子的《论语》。\n");
	    set("value", 400);
	    set("no_put", 1);
	    set("material", "paper");
	    set("skill", ([
		"name": "literate",    // name of the skill
		"jing_cost":    55,    // jing cost every time study this
		"difficulty":   35,    // the base int to learn this skill
		"max_skill":   119,    // the maximum level you can learn to
		"min_skill":   100,    // minimun level required
	    ]) );
	}
}
