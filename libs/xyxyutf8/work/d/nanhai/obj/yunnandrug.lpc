// yunnandrug.c 云南白药
inherit COMBINED_ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("云南白药", ({"yunnan baiyao", "baiyao", "yao","drug"}));
	if( clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("base_unit", "粒");
		set("long", "这是一瓶贵重的云南白药，省着点用。\n");
		set("value", 5000);
		set("no_sell",1);
	}
	setup();
	set_amount(1);
}

int do_eat(string arg)
{
	object me = this_player();
	if( !arg || !id(arg) )
		return 0;
	if( me->query("eff_kee")>=me->query_maxkee()
	 && me->query("eff_sen")>=me->query_maxsen() )
		return notify_fail("没病别乱吃药。\n");
	this_player()->receive_curing("kee", 150);
	this_player()->receive_curing("sen", 150);
	message_vision("$N拿起瓶云南白药往嘴里一倒，胡乱咽了下去。\n", this_player());
	if( query_amount()<=1 )
		destruct(this_object());
	else	add_amount(-1);	
	return 1;
}

