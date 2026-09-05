// fojing11.c
//seagate@pkuxkx 增加书籍翻页和朗诵功能，并且增加对诵经任务的支持 2010/10/09

inherit ITEM;
inherit "/newbiequest/book";

string* titles = ({
	"般若经",
	"维摩经",
	"法华经",
	"华严经",
//	"无量寿经",
//	"大般涅磐经",
//	"阿含经",
//	"金刚经",
//	"波罗蜜多心经",
});

void create()
{
	set_name(titles[random(sizeof(titles))], ({ "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册佛经。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"buddhism",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	50	// the maximum level you can learn
		]) );
	}
	set("pages",get_pages(query("name")));
	set("page",1);
	setup();
}

#include "/newbiequest/shaolin/quest_chanting.h"