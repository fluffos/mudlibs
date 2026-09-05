#include <ansi.h>

void init()
{
	add_action("do_eat", ({"eat","fu"}));
	add_action("do_chop", ({"qie","chop"}));
}

int do_chop(string arg)
{
	object me=this_player(),obj;
	int num=6+random(4);
	if (me->is_busy())
	{
		write("你正忙着呢。\n");
		return 1;
	}
	if (!arg||member_array(arg,this_object()->parse_command_id_list())==-1)
	{
		return 0;
	}
	me->add_busy(1);
	message_vision(HIG+"$N"+HIG+"仔细的把手中的$n"+HIG+"切成小片。\n"+NOR,me,this_object());
	for (int i=0;i<num;i++)
	{
		obj=new(this_object()->query("product"));
		obj->move(me);
	}
	write("切割之后，你共计获得了"+chinese_number(num)+"片"+obj->query("name")+"。\n");
	destruct(this_object());
	return 1;
}
