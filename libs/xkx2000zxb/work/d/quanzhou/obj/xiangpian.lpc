//Cracked by Kafei
// 香片

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("香片茶杯", ({"xiangpian chabei", "bei", "cup"}));
        set_weight(70);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个普通的茶杯。\n");
                set("unit", "个");
                set("value", 30);
		set("max_liquid", 4);
		set("worthless", 1);
		set("liquid", ([
        		"type": "tea",
			"name": "香片",
			"remaining": 4,
			"drunk_supply": 0,
    		]));
        }
}
