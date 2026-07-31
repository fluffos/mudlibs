inherit ITEM;

void create()
{
	set_name("海螺", ({ "hailuo" }) );
	set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "个");
		set("value", 100);
		set("long", 
"海中的一中贝类动物,在海滩上常能见到！\n");
	}
	setup();
}
