inherit ITEM;

void create()
{
	set_name("药师佛神像", ({ "shenxiang" , "xiang"}) );
	set_weight(500000);
	set("no_get",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "尊");
		set("long", "一尊石雕药师佛像.\n");
		set("value", 1);
             set("no_drop",1);
		set("material", "stone");
	}
setup();
}
