// baihe.c

inherit ITEM;

void create()
{
	set_name("百合花", ({ "lily" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一枝美丽的百合花。\n");
		set("unit", "枝");
		set("value", 100);
	}
}
