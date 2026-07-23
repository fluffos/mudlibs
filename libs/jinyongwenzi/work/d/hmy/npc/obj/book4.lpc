// book4.c

inherit ITEM;

string* skills = ({
	"blade"
});

void create()
{
	int i = random(sizeof(skills));

	set_name("石壁", ({ "shibi", "bi","stone"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
              set("no_get",0);                
              set("long",
			"天魔日月刀基础篇\n"
			"这是一块园园的石壁，似乎用手指刻划了数个指印。\n");
		set("material", "stone");
		set("skill", ([
			"name":	skills[i],	// name of the skill
			"exp_required":	100000,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	101	// the maximum level you can learn
		]) );
	}
}
