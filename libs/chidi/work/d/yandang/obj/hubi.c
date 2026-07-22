
inherit ITEM;

void create()
{
	set_name("湖笔", ({ "hubi" , "湖笔"}) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", "一支沾满了黑墨的笔\n");
	}
}


