// inherit object: liandan_lin.c

#include <ansi.h> 

inherit ROOM;

int do_cai(string arg);

void init()
{
	add_action("do_cai","cai");
	set("item_desc", ([
		"【草药】" : "看起来好像是一颗小草，走进一看却又有些不同寻常。\n"
		ZJOBACTS2"采药:cai yao\n",
	]));
}

int do_cai(string arg)
{
	object me = this_player();
	object ob;
	object ob1;

	if (query("last_cai")&&(time()-query("last_cai"))<30)
		return notify_fail("草药生长中，"+(query("last_cai")+30-time())+"秒钟之后成熟。\n");

	if (arg != "yao" && arg != "caoyao")
		return notify_fail("你要采什么。\n");

	if (me->query("combat_exp")<1000000)
		return notify_fail("你还是先提高自己的实战修为再来采药吧！\n");

	if (me->is_busy()||me->is_fighting()||me->query_temp("cai_yao"))
		return notify_fail("你正忙着呢，忙完再说吧！\n");
       
	if (query_temp("cai_user"))
		return notify_fail(query_temp("cai_user")->query("name")+"正在采集呢。\n");

	if ((int)me->query("jing") < 40)
		return notify_fail("你太疲倦了，休息一下吧。\n");

	if ((int)me->query("qi") < 40)
		return notify_fail("你太累了，休息一下吧。\n");

	message_vision("$N趴在地上，瞪大了眼睛在草丛中小心翼翼滴开始采摘草药。\n", me);
	me->set_temp("cai_yao",10);
	set_temp("cai_user",me);
	call_out("cai", 1, me);
	return 1;
}

int cai(object me)
{ 
	object ob;
	object ob1;
      int exp,pot;
	
	if (!me) return 0;
	if (present(me->query("id"),this_object())) 
		delete_temp("cai_user");

	if (! objectp(me) ||  ! living(me) ) {
		delete_temp("cai_user");
		return 0;
	}

	if ( present("du she", this_object()) || present("du langzhong", this_object()) || me->is_fighting() || environment(me) != this_object() ) {
		me->delete_temp("cai_yao");
		delete_temp("cai_user");
		tell_object(me,HIM"采集被打断！"NOR"\n");
		return 1;
	}

	if(me->query_temp("cai_yao")>0)
	{
		me->receive_damage("jing", 5);
		me->receive_damage("qi", 5);
		me->add_temp("cai_yao",-1);
		message_vision(HIY"$N"NOR"采集草药中："HIG+repeat_string("■",10-me->query_temp("cai_yao"))+repeat_string("□",me->query_temp("cai_yao"))+NOR"\n",me);
		call_out("cai", 1, me);
	}
	else
	{
		message_sort(HIG "$N" HIG"小心翼翼，终于将草药掘了出来。"NOR"\n", me);
            exp=20+random(11);
		me->add("combat_exp", exp);
		pot=me->improve_potential(exp-random(10));
		tell_object(me,  "你获得了一株不知名草药。"NOR"\n" );
		tell_object(me,  "你获得了" + chinese_number(exp) +	"点修为和" + chinese_number(pot) + "点潜能。"NOR"\n" );
		ob1 = new("/d/beijing/npc/dan/caoyao");
		ob1->move(me, 1);
		me->delete_temp("cai_yao");
		delete_temp("cai_user");
		set("last_cai",time());
		return 1;
	}

	if (random(100) > 98)
	{	 
		tell_room(environment(me), HIR "草丛中一阵晃动，突然钻出一条毒蛇。"NOR"\n");
		ob = new("/d/beijing/npc/liandan_dushe");
		ob->move(this_object());
		ob->kill_ob(me);
		me->kill_ob(ob);
	}
	else if (random(100)>98)
	{	 
		tell_room(environment(me), HIR "林子后面突然跳出一个凶神恶刹的男子，手提一把短刀向你扑来！"NOR"\n");
		ob = new("/d/beijing/npc/liandan_langzhong");
		ob->move(this_object());
		ob->kill_ob(me);
		me->kill_ob(ob);
	} 
	return 1;
}

