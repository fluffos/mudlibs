// Last Modified by winder on May. 29 2001
// wuji13.c

inherit ITEM;

string* titles = ({
	"无常杖",
	"普渡杖",
	"修罗刀",
	"慈悲刀",
	"大金刚拳",
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
	set("unit", "册");
	set("long", "这是一册" + titles[i] + "\n");
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
