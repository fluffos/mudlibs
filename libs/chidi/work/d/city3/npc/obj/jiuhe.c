// jiuhe.c  酒壶

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("酒壶", ({"jiuhu", "hu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "一个用来装酒的酒壶，大概装得八、九升的酒。\n");
		set("unit", "个");
		set("value", 20);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
                "name": "酒",
		"remaining": 15,
		"drunk_supply": 6,
	]));
}

