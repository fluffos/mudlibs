// movebook.c

inherit ITEM;

void create()
{
	set_name("古玉牌", ({ "guyupai" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long",
			"这块古玉牌上正刻得是极高明的招架方法,你可以用study来读它。\n");
		set("value", 0);
		set("material", "stone");
		set("skill", ([
			"name": 		"unarmed",	
			"exp_required":	20000,				
			"jing_cost":		80,				
			"difficulty":	80,		
			"max_skill":	360,
		]) );
	}
}
