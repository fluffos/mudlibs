// biduzhu.c

inherit ITEM;

void create()
{
	set_name("避毒珠", ({ "bidu zhu"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "颗");
		set("long", "这是一颗不起眼的黑珠子。\n");
	}
}