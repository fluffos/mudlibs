// wuji13.c
inherit ITEM;

string* skills = ({
	"damo-jian",
	"fumo-jian",
	"mohe-zhi",
	"weituo-zhang",
	"ruying-suixingtui",
});

void create()
{
	int i = random(sizeof(skills));
	string titles = to_chinese(skills[i]) + "谱";

	set_name(titles, ({ "shaolin wuji", "wuji" }));
	set_weight(200);
	set("unit", "册");
	set("long", "这是一册" + titles + "。\n");
	set("value", 500);
	set("material", "paper");
	set("shaolin", 1);
	set("skill", ([
		"name":	skills[i],	// name of the skill
		"exp_required":	10000,	// minimum combat experience required
		"jing_cost": 15+random(30),// jing cost every time study this
		"difficulty":	25,	// the base int to learn this skill
		"max_skill":	99	// the maximum level you can learn
	]) );
}
