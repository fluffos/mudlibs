// xiaoyao.c

#include <ansi.h>
#include <medical.h>

inherit MEDICAL_BOOK;

void create()
{
	set_name(HIY "子午针灸经" NOR, ({ "ziwu jing", "jing" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一本破破烂烂的书籍，上面用小楷"
			    "写着“子午针灸经”几个字。\n");
		set("material", "paper");
		set("skill", ([
			"name"      : "xiaoyao-qixue",
			"jing_cost" : 50,
			"difficulty": 45,
			"max_skill" : 160,
			"min_skill" : 30,
		]));

		set("can_make", ([
			"jingqi"   : 50,	// 精气丸
			"dahuan"   : 80,	// 大还丹
			"jiedu"    : 100,       // 牛黄解毒丸
			"heishi"   : 180,       // 玉洞黑石丹
			"xiongshe" : 250,       // 九转熊蛇丸
		]));
	}
	setup();
}

