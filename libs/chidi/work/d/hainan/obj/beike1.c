// beike1.c

inherit ITEM;

void create()
{
	set_name("贝壳", ({ "beike" }) );
	set_weight(10);
	if( !clonep() ) {
		set("unit", "个");
		set("value", 200);
		set("long", 
"这是个漂亮的贝壳！\n");
	}
	setup();
}
