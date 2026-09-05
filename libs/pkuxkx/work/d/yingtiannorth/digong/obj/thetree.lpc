inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIG"神木"NOR,({ "shen mu", "mu", "tree"}) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
				set("long","这是一棵极为高大的树，树冠遮蔽之下，竟不见天光。\n");
                set("unit", "棵");
                set("value", 0);
                set("material", "wood");
				set("no_get","你也太异想天开了。\n");
			}
	setup();
}

void init()
{
	add_action("do_climb","climb");
}
int climb(object me)
{
	if (!me||!environment(me)||!environment(me)->query("ontree"))
	return 1;
	write(HIG"几经艰辛，你终于爬到了树顶！\n"NOR);
	me->move("/d/yingtiannorth/digong/level5treetop");
	message_vision(HIG"几经艰辛，$N终于爬到了树顶！\n"NOR,me);
	return 1;
}
int do_climb(string arg)
{
	object me=this_player();
	if (me->is_busy())
	{
		write("你正忙着呢。\n");
		return 1;
	}
	if (arg!="up")
	{
		write("你只能向上爬(climb up)。\n");
		return 1;
	}
	me->add_busy(5);
	message_vision("$N向上方爬去。\n",me);
	me->move("/d/yingtiannorth/digong/level5ontree");
	call_out("climb",5+random(5),me);
	return 1;
}
