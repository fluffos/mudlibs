// baipao.c

inherit EQUIP;

void create()
{
    set_name("三点式泳装", ({ "yong zhuang","zhuang", }) )
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("armor_type", "cloth");
        set("value", 200);
        set("armor_prop/dodge", 9999);
        set("armor_prop/armor", 9999);
	}
}
