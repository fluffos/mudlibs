inherit ITEM;

void create()
{
        set_name("半透明的大石头", ({ "dashi" , "stone"}) );
	set_weight(500000);
	set("no_get",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "一块玲珑的石头,隐隐霞光流转.\n");
		set("value", 1);
             set("no_drop",1);
		set("material", "stone");
	}
setup();
}
