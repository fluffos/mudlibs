// /u/beyond/mr/obj/shu.c
// this is made by beyond
// update 1997.6.29

inherit ITEM;

string* titles = ({
	"慕容心法上卷",
});

void create()
{
	set_name(titles[random(sizeof(titles))], ({ "shu", "book" }));
                set("treasure", 1);
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是慕容心法的上卷。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"murong-xinfa",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	30	// the maximum level you can learn
		]) );
	}
}
