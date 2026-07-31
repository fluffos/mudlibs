#include <ansi.h>
int do_tiao(string arg)
{
	object me;
	me=this_player();
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if ( !arg || arg != "shenyuan")
       		return notify_fail("你要往哪跳？\n");
	if( !me->query_temp("tiaoya")){
		write(HIR"这个悬崖如此凶险，你就这么跳下去只怕凶多吉少，你还是再考虑一下吧。\n"NOR);
		write(HIR"决定跳就敲（yes），改变主意就敲（no）。\n"NOR);
		me->set_temp("tiaoya", 1);
		return 1;
	}
	write("你到底怎么决定的？\n");
	return 1;
}

int do_yes()
{
	object me = this_player(); 
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if( !me->query_temp("tiaoya") )
		return 0;
	message_vision(HIR"$N犹豫再三，终于下定决心，两眼一闭，涌身向崖底跳去！\n"NOR, me);
	me->delete_temp("tiaoya");
	message_vision(HIR"\n$N身体冲开迷雾，只感觉耳边生风，向崖底直坠下去。\n"NOR,me);
	if ((int)me->query("kar",1) >= 28){
		call_out("win", 1);
		return 1;
        	}
	call_out("fail", 1);
	return 1;	
	
}

int do_no()
{
	object me;
	me=this_player();
	
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if( !me->query_temp("tiaoya") )
		return 0;
	write(HIG"你思虑再三取消了跳下去的决定。\n"NOR);
	me->delete_temp("tiaoya");
	return 1;
}

int win()
{
	object me;
	me=this_player();
	write(HIR"\n你身体距离谷底越来越近，定睛看去，谷底原来是一片水潭！\n"NOR,);
	write(HIR"\n你在空中，身体已经不受控制，直接向水中落去。\n"NOR);
	write(HIR"\n扑通一声，你肚子首先入水，五脏六腑一阵翻滚。张嘴想要惊呼，咕噜咕噜，\n"+
                 "反而被灌了一肚子水。\n"NOR);
       me->move(__DIR__"guditan1");
       tell_room(environment(me), "只听到一声惨叫，"+me->name() + "从天空直坠了下来。\n", ({ me }));
       tell_room(environment(me), me->name() + "向下面径直沉了下去。\n", ({ me }));
       me->receive_damage("jing", 100);
       me->receive_damage("qi", 100);
       me->move(__DIR__"guditan2");
       tell_room(environment(me), me->name() + "从上面直坠了下来。\n", ({ me }));
       tell_room(environment(me), me->name() + "向下面径直沉了下去。\n", ({ me }));
       me->receive_damage("jing", 200);
       me->receive_damage("qi", 200);
       me->move(__DIR__"guditan3");
       tell_room(environment(me), me->name() + "从上面直坠了下来。\n", ({ me }));
       tell_room(environment(me), me->name() + "向下面径直沉了下去。\n", ({ me }));
       me->receive_damage("jing", 300);
       me->receive_damage("qi", 300);
       me->set("water", me->max_water_capacity()+200);
       me->move(__DIR__"guditan4");       
       tell_room(environment(me), me->name() + "从上面直坠了下来。\n", ({ me }));
       message_vision (HIB"$N只觉得头晕晕的，身体浸在冰冷的水中，不住的颤抖。\n"NOR,me);
       return 1;
	
}

int fail()
{
	object me, tmp;
	object *ob;
	int i;
	me= this_player();
	write(HIR"\n你身体距离谷底越来越近，定睛看去，谷底原来是一片水潭！\n"NOR,);
	write(HIR"\n你在空中，身体已经不受控制，直接向潭边一块大石头坠去！\n"NOR, );
	write(HIR"\n你急转身形，想要调整方向，无耐四体悬在空中，飘忽忽的浑不着力，眼看着\n"+
                 "距离石头越来越近了！这时侯你心中不禁泛起一丝悔意：小龙女爱的又不是我，\n"+
                 "我跳下来干什么？\n"NOR);
       me->move(__DIR__"gudi");
       me->set_temp("last_damage_from","跳下山崖摔");
       me->unconcious();
       me->die();
       	if (tmp = present("corpse", this_object())) 
	{
		ob = deep_inventory(tmp);
		i = sizeof(ob);
		while (i--) if (userp(ob[i])) ob[i]->move(this_object());
		destruct(tmp);
               if (me) tell_room(this_object(), me->name()+"的尸骨都找不到了。\n");
	}
	return 1;
}
