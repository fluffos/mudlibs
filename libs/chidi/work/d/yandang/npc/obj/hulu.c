// bottle.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("青葫芦", ({ "qing hulu", "hulu","calabash" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一个碧绿色的葫芦，青里透黄颜色十分讨人喜爱。\n");
		set("unit", "个");
		set("value", 80);
		set("max_liquid", 60);
	}
	set("liquid", ([
		"type": "water",
		"name": "甘泉水",
		"remaining": 60,
	]) );
}
