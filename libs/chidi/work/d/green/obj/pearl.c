//pearl.c
inherit ITEM;

void create()
{
        set_name("夜明珠", ({ "pearl" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "一颗灿烂的夜明珠。晚上发出的光芒可以照亮大地。\n");
                set("value", 10000);
 	}
	set_temp("light",1);
	set("no_shown", 1);
	setup();
}

