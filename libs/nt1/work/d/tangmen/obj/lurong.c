// lugu.c Â¹È×

inherit ITEM;

void create()
{
	set_name("Â¹È×", ({"lu rong", "rong"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»Î¶¼«ÆäÕä¹óµÄÒ©²Ä£¬Â¹È×¡£\n");
		set("unit", "¿é");
		set("value", 1500);
	}
}
