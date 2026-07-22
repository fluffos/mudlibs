// /d/xiangyang/obj/mutou.c

inherit ITEM;

void create()
{
	set_name("木头", ({ "mutou" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "堆");
		set("long", "这是一堆由木人身上掉下来的木头，大概可以送还给木匠吧。\n");
		set("value", 1);
		set("material", "wood");
	}
	setup();
}
