// Last Modified by winder on May. 29 2001
// wuji2.c

inherit ITEM;

string* titles = ({
	"混元一气",
	"少林身法",
	"韦驮棍",
	"达摩剑",
	"醉棍",
});

string* skills = ({
	"hunyuan-yiqi",
	"shaolin-shenfa",
	"weituo-gun",
	"damo-jian",
	"zui-gun",
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
			"name":	skills[i],	// name of the skill
			"exp_required":	10000,	// minimum combat experience required
			"jing_cost": 15+random(30),// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"max_skill":	99	// the maximum level you can learn
		      ]) );
}
