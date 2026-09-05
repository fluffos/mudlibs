inherit ITEM;
#include <ansi.h>

int is_KARMA_TREE()
{
	return 1;
}
void create()
{
	set_name("树木",({ "shu mu", "shu", "tree"}) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
				set("long","这是一棵新砍下的树木。\n");
                set("unit", "棵");
                set("value", 0);
                set("material", "wood");
				set("no_get","这棵树实在太重了，你只能推(tui)着它走。\n");
			}
	setup();
}

void init()
{
	add_action("do_tui","tui");
	add_action("do_xiao","xiao");
}
int do_xiao()
{
	int allow;
	object obj,product, me=this_player();
	if (me->is_busy())
	{
		write("你正忙着呢。\n");
		return 1;
	}
	if (me->query_temp("weapon")&&objectp(obj=me->query_temp("weapon"))&&obj->is_KARMA_AXE()) allow=1;
	else if (me->query_temp("secondary_weapon")&&objectp(obj=me->query_temp("secondary_weapon"))&&obj->is_KARMA_AXE()) allow=1;
	if (!allow)
	{
		tell_object(me,RED"你要把这棵树削成木材，需要拿一把斧头。\n"NOR);
		return 1;
	}
	if (me->query_temp("karma/level4/skill")!="handicraftsman")
	{
		tell_object(me,"你不擅长制造木材，找个擅长的人来做吧。\n");
		return 1;
	}
	me->add_busy(2+random(2));
	message_vision("$N把$n去掉枝叶，削成一块木材。\n",me,this_object());
	product=new(__DIR__"cai");
	product->move(environment(me));
	this_object()->move(VOID_OB);
	destruct(this_object());
	return 1;
}
int do_tui(string arg)
{
	mapping cdir=(["east":"东面","west":"西面","south":"南面","north":"北面"]);
	object me=this_player();
	string room,*dirs=({"east","west","north","south"});
	if (me->is_busy())
	{
		write("你正忙着呢。\n");
		return 1;
	}
	if (member_array(arg,dirs)==-1)
	{
		write("这里的路比较狭窄，你只能往north,south,west或者east方向推。\n");
		return 1;
	}
	if (!room=environment(me)->query("exits/"+arg))
	{
		write(arg+"方向推不过去。\n");
		return 1;
	}
	me->add_busy(2+random(2));
	message_vision("$N运足全身力气，将$n向"+cdir[arg]+"方向推去。\n",me,this_object());
	this_object()->move(room);
	me->move(room);
	return 1;
}