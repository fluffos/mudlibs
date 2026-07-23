// book_pic.c

inherit ITEM;

void create()
{
	set_name("图画", ({ "picture", "tu hua", "book" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "幅");
		set("long",
"这是一幅旧得发黄的水墨图，里面画着一个大汉挥舞竹棒与众人厮杀的情景。\n");
		set("value", 500);
		set("material", "silk");
		set("skill", ([
			"name":	"stick",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	31	// the maximum level you can learn
		]) );
	}
}
