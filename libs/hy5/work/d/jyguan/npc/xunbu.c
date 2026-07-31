// bukuai.c 捕快
// Freeze(Rtm) 编写  Beta 1.1 目前的问题是-当着捕快杀了人捕快不会马上采取行动 :P
// 版权为 超频 工作室所有 / 未经许可不得复制、使用、改动
// 1998/9/19

#include <ansi.h>
inherit NPC;

void catched(object me,object dest);
void greeting(object ob);
int catch_pk(object me,object dest);
int waiting(object me, object dest);
int checking(object me, object dest);

void create()
{
	set_name("捕快", ({ "bu kuai", "bu", "kuai" }));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 30);
	set("dex", 16);
	set("long", "看那样子就是场面上的老手，行走于黑、白两道...\n");
	set("combat_exp", 100000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);
	
        set("chat_chance",10);
        set("chat_msg",({
     "捕快哼了一声，说道：“有我在就谁也别想杀人...谁要是杀了人给我找麻烦，就让他妈的去坐牢！”\n",
     BLU"捕快低声嘟囔着：遇上杀人我才不理会呢！却来个欲擒故纵，只等他杀人得手逃去我才缉拿，如此就有赏银花了...哼哼...\n"NOR,
        (: random_move :)
	}));

	setup();
	carry_object("/d/city/obj/gangjian")->wield();
	carry_object("/d/city/obj/tiejia")->wear();
}

void init()
{
	object ob;
	::init();

	if (interactive(ob = this_player()))
        {
		remove_call_out("greeting");
	        call_out("greeting", 0, ob);
	}        
}

void greeting(object ob)
{
        object me;
        me = this_object();

	if(!ob || environment(ob) != environment()) return;
	if ( ob->query_condition("killer") )
	{
                if ( ! is_fighting()) 
                {
			call_out("catch_pk",0,me,ob);
			return;	
		}
		else
		{
			message_vision(HIC "$N对$n说道：听说你个小混蛋杀了人，等我忙完了再来收拾你！"
                                +RANK_D->query_rude(ob)+"，算你命大，再留你多活几天！\n" NOR, me, ob);
			return;
		}
        }
	else
	{
		command("say 他妈的，今天怎么没有人杀人！拿不着人老子花什么...闷死我了...");	
//		init();
	}
	return;
}

int catch_pk(object me,object dest)
{
	if( objectp(dest) && present(dest, environment(me))
		 && !environment(me)->query("no_fight"))
	{
//		if (dest->query("qi") == 0 || dest->query("qi") <= 30 ) 
		if ( dest->query("qi") <= 40)
//		if ( dest->query("qi") == 0 )
		{
			catched(me,dest);
               	        return 1;
		}

		message_vision(HIY "$N对$n说道：听说你杀了人，乖乖儿跟我回去查个清楚，否则让你"
			+RANK_D->query_rude(dest)+"见阎王！\n" NOR, me, dest);
		me->set_leader(dest);
                me->fight_ob(dest);
                
		dest->fight_ob(me);
               
		call_out("checking", 0,  me, dest);
		
	}
	else  
		call_out("waiting", 1, me, dest);
	
	return 1;
}

int waiting(object me, object dest)
{
	if ( objectp(dest) )
	{
		if (dest->is_ghost())
		{
			dest->apply_condition("killer",0);
			return 1;
		}
		else if (me->is_fighting() && present(dest, environment(me)))
		{
			call_out("checking", 0, me);
			return 1;
		}
		     else if (!me->is_fighting() && present(dest, environment(me)))
		     {
		     	      call_out("checking",0,me);
			      return 1;
		     }			
	}		
	
	remove_call_out("waiting");
	call_out("waiting", 10, me);
    return 1;
}

int checking(object me, object dest)
{
	object ob;
        
	if (me->query("qi") == 0)
		return 1;

	if (me->is_fighting()) 
	{
		call_out("checking",0,me);		
	        return 1;
	}
	else  init();

	if (objectp(ob = present("corpse", environment(me)))
		 && ob->query("victim_name") ==	dest->query("name") )
	{
		dest->apply_condition("killer",0);
		me->set_leader(0);
        	return 1;
	}

//	if (dest->query("qi") == 0 || dest->query("qi") <= 30 ) 
	if ( dest->query("qi") <= 40 )
//	if ( dest->query("qi") == 0 )
	{
		command("say 这次是checking()在工作");
		catched(me,dest);
		return 1;
	} 
	else if (dest->query("qi") > 0) init();

	call_out("waiting", 0, me, dest);
	return 1;
}

void catched(object me,object dest)
{	
	command("say "+(string)dest->query("id")+(string)dest->query("qi"));
	
//!	dest->apply_condition("gvmt_jail", 20);
	dest->unconcious(); //可能有不良影响	
//	command("get "+(string)dest->query("id"));
	command("say 呵，就这么两下子还敢跟老子叫板！你已经没着了，看绑吧！" );
	message_vision(HIC"只听“哗啦”一声，$N抛出锁链将人犯锁住，押解着"+(string)dest->query("name")+"向嘉峪关方向赶去。\n"NOR,me);

        dest->move("/wizhome/rtmhome/gvmt/jianyu_do");
	me->move("/wizhome/rtmhome/gvmt/jianyu_do");
	

	dest->apply_condition("killer",0);
//	command("drop "+(string)dest->query("id"));
	me->set_leader(0);
		
	message_vision(HIC"$N啐了口唾沫，将"+(string)dest->query("name")+"重重的掷在地上，狠狠地踢了一脚，留下一个清晰的鞋印，转身锁上牢门离开。\n"NOR,me);

	switch ( random(6) )
	{
	case 0 :
		me->move("/d/city/guangchang");
		break;
	case 1 :
		me->move("/d/city/beidajie1");
		break;
	case 2 :
		me->move("/d/city/nandajie1");
		break;
	case 3 :
		me->move("/d/city/xidajie1");
		break;
	case 4 :
		me->move("/d/city/dongdajie1");
		break;
	case 5 :
		me->move("/d/city/wumiao");
		break;
	}
	message_vision("$N走了过来。\n",me);
           	
	return;
}



