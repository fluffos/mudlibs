// cagate.c 玛瑙残片


inherit COMBINED_ITEM;

void create()
{
	set_name(HIR "玛瑙残片" NOR, ({ "chipped agate" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIR "一片的玛瑙碎片，发出微弱的红光。"NOR"\n");
		set("base_value", 20000);
		set("base_weight", 1);
		set("base_unit", "块");
		set("can_be_enchased", __DIR__"agate");
		set("enchased_need", 3);
		set("magic/type", "fire");
		set("magic/power", 50);
	}
	set_amount(1);
	setup();
}
