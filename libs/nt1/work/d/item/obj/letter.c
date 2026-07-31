// 信件 莫邪交给弟子们的信件
// Written by Doing Lu 1998/11/2

inherit ITEM;

void create()
{
	set_name("信件", ({"item permit", "letter"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是莫邪给弟子写的信，你可以带上它去找弟子打造道具。\n");
		set("unit", "封");
		set("value", 0);
		set("wield_msg", "");
		set("unwield_msg", "");
	}
}
