// wuji13.c

inherit ITEM;

string* titles = ({
	"醉棍棍法",
	"普渡杖法",
	"伏魔剑法",
	
	/*"韦陀棍法",
	"无常杖法",
	"达摩剑法",*/
});

string* skills = ({
	"zui-gun",
	"pudu-zhang",
	"fumo-jian",
	/*
	"weituo-gun",
	"wuchang-zhang",
	"damo-jian",*/
});

void create()
{
	int i = random(sizeof(titles));

	set_name(titles[i], ({ "shaolin wuji", "wuji" }));
	set_weight(200);
	set("unit", "册");
	set("long", "这是一册" + titles[i] + "\n");
	set("value", 500);
        set("no_sell",1);
        set("no_put",1);
	set("material", "paper");
	set("skill", ([
			"name":	skills[i],	// name of the skill
			"exp_required":	10000,	// minimum combat experience required
			"jing_cost": 15+random(30),// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"max_skill":	99	// the maximum level you can learn
		      ]) );
}
