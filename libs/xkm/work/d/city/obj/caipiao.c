inherit ITEM;

void create()
{
	set_name("彩票", ({"cai piao","caipiao","piao"}));
	set_weight(10);
	set("long", "空白彩票一张，原来是毫无用处的东西。\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("value", 1);
	}
	setup();
}
