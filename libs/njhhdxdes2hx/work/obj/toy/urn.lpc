// urn.c

inherit ITEM;

void create()
{
	set_name("药罐", ({ "urn" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"这是用来煎药的药罐，你可以把适当份量的药材\n"
			"放进去，然後将药罐放到火炉上煎。\n"
		);
		set("unit", "个");
		set("weight", 1200);
		set("value", 600);
	}
	set_max_encumbrance(1500);
}
