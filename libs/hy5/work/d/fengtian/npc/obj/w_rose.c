// w_rose.c

inherit ITEM;

void create()
{
	set_name("白玫瑰", ({ "white rose" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一枝素雅的白玫瑰花。\n");
		set("unit", "枝");
		set("value", 100);
	}
}
