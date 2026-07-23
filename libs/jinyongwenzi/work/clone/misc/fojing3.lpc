// fojing.c

inherit ITEM;

void create()
{
	set_name("甘珠儿经", ({ "ganzhuer jing","shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册梵文书写的佛经。\n");
		set("value", 500);
                set("no_sell", 1);
		set("material", "paper");
		set("skill", ([
			"name":	"huanxi-chan",	
			"exp_required":	0,	
			"jing_cost":	10,	
			"difficulty":	15,	
             		"max_skill":	51	
		]) );
	}
}
