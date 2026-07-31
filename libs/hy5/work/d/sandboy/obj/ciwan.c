// music  yangzhou's  酒壶

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("青瓷碗",({"qingci wan","wan"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
	set("long","一个缺了口的海口青瓷碗。\n");
	set("unit","个");
		set("max_liquid", 15);
	}
	set("liquid", ([
		"type":"water",
	"name": "茶水",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
