// shiji2.c

inherit ITEM;

string* titles = ({
	"大学",
	"中庸",
	"孟子",
	"论语",
});

void create()
{
	int i = random(sizeof(titles));

    set_name(titles[i], ({ "shu2", "shu ji"}));
	set_weight(200);
	set("unit", "册");
	set("long", "这是一册" + titles[i] + "\n");
      set("value",30000);
	set("skill", ([
			"name":	"literate",	// name of the skill
			"sen_cost": 20+random(20),// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	70	// the maximum level you can learn
    ]) );
}
