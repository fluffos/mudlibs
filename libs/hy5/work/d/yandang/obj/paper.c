
inherit ITEM;

void create()
{
	set_name("宋纸", ({ "paper" , "宋纸"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "一张宋时的泥金簪花筏.\n");
	}
}


