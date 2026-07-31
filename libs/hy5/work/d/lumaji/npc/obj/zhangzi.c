// zhangzi.c

inherit ITEM;

void create()
{
	set_name("死獐子", ({ "zhang zi"  }) );
	set("unit", "只");
	set("long","这是一只死去多时的獐子。\n");
	set_weight(7000);
	set("value",10000);
	setup();
}