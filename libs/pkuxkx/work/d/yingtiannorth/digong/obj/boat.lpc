inherit ITEM;
#include <ansi.h>

int is_KARMA_BOAT()
{
	return 1;
}
void create()
{
	set_name("小船",({ "xiao chuan", "chuan", "boat"}) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
				set("long","这是一艘小船，大家可以登船("+HIR+"board"+NOR+")。\n");
                set("unit", "艘");
                set("value", 0);
                set("material", "wood");
				set("no_get",1);
			}
	setup();
}

void init()
{
	add_action("do_board","board");
}
int do_board()
{
	object me=this_player(),rm=load_object("/d/yingtiannorth/digong/level4boat");
	if (me->is_busy())
	{
		write("你正忙着呢。\n");
		return 1;
	}
	me->add_busy(2+random(2));
	message_vision("$N飞身跳上了$n。\n",me,this_object());
	if (rm)
	{
		tell_room(rm,me->name()+"登上了船。\n");
		me->move(rm);
		rm->set("from",environment(this_object())->query("river"));
		rm->set("off_boat",this_object());
		rm->set("boardfrom",environment(this_object()));
	}
	else
	write("船坏了，和WIZ报告吧。\n");
	return 1;
}
