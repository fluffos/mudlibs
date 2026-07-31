// tupu.c

inherit ITEM;

void create()
{
	set_name("拳法图谱", ({ "quanfa tupu"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "幅");
		set("long", "这是一幅脏兮兮的图谱。\n");
	}
}