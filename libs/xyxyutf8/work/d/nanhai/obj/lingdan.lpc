inherit COMBINED_ITEM;

void init()
{
	add_action("do_eat", "eat");
}

void setup(){}

void create()
{
	set_name("灵丹", ({"ling dan", "dan"}));
	if( clonep())
		set_default_object(__FILE__);
	else {
		set("base_unit", "粒");
		set("unit","瓶");
		set("long", "这是一粒贵重的灵丹，吃下去能够养精活血。\n");
		set("value", 5000);
	}
	setup();
	set_amount(1);
}

int do_eat(string arg)
{
	object me = this_player();
	if( !arg || !id(arg) )
		return 0;
	if( me->query("kee")>=me->query("eff_kee") 
	 && me->query("sen")>=me->query("eff_sen") )
	    	return notify_fail("你现在精血充足。\n");
	me->receive_heal("sen", 50);
	me->receive_heal("kee", 50);
	message_vision("$N拿起一粒灵丹往嘴里一扔，嚼也没嚼就吞了下去。\n",me);
	if( query_amount()<=1 )
		destruct(this_object());
	else	add_amount(-1);	
	return 1;
}