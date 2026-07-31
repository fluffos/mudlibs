//Cracked by Roath
// lingdan.c 灵丹 

inherit ITEM;


void create()
{
	set_name("灵丹", ({"lingdan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("long", "这是一粒贵重的灵丹，吃下去能够养精活血。不过时间一长药性就会消失，灵丹也会无影无踪的。\n");
		set("value", 500);
	}
	setup();
}

