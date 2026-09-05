
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("酥皮莲蓉包", ({"lianrong bao", "bao"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个香喷喷的包子，皮薄白、爽软、半透明，可见角内馅料，馅鲜美甘香。\n");
		set("unit", "个");
		set("value", 500);
		set("food_remaining", 5);
		set("food_supply", 30);
		
		set("food_apply/duration", 180);
		set("food_apply/apply", ([
			"constitution": 5,
			"neili_recover": 20,
			])); 
		set("food_apply/desc", ({ "根骨提高5点", "内力恢复提高20点", }));
		
	}
}
