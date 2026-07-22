// tieqiao.c

inherit ITEM;

void create()
{
	set_name("铁锹", ({ "tie qiao", "qiao" }) );
	set_weight(1500);
        if (clonep())
                set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 2000);
		set("long", "这是一把铁锹。\n");
	}
	setup();
}
