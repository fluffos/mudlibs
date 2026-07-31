// music  yangzhou's  酒壶

inherit ITEM;
inherit F_LIQUID;

void create()
{
set_name("白瓷酒壶",({"jiu hu","hu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
set("long","用红绸系着壶颈,壶身有个凸出的[酒]字.\n");
		set("unit", "个");
set("value",300);
		set("max_liquid", 15);
	}

	set("liquid", ([
		"type": "alcohol",
"name":"醉太白",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
