void create()
{
	set_name("矿石", ({ "kuangshi" , "shi" }));
	set_weight(3000+random(5000));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一块普通的矿石。\n");
		set("value", 3000);
		set("kuangshi",1);
	}
	setup();
}
