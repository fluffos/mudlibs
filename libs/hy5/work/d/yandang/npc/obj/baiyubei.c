// music  yangzhou's  酒壶

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("白玉杯",({"baiyu bei","bei"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
	set("long","苏州本地产的小茶杯。\n");
	set("unit","个");
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type":"water",
		"name":"茉莉花茶",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
