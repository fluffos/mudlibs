// shanji.c

inherit ITEM;

void create()
{
	set_name("死野山鸡", ({ "shan ji"  }) );
	set("unit", "只");
	set("long","这是一只死去多时的野山鸡。\n");
	set_weight(4000);
	set("value",3000);
	setup();
}