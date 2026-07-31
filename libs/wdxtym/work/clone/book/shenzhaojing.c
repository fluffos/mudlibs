inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
	set_name("「神照经」", ({ "shenzhao jing", "shenzhao", "jing" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "一本薄薄的经书，封面上写着「神照经」三个大字。\n" );
		set("value", 1);
		set("no_sell", 1);
		set("material", "paper");
		set("skill", ([
			"name"	: "shenzhaojing",
			"exp_required":  100000,
			"jing_cost"   :  120,
			"difficulty"  :  40,
			"max_skill"   :  180,
			"min_skill"   :  40,
		]) );
	}
}

int query_autoload() { return 1; }


