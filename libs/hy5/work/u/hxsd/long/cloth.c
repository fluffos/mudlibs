// baichou.c

inherit EQUIP;

void create()
{
    set_name("°×³ñÈ¹", ({ "baichou qun", "qun" }) );
        set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("armor_type", "cloth");
		set("value", 500000);
		set("armor_prop/dodge", 55);
		set("armor_prop/armor", 99);
	}
}
