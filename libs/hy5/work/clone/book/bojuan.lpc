// bojuan.c

inherit ITEM;

void create()
{
	set_name("帛卷", ({ "bo juan", "bo", "juan" }));
	set_weight(50);
//	set("no_drop", "这样东西不能离开你。\n");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("treasure",1);set("unit", "卷");
		set("long",
			"这是一卷帛卷，里面写着 ：\n"
			"庄子“逍遥游”有云：穷发之北有冥海者，天池也。有鱼焉，其广数千里。。。。\n");
		set("value", 500);
		set("material", "silk");
		set("skill", ([
			"name":	"beiming-shengong",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	50,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	100,	// the maximum level you can learn
			"min_skill":	20	// the maximum level you can learn
		]) );
	}
}

