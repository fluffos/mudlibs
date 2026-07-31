// yan.c


inherit ITEM;

void create()
{
	set_name("水烟", ({"yan", "smoke"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一卷用水烟丝。\n");
		set("unit", "个");
		set("value", 10);
    	}
}
