
inherit ITEM;

void create()
{
	set_name("端砚", ({ "duanyan" , "端砚"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "方");
		set("long", "一方上好的砚台,背面还雕刻了一只大雁\n");
	}
}


