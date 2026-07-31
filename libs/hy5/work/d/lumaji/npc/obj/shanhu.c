// shanhu.c

inherit ITEM;

void create()
{
	set_name("死山虎", ({ "shan hu"  }) );
	set("unit", "只");
	set("long","这是一只死去多时的山老虎。\n");
	set_weight(10000);
	set("value",5000);
	setup();
}