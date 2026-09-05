inherit ITEM;

void create()
{
        set_name( "内务府通行令", ({ "hgtongxing ling", "ling"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
                set("long", "这是一块内务府签发的皇宫通行令，凭此令当天内可自由进出皇宫。\n");
		set("value", 100);
		set("material", "iron");
	}
	setup();
        call_out("dest", 900);
}

void init()
{
}

void dest()
{
	destruct(this_object());
}
