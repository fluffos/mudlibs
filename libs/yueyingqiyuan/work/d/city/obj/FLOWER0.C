//flower.c
inherit ITEM;

void create()
{
    set_name("[1;31m红玫瑰[2;37;0m", ({ "red flower", "rose","flower" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一朵娇艳欲滴的黄玫瑰。\n");
		set("unit", "朵");
		set("value", 100);
		set("material", "plant");
		set("armor_prop/armor", 0);
		set("armor_prop/personality", 3);
		set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
		set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");
		set("female_only", 1);
	}
    setup();
}
