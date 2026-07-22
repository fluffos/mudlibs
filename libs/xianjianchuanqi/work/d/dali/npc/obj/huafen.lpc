inherit ITEM;

void create()
{
	set_name( "花粉", ({ "hua fen", "fen" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "盒");
                set("long", "这是一盒擦脸保养用的花粉。 \n");
		set("value", 250);
		set("material", "iron");
	}
	setup();
}

