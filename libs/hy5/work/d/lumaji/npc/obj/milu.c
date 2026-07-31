// milu.c

inherit ITEM;

void create()
{
	set_name("死麋鹿", ({ "mi lu"  }) );
	set("unit", "只");
	set("long","这是一只死去多时的麋鹿。\n");
	set_weight(10000);
	set("value",10000);
	setup();
}