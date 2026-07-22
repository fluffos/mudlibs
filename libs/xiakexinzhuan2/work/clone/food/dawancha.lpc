inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("大碗茶",({"tea", "cha", "dawan cha"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一杯大碗茶，悠悠地冒着热气～～～\n");
		set("unit", "杯");
		set("value", 0);
        }
	set("liquid", ([
		"type": "water",
		"name": "茶水",
		"remaining": 3,
		"drunk_apply": 15,
	]));
}

