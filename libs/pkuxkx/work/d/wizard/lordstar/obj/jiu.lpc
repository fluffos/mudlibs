
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("西凤酒", ({"xifeng jiu", "jiu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装西凤酒的酒壶。西凤酒醇香典雅，甘润挺爽，诸味协调，尾净悠长，乃少有的好酒。\n");
		set("unit", "壶");
		set("value", 1000);
		set("max_liquid", 20);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "西凤酒",
		"remaining": 20,
		"drunk_supply": 8,
	]));
	
	set("liquid_apply/liquidtype", "alcohol");
	set("liquid_apply/liquidname", "西凤酒");
	set("liquid_apply/duration", 180);
	set("liquid_apply/apply", ([
			"strength": 5,
			"qi_recover": 50,
			"intelligence": -2,
			])); 
	set("liquid_apply/desc", ({ "气血恢复提高50点", "膂力提高5点", "悟性降低2点" }));
}

