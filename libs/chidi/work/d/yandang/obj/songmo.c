
inherit ITEM;

void create()
{
	set_name("宋墨", ({ "songmo" , "宋墨"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "正宗的宋墨,由百年老松熏制而成.\n");
	}
}


