// caoyao.c 草药

inherit ITEM;

void setup()
{}


void create()
{
	set_name("制成的草药", ({"caoyao", "yao"}));
    set("is_caoyaoed",1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "副");
		set("long", "这是一副制好的草药。\n");
		set("value", 100);
	}
	setup();
}

