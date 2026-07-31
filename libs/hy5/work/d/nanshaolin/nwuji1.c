// Last Modified by winder on May. 29 2001
// nwuji1.c

inherit ITEM;

string* titles = ({
	"拈花指",
	"一指禅",
	"鹰爪功",
	"龙爪功",
	"风云手",
	"如来千叶手",
	"般若掌",
	"散花掌",
	"罗汉拳",
});

string* skills = ({
	"nianhua-zhi",
	"yizhi-chan",
	"yingzhua-gong",
	"longzhua-gong",
	"fengyun-shou",
	"qianye-shou",
	"banruo-zhang",
	"sanhua-zhang",
	"luohan-quan",
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
