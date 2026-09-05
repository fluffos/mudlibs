//taobook-3.c
//seagate@pkuxkx 2010/10/21

inherit ITEM;
inherit "/newbiequest/book";

void create()
{
	set_name( "庄子·内篇「下卷」", ({ "zhuang zi", "jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册庄子，包含内篇的人间世、德充符、大宗师、应帝王。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"taoism",	            // name of the skill
			"exp_required":	0,	          // minimum combat experience required
			"jing_cost": 20, 	            // jing cost every time study this
			"difficulty":	20,	            // the base int to learn this skill
			"max_skill":	80,	// the maximum level you can learn
		]) );
	}
	set("pages",get_pages(query("name")));
	set("page",1);
}

#include "/newbiequest/wudang/quest_chanting.h"