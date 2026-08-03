// by Amis 2006-9-23 20:18

#include <ansi.h>

void init()
{
		add_action("block_cmd","beg",1);
		add_action("block_cmd","steal",1);
		add_action("block_cmd","sleep",1);
		
		add_action("do_go","go");
		add_action("do_dig","digging",1);
		
		//this_player()->set_temp("marks/守卫", 1);

}


int block_cmd()
{
		object ob = this_object();
		if ( ob->query("定做/liuxing") ){
		write("由于刚出现过流星，附近有不少村民围观，你还是收敛点吧！\n");
    return 1;
  	}
}

int do_dig()
{
		object obj,ob = this_object(),me = this_player();
		if ( !ob->query("定做/liuxing") )
		return 0;	

    if ( !(present("tie qiao", me)) && !(present("tie chan", me)))
        return notify_fail(YEL"\n没有工具你挖得动吗？！\n"NOR);

    if( me->is_busy() || me->is_fighting() ) 
        return notify_fail("你正忙着呢！\n");     
        
		if ( me->query("jing") < 50 )
		return notify_fail("你实在太累了，歇歇吧！\n");	
		
			
		message_vision("$N抡起铁锹，开始一阵猛敲乱砸。\n", me);	
		me->start_busy(2);

		if ( random(1000)==1 )	//获得醉月玄晶
		{
				obj=new("/clone/item/zuiyue-xuanjing");
				obj->move(me);
				//ob->set("yuntie",1);
				message_vision(HIC"$N正挖间忽然碰到一个异常坚硬的物体，刨出来一看，赫然是"+obj->query("name")+"！\n"NOR, me);
				write(HIG"你竟然发现了极其难得一见的材料，简直欣喜若狂，兴奋无比！\n"NOR);		
				return 1;
		}		
		else if ( random(200)==2  )	//获得火龙宝石
		{
				obj=new("/clone/gem/gem");
				obj->move(me);
				message_vision("$N的榔头忽然被一物碰出点点火星，刨出来一看，竟然是"+obj->query("name")+"！\n", me);
				return 1;
		}		
		else if ( random(100)==3 )	//获得1星装备
		{
				obj=new("/clone/tzbox/one-box");
				obj->move(me);
				message_vision("$N的榔头突然光芒闪耀，定睛一看，竟然是"+obj->query("name")+"！\n", me);
				return 1;
		}
		else if ( random(100)==4 )	//获得1星武器
		{
				obj=new("/clone/tzbox/wp1-box");
				obj->move(me);
				message_vision("$N的榔头突然光芒闪耀，定睛一看，竟然是"+obj->query("name")+"！\n", me);
				return 1;
		}		
		else if ( random(100)==5 )	//获得动态宝石
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
				return 1;
		}
		else if ( random(100)==6 )	//获得优化符
		{
				obj=new("/clone/map/obj/youhua-fu");
				obj->move(me);
				message_vision("$N的榔头突然光芒闪耀，定睛一看，竟然是"+obj->query("name")+"！\n", me);
				return 1;
		}		
		else 
		{
			message_vision("$N你累的满头大汗，结果啥也没挖到。\n", me);	
		}
		me->receive_damage("jing", 15 + random(10) );
		
		return 1;
}

