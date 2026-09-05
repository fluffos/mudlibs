// Modified by iszt@pkuxkx, 2007-04-07

inherit ITEM;

void create()
{
	set_name("易筋经内功篇", ({ "yijin jing", "book" }));
	set_weight(100); 
	set("no_drop",1);
	set("no_store", 1);
	set("shaolin", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "少林至高无上绝学之经典----易筋经内功篇”。\n");
		set("value", 1000);
		set("material", "bamboo");
		set("skill", ([
			"name": "hunyuan-yiqi",
			"exp_required": 500000,
			"jing_cost":    30,
			"difficulty":   30,
			"min_skill":   101,
			"max_skill":   301,
		]) );
	}
}
