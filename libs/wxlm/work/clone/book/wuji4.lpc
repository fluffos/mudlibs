// wuji4.c

inherit ITEM;

string* titles = ({
	"一拍两散",
	
	/*"修罗指法",
	"神掌八打",
	"无相指法",
	"多罗叶指",*/
});

string* skills = ({
	"yipai-liangsan",
	
	/*"xiuluo-zhi",
	"shenzhang-bada",
	"wuxiang-zhi",
	"duoluoye-zhi",*/
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
			"jing_cost": 35 + random(30),// jing cost every time study this
			"difficulty":	30,	// the base int to learn this skill
			"max_skill":	99	// the maximum level you can learn
		      ]) );
}
