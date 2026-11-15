// agate.c 玛瑙


inherit COMBINED_ITEM;

void create()
{
	set_name(HIR "玛瑙" NOR, ({ "agate" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIR "一块晶莹剔透的暗红色玛瑙。"NOR"\n");
		set("base_value", 50000);
		set("base_weight", 1);
		set("base_unit", "块");
		set("can_be_enchased", __DIR__"fagate");
		set("enchased_need", 3);
		set("magic/type", "fire");
		set("magic/power", 100);
	}
	set_amount(1);
	setup();
}
