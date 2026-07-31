// yaoshi.c

inherit ITEM;

void create()
{
	set_name("牢房钥匙", ({"hg key", "key"}));
	set("long",
		"这是一把很普通的钥匙。\n");
	set("unit", "把");
	set("weight", 10);
}

