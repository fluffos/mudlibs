// aiwowo.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("爱窝窝", ({ "ai wo wo" }) );

	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "一个香喷喷、热气腾腾的爱窝窝。\n");
		set("unit", "个");
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
