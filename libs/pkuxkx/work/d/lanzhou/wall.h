// Zine 兰州城

#include <ansi.h>
void init()
{
	object me=this_player();
	add_action("do_jump","jump");
	if (!me->query_temp("Lanzhou_Wall_Notice"))
	{
		me->set_temp("Lanzhou_Wall_Notice",1);
		tell_object(me,"城墙上随时可能被西夏军士围杀，走投无路的时候跳(jump)下去也许是不错的选择。\n");
	}
}

int do_jump()
{
	object me=this_player(),rm;
	if (me->is_busy()) 
	{
		write("你正忙着呢。\n");
		return 1;
	}
	message_vision(HBWHT+HIR+"$N"+HBWHT+HIR+"大喊一声，准备跳出城墙……\n"+NOR,me);
	if (query("jump_path")&&stringp(query("jump_path"))&&load_object(query("jump_path"))&&random(2))
	{
		rm=load_object(query("jump_path"));
		tell_room(rm,me->name()+"从城墙上直接跳落了下来。\n");
		me->move(rm);
	}
	else
	{
		rm=load_object(replace_string(base_name(this_object()),"wall","outwall"));
		if (!rm) 
		{
			write("你还无法战胜心中的恐惧，横不下心来跳下去。\n");
			return 1;
		}
		else
		{
			tell_room(rm,me->name()+"从城墙上直接跳落了下来。\n");
			me->move(rm);
		}
	}
	write(RED+"从几丈高的城墙直接跳下，你一阵气血翻腾。\n"+NOR);
	if (me->query("qi")>500)
	me->add("qi",-300);
	else
	me->unconcious();
	if (me->query_skill("dodge")<1000)
	me->add_busy(2+random(2));
	return 1;
}