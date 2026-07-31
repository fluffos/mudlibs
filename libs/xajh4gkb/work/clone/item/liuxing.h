// by Amis 2006-9-23 20:18

#include <ansi.h>

void init()
{
	add_action("block_cmd","beg",1);
	add_action("block_cmd","steal",1);
	add_action("block_cmd","sleep",1);
	add_action("do_dig","digging",1);
}


int block_cmd()
{
	object ob = this_object();
	if ( ob->query("定做/liuxing") )
	{
		write("由于刚出现过流星，附近有不少村民围观，你还是收敛点吧！\n");
		return 1;
	}
}

int do_dig()
{
	object ob,me,obj;	
	object *usr;
	string str;	
	int i,ip_cnt;

	ob = this_object();
	me = this_player();
	if ( !ob->query("定做/liuxing") ) return 0;	
	if ( !(present("tie qiao", me)) && !(present("tie chan", me)))
		return notify_fail(YEL"\n没有工具你挖得动吗？！\n"NOR);
    if( me->is_busy() || me->is_fighting() ) 
        return notify_fail("你正忙着呢！\n");     
	if ( me->query("jing") < 50 || me->query("qi") < 50)
		return notify_fail("你实在太累了，歇歇吧！\n");
//	if ( me->query_temp("ip_liuxing") )	
//		return notify_fail("加油呀！再挖挖就发家致富了。\n");
//放开IP管制	
	usr = get_all_user();
	str=query_ip_number(me);
	ip_cnt=0;
	for(i=0; i<sizeof(usr); i++)
	{
		if (str==query_ip_number(usr[i]) && usr[i]->query_temp("ip_liuxing")) ip_cnt++;
	}
	if ( ip_cnt > 1 ) 
	{
		write("这个IP上挖流星的玩家太多了，给其他人一个机会吧！\n");	
		return 1;
	}
			
	message_vision("$N抡起铁锹，开始一阵猛敲乱砸。\n", me);
	me->set_temp("ip_liuxing", 1);
	me->receive_damage("jing", 15 + random(10) );
	me->receive_damage("qi", 15 + random(10) );	
	if ( living(me) )
	{
//		me->delete_temp("ip_liuxing");
		if ( random(120)==1 )	//获得醉月玄晶
		{
			obj=new("/clone/item/zuiyue-xuanjing");
			obj->move(me);
			message_vision(HIC"$N正挖间忽然碰到一个异常坚硬的物体，刨出来一看，赫然是"+obj->query("name")+"！\n"NOR, me);
			write(HIG"你竟然发现了极其难得一见的材料，简直欣喜若狂，兴奋无比！\n"NOR);
			message("channel:chat", HIR"【天外流星】"+HIM"听说 "HIG+me->name(1)+HIM" 在流星陨落之地挖到了稀世宝物 "HIM+obj->name(1)+"("+obj->query("id")+")。\n"NOR,users() );  //2016.6.15阿飞改，增加显示物品的id
		}		
		else if ( random(30)==2  )	//获得火龙宝石
		{
			obj=new("/clone/gem/gem3");
			obj->move(me);
			message_vision("$N的榔头忽然被一物碰出点点火星，刨出来一看，竟然是"+obj->query("name")+"！\n", me);
		}		
/*		else if ( random(100)==300 )	//获得1星装备
		{
			obj=new("/clone/tzbox/one-box");
			obj->move(me);
			message_vision("$N的榔头突然光芒闪耀，定睛一看，竟然是"+obj->query("name")+"！\n", me);
		}
		else if ( random(100)==400 )	//获得1星武器
		{
			obj=new("/clone/tzbox/wp1-box");
			obj->move(me);
			message_vision("$N的榔头突然光芒闪耀，定睛一看，竟然是"+obj->query("name")+"！\n", me);
		}		
		else if ( random(100)==500 )	//获得动态宝石
		{	
			switch ( random(7) )
			{
			case 0: obj=new("/quest/baoshi/baoshis/earth light");
				break;
			case 1: obj=new("/quest/baoshi/baoshis/fire light");
				break;
			case 2: obj=new("/quest/baoshi/baoshis/gods light");
				break;
			case 3: obj=new("/quest/baoshi/baoshis/justice light");
				break;
			case 4: obj=new("/quest/baoshi/baoshis/love light");
				break;
			case 5: obj=new("/quest/baoshi/baoshis/mercy light");
				break;
			case 6: obj=new("/quest/baoshi/baoshis/sea light");
				break;			
			}				
			obj->move(me);
			message_vision("$N似乎挖到了什么东西，刨出来一看，竟然是"+obj->query("name")+"！\n", me);
		}
		else if ( random(100)==600 )	//获得优化符
		{
			obj=new("/clone/map/obj/youhua-fu");
			obj->move(me);
			message_vision("$N的榔头突然光芒闪耀，定睛一看，竟然是"+obj->query("name")+"！\n", me);
		}	*/	
		else 
		{
			message_vision("$N你累的满头大汗，结果啥也没挖到。\n", me);	
		}
	}
	me->start_busy(3);		
	return 1;
}
