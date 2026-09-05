//瀑布水潭
//by icer
inherit ROOM;
object ob1;
void create()
{
        set("short", "水潭");        set("long", @LONG
这里是水潭之中，但见瀑布奔流而去，水沫四溅，流速甚急，很难立住脚跟。
    那对金娃娃就藏在潭底的一块大石之下。要想抓住(catch)它们，必须抬起
    (lift)这块大石。
LONG
);
set("exits", ([
                "out" :__DIR__"pubu",
]));

setup();
}

void init()
{
        add_action("do_none","get");
	add_action("do_lift","lift");
	add_action("do_catch","catch");
}
int do_none()
{
        write("什么？\n");
        return 1;
}
int do_lift(string arg)
{
	object fish,me;
	me=this_player();
	if (arg != "stone")
	return notify_fail("你要抬起什么东西？\n");
	if (((int)me->query_str()<25)||((int)me->query_skill("strike", 1)<60))
	{
		me->add("neili",-100);
		return notify_fail("你使出了吃奶的力气，可还是搬不动这块大石。\n");
	}
	write("你伸手到怪鱼遁入的那大石地下用力一抬，双掌向上猛举，水声响处，\n
大石竟被你抬了起来。你紧接着对着大石用力一掌，大石受水力与\n
掌力夹击，擦过你身旁，滚落到下面的深渊去了。\n");
        ob1=new("/clone/yidengtask/fish");
	ob1->move(environment(me));
	return 1;
}
int do_catch(string arg)
{
	object me;
	me = this_player();
	if (arg != "fish")
	return notify_fail("你要抓什么？\n");
	if ( me->query_temp("marks/渔4"))
	return notify_fail("金娃娃已经给你抓走啦！\n");
	if (!( present("fish", environment(me))))
	return notify_fail("鱼还藏在大石底下呢！");
	if ((int)me->query_dex()<30)
	return notify_fail("也许是你不够灵活，怎么也抓不到金娃娃。\n");
	if (random(4)==1)
	{
		write("你抓到了金娃娃！赶快上岸吧！\n");
                new("/clone/yidengtask/fish")->move(me);
		destruct(ob1);
		me->set_temp("marks/渔4",1);
	
	}
	else {
		write("你几乎抓住了金娃娃，可是就在最后一下它们逃脱了。\n");
	}
	me->add("neili",-30);
	me->add("qi",-30);
	return 1;
}

int valid_leave(object me, string dir)
{
        if (me->query_skill("dodge")<150)
	{
		    tell_object(me, "迎面一个浪头打来，你被打到了下游的深渊里。\n");
		    message("vision", "只见" + me->query("name") + "被一个浪头打了出去，再也没出现。\n", environment(me), me);
		    me->receive_wound("qi", (int)me->query("max_qi"));
		    me->move("/d/death/gate");
		    me->unconcious();

        return 0;}
	write("你腾空而起，在空中美妙的转了个身，稳稳地落在了地上。\n");
	return ::valid_leave(me, dir);
}
