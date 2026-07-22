// zhushao
// 98.8.5  by emnil
// 10/6/2001 by augx@sj

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG"竹哨"NOR, ({ "zhushao","shao" }) );
	set("long",HIG"这是一只用来驯蛇的竹哨。\n"NOR);
	set("unit", "只");
	set("weight", 50);
	set("no_sell",1);
	set("no_get",1);
	set("no_steal",1);
	set("no_drop",1);
	set("no_give",1);
	set("value", 1);
} 

void init()
{
	add_action("do_xunshe","xunshe");
	add_action("do_zhaoshe","zhaoshe");
	add_action("do_fangshe","fangshe");
	add_action("do_nashe","nashe");
	add_action("do_chushe","chushe");
	add_action("do_she","she");
	add_action("do_huti","huti");
	add_action("do_gongji","gongji");
}

int do_xunshe(string arg)       
{
	object me = this_player();
	
	if((int)me->query_skill("dulong-dafa",1) < 100) 
		return notify_fail("你的毒龙大法修为不够，不能驯蛇。\n");
	if((int)me->query("eff_jingli") < 800) 
		return notify_fail("你的精血太少了，不能驯蛇。\n");		
	if( objectp(me->query_temp("sld/snake")) )
		return notify_fail("你已经拿到一条蛇了。\n");
	if((int)environment(me)->query("canfindsnake")!=1)
		return notify_fail("你在这里找不到蛇。\n");

	message_vision(HIG"$N拿出竹哨，幽幽的吹了起来，不一会儿，一条金光闪闪的小蛇从树林中钻了出来！\n"+
			  "$N把手指伸到蛇面前，小蛇吸起$N的精血，$N的脸上突然现出一丝金光！\n"NOR,me);
	me->add("eff_jingli",-2);
	me->set("sld/mysnake",1);
	me->set("sld/getsnake",0);
	return 1;
}

int do_zhaoshe(string arg)
{ 
	object me,ob;
	int lvl,exp;

	me = this_player();
	if( !(int)me->query("sld/mysnake") )
		return notify_fail("你还没有蛇呢！\n");
	if( (int)me->query("sld/getsnake") )
		return notify_fail("你已经拿到蛇了。\n");
	if((int)environment(me)->query("canfindsnake")!=1)
		return notify_fail("你在这里找不到蛇。\n");

	message_vision(HIG"$N拿出竹哨，幽幽的吹了起来，不一会儿，一条金光闪闪的小蛇串到$N的身上。\n"NOR,me);

	//seteuid(getuid());
	ob = new(__DIR__"ssnake");
	if (!ob) return notify_fail("异常错误：无法创建金蛇！\n");
	ob->set("owner",me);
	
	exp = me->query("combat_exp"); 
	if( exp < 100000) exp = 100000;
	ob->set("combat_exp",exp);
	
	ob->set("max_qi",me->query("max_qi"));
	ob->set("eff_qi",me->query("max_qi"));
	ob->set("qi",me->query("max_qi"));  
	ob->set("max_jing",me->query("max_jing"));
	ob->set("eff_jing",me->query("max_jing"));
	ob->set("jing",me->query("max_jing")); 
	
	ob->set("max_neili",me->query("max_neili"));
	ob->set("neili",me->query("max_neili"));
	ob->set("eff_jingli",me->query("eff_jingli"));
	ob->set("jingli",me->query("eff_jingli"));
	
	lvl = me->query("max_pot") - 100;
	ob->set_skill("force",lvl);
	ob->set_skill("dodge",lvl);
	ob->set_skill("parry",lvl);
	ob->set_skill("poison",lvl);
	ob->set_temp("apply/attack",lvl);
	ob->set_temp("apply/dodge",lvl);
	ob->set_temp("apply/parry",lvl);
	ob->set_temp("apply/force",lvl);
	ob->set_temp("apply/defense", lvl);
	ob->set_temp("apply/damage",(lvl/10)>20?(lvl/10):20);
	ob->set_temp("apply/armor", (lvl/3)>50?(lvl/3):50);

	ob->move(me);

	me->set("sld/getsnake",1);
	if( objectp(me->query_temp("sld/snake")) )
		destruct(me->query_temp("snake"));
	me->set_temp("sld/snake",ob);
	return 1;
}

int do_fangshe(string arg)      
{
	object me;
	object * all;
	int i,j;

	me = this_player();
	if( !(int)me->query("sld/getsnake") )
		return notify_fail("你没有拿到蛇。\n");
	if( !(int)environment(me)->query("canfindsnake") )
		return notify_fail("你不能在这里放蛇。\n");
		
	all = all_inventory(me);                      
	j=0; 
	for (i=0; i<sizeof(all); i++)
		if ( objectp(me->query_temp("sld/snake")) && all[i]==me->query_temp("sld/snake") ) j=1;
	if (!j) return notify_fail("你的蛇现在不在你身上！\n");

	message_vision(HIG"$N轻轻的把小蛇放下，拍拍它的头，小蛇轻叫一声就窜回树林中去了。\n"NOR,me);
	destruct(me->query_temp("sld/snake"));
	me->delete("sld/getsnake");
	me->delete_temp("sld/snake");
	me->delete_temp("sld/huti");
	
	return 1;
}

int do_nashe(string arg)        
{
	object * all,me;
	int i , j;

	me = this_player();
	if( !(int)me->query("sld/getsnake") )
                return notify_fail("你没有拿到蛇。\n");
 
	all = all_inventory(environment(me));                      
	j=0;
	for (i=0; i<sizeof(all); i++)
		if ( objectp(me->query_temp("sld/snake")) && all[i]==me->query_temp("sld/snake") ) j=1;
	if (!j) return notify_fail("你要拿的蛇不在这里呀！\n");

	message_vision("$N轻轻拿起小蛇。\n",me);
	(me->query_temp("sld/snake"))->move(me);

	return 1;
}

int do_chushe(string arg)       
{
	object * all,me;
	int i , j;

	me = this_player();
	if( !(int)me->query("sld/getsnake") )
		return notify_fail("你没有拿到蛇。\n");

	all = all_inventory(me);                      
	j=0;
	for (i=0; i<sizeof(all); i++)
		if ( objectp(me->query_temp("sld/snake")) && all[i]==me->query_temp("sld/snake") ) j=1;
	if (!j)  return notify_fail("你的蛇已经放出去了！\n");

	message_vision("$N轻轻放下小蛇。\n",me);
	(me->query_temp("sld/snake"))->move(environment(me));

	return 1;
}
	
int do_she(string arg)  
{
	object me,ob;

	me = this_player();
	if( !(int)me->query("sld/getsnake") )
		return notify_fail("你没有拿到蛇。\n");
 	if( !objectp(ob=me->query_temp("sld/snake")) )
		return notify_fail("你现在没有蛇。\n");
	if( environment(ob) == me )
		notify_fail("你的蛇还没有放出去！\n");	
		
	ob->do_command(arg);
	return 1;
}

int do_gongji(string arg)  
{
	object me,ob;

	me = this_player();
	if( !(int)me->query("sld/getsnake") )
		return notify_fail("你没有拿到蛇。\n");
 	if( !objectp(ob=me->query_temp("sld/snake")) )
		return notify_fail("你现在没有蛇。\n");
	if( environment(ob) != me )
		return notify_fail("蛇不在你身上！\n");
	if( !me->is_fighting() )
		return notify_fail("你并没有在战斗啊！\n");
		
	return notify_fail(ob->gongji());
}

int do_huti(string arg)  
{
	object me,ob;

	me = this_player();
	if( !(int)me->query("sld/getsnake") )
		return notify_fail("你没有拿到蛇。\n");
 	if( !objectp(ob=me->query_temp("sld/snake")) )
		return notify_fail("你现在没有蛇。\n");
	if( environment(ob) != me )
		return notify_fail("蛇不在你身上！\n");
	if( !me->is_fighting() )
		return notify_fail("你并没有在战斗啊！\n");
		
	return notify_fail(ob->huti());
}
