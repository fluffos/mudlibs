//chaifang2.c	柴房
//by bing
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","柴房");
	set("long",@LONG 
这是一处不知道是谁家的柴房，堆放着乱七八糟的
杂物和枯枝。光线很暗，你很难看清楚具体都有什么东
西，最好有个火来照明。
LONG
	);
	set("fired",0);

	set("exits", ([
		"east" : __DIR__"cunlu3",
	]));
	setup();

}

void init()
{
    object me=this_player();
    int i,count=0;
    object chai;
    object *all=all_inventory(this_object());
    add_action("do_get","get");
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("is_chai"))
        {
            count=1;
        }
    }
    if (userp(me)&&me->query("rynewbiejob/chufang/start")&&count<1)
    {
        chai=new(__DIR__"obj/chai");
        chai->move(this_object());
    }
}

int do_get(string arg)
{
    object me=this_player();
    if (arg=="all")
    {
        tell_object(me,"这里只能一件一件拿东西。\n");
        return 1;
    }
    if (arg=="chai huo"||arg=="chai"||arg=="chaihuo")
    {
        if (!me->query("rynewbiejob/chufang/start"))
        {
            tell_object(me,"一根柴火也偷，真是辱没你在江湖的威名啊。\n");
            return 1;
        }
        if (present("chai huo",me))
        {
            tell_object(me,"你身上不是有一根柴火了吗？\n");
            return 1;
        }
    }
}

int valid_leave(object me, string dir)
{
            if (dir == "east" && present("la zhu",me) && !me->query_temp("riyue/fire") && !query("fired") && me->query("combat_exp")>random(30000) )
	{
		message_vision("$N一转身，手上的蜡烛碰到了柴火，柴火立刻燃烧起来！\n",me);
		set("fired",1);
		me->set_temp("riyue/fire",1);
        me->start_busy(15);
          call_out("fire",3,me);
		return notify_fail(HIR "着火啦！\n" NOR);
	}

	if (dir == "east" && me->query_temp("riyue/fire"))
		return notify_fail("你正忙着呢！出不去！\n");
	
        return ::valid_leave(me, dir);

}

int fire(object me)
{
	me->receive_damage("qi",200,"被柴房大火烧");
	me->receive_wound("qi",50,"被柴房大火烧");
	me->add_temp("riyue/fire",1);
	
	if (me->query_skill("dodge") > 150 && me->query_temp("riyue/fire") == 2)
	{
		message_vision(HIR "火越烧越大，$N已经难以扑救，一转身，逃到了屋外。\n" NOR,me);
                me->delete_temp("riyue/fire");
		me->move(__DIR__"cunlu3");
                message("vision",me->name()+"从浓烟滚滚的柴房跑出来，焦头烂额，狼狈不堪。\n",environment(me),({me}));
		return 1;
	}
	else if (me->query_temp("riyue/fire") == 2)
		{
			message_vision(HIR "火越烧越大，$N已经难以扑救，可是也逃不出去。\n" NOR,me);
             call_out("fire",3,me);
			return 1;
		}
	
	if (me->query_skill("dodge") > 100 && me->query_temp("riyue/fire") == 3)
	{
		message_vision(HIR "$N已经被火包围，身上也着了火，$N一急，抱住头，缩身一滚，滚了出去。\n" NOR,me);
                me->delete_temp("riyue/fire");
		me->move(__DIR__"cunlu3");
                message("vision",me->name()+"从火光熊熊的柴房滚了出来，又打了几个滚，才把身上的火压灭。\n",environment(me),({me}));
		return 1;
	}
	else
	{
		message_vision(HIR "$N已经被火包围，逃不出去了。！\n" NOR,me);
                me->delete_temp("riyue/fire");
        me->save();
		me->die();
		return 1;
	}
}
		





