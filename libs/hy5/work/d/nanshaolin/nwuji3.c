// Last Modified by winder on May. 29 2001
// wuji13.c

inherit ITEM;

string* titles = ({
	"Œﬁ≥£’»",
	"∆’∂…’»",
	"–ﬁ¬ﬁµ∂",
	"¥»±Øµ∂",
	"¥ÛΩ∏’»≠",
});

string* skills = ({
	"wuchang-zhang",
	"pudu-zhang",
	"xiuluo-dao",
	"cibei-dao",
	"jingang-quan",
});

void create()
{
	int i = random(sizeof(titles));

	set_name(titles[i], ({ "shaolin wuji", "wuji" }));
	set_weight(200);
	set("unit", "≤·");
	set("long", "’‚ «“ª≤·" + titles[i] + "\n");
	set("value", 500);
	set("material", "paper");
	set("skill", ([
		"name":	skills[i],
		"exp_required":	10000,
		"jing_cost": 15+random(30),
		"difficulty":	25,
		"max_skill":	99
	]) );
}
