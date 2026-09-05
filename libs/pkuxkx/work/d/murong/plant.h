#include <ansi.h>
void init()
{
	add_action("do_zai","zai");
         add_action("do_zai","zhong");
         add_action("do_zai","plant");
}

int do_zai()
{
	object me;
	me=this_player();
	if (me->is_busy())
	return notify_fail("你正忙着呢。\n");
	if (!(present("chu tou",me)))
	{
		write("没带锄头怎么种啊。\n");
		return 1;
	}
	message_vision("$N卷起衣袖，拿起锄头，在地上刨了起来。\n",me);
	me->add_busy(30);
	call_out("wait1",10,me);

	return 1;
}

void wait1(object me)
{
	object obj;
	if (!me) return;
	if (!obj=(present("hua zhong",me)))
	{
		write("没有花种怎么种。\n");
		return;
	}
	tell_object(me, "\n............................\n" ) ;
	tell_object(me, "\n.......................\n" ) ;
	tell_object(me, "\n...................\n" ) ;
	tell_object(me, "\n..............\n" ) ;
	tell_object(me, "\n.....\n" ) ;
	message_vision("刨了半响，$N累得满头大汗，终于在地上弄了小坑。\n",me);
	message_vision("$N用衣袖擦了擦脸上的汗，把身上的种子放到坑里。\n",me);
	message_vision("$N又把土拢向坑内，把种子埋了起来。\n",me);
	destruct(obj);
	call_out("wait2",10,me);
}
void wait2(object me)
{
	if (!me) return;
	tell_object(me, "\n............................\n" ) ;
	tell_object(me, "\n.......................\n" ) ;
	tell_object(me, "\n...................\n" ) ;
	tell_object(me, "\n..............\n" ) ;
	tell_object(me, "\n.....\n" ) ;
	message_vision("慢慢地，一个小芽从地下钻了出来。\n",me);
	message_vision("它慢慢的长大，长出新枝，张满绿叶。\n",me);
	call_out("wait3",10,me);
}
void wait3(object me)
{
	object ob;
	if (!me) return;
	tell_object(me, "\n............................\n" ) ;
	tell_object(me, "\n.......................\n" ) ;
	tell_object(me, "\n...................\n" ) ;
	tell_object(me, "\n..............\n" ) ;
	tell_object(me, "\n.....\n" ) ;
	message_vision(HIM"一片粉红的茶花开了。\n"NOR,me);
	message_vision(HIG"$N"+HIG+"欢呼起来，小心的把所有的茶花摘了下来。\n"+NOR,me);
	me->delete_temp("murong/chuhua");
	me->set_temp("murong/zhonghua",1);
	for (int i=0;i<2;i++)
	{
		ob=new("/d/murong/obj/hua");
		ob->move(me);
	}
}

