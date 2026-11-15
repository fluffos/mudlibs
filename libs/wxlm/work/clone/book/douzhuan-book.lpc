// douzhuan-book.c 移星换斗



inherit ITEM;

void create()
{
	set_name(CYN "移星换斗" NOR, ({ "douzhuan book", "douzhuan", "book" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "本");
		set("no_sell", 1);
		set("long", "这是一本记载了慕容家移星换斗的秘籍。\n");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name":	 "douzhuan-xingyi",
			"exp_required": 100000,
			"jing_cost" :   50,
			"difficulty":   40,
			"max_skill":    179,
			"min_skill":    100
		]) );
	}
}
