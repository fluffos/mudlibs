inherit F_UNIQUE;
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(CYN "圣火令" NOR, ({ "shenghuo ling3", "ling3" }) );
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "把");
		set("value", 10000);
		set("material", "steel");
		set("no_sell", "他奶奶的，这是什么玩意？");
		set("long", CYN "这是一柄两尺来长的黑牌，非金非铁。质地坚硬无比，\n"
				"似透明，令中隐隐似有火焰飞腾，实则是令质映光，颜\n"
				"色变幻。令上刻得有不少波斯文字。似乎和武学有关。"NOR"\n");
		set("wield_msg", CYN "$N" CYN "“唰”的一声，从腰间抽出一片黑黝的铁牌握在手中。"NOR"\n");
		set("unwield_msg", CYN "$N" CYN "将圣火令插回腰间。"NOR"\n");

		set("skill", ([
			"name":		"shenghuo-ling",
			"exp_required":	1500000,	// minimum combat experience required
			"jing_cost":	120,	    // jing cost every time study this
			"difficulty":	48,	     // the base int to learn this skill
			"max_skill":	149,	    // the maximum level you can learn
			"min_skill":	119,	    // the maximum level you can learn
			"need" : ([ "sanscrit" : 150 ]),// need at least 150 lvl san
		]) );
	}
	init_sword(80);
	setup();
}
