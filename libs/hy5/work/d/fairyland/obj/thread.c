// thread.c
// By jpei

inherit ITEM;

void create()
{
	set_name("细丝", ({ "thread", "xi si", "si" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根由树皮搓成的细丝。\n");
		set("value", 1);
		set("material", "wood");
	}
	setup();
}
