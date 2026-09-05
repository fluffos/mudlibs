// by aiai for xiakedao.c
// dodge book

inherit ITEM;

void create()
{
    set_name("飞仙古画", ({ "picture"}));
	set_weight(60000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long",
			"这张都已经泛黄了古画，上面有一些小人\n"
			"摆出一些醉仙望月步的姿态。\n");
                set("value", 1);
		set("material", "paper");
		set("skill", ([
			"name": 	"xiake-shenfa",	
			"exp_required":	400000,				
			"jing_cost":	100,				
			"difficulty":	60,		
			"max_skill":	250		
		]) );
	}
}
