// shiji3.c

inherit ITEM;

string* titles = ({
	"春秋",
	"尚书",
	"庄子",
});

void create()
{
	int i = random(sizeof(titles));

    set_name(titles[i], ({ "shu3", "shu ji"}));
	set_weight(200);
	set("unit", "册");
	set("long", "这是一册" + titles[i] + "\n");
	set("value", 800);
	set("material", "paper");
	set("skill", ([
			"name":	"literate",	// name of the skill
			"sen_cost": 25+random(20),// jing cost every time study this
			"difficulty":	0,	// the base int to learn this skill
			"max_skill":	130	// the maximum level you can learn
    ]) );
}
