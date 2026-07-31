
inherit ITEM;

void create()
{
	set_name("油皮袋", ({ "oilbag" , "油皮袋"}) );
	set_weight(500);
	set_max_encumbrance(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个可放东西进水的油皮袋。\n");
		set("value", 1);
	}
}

int is_container() { return 1; }
