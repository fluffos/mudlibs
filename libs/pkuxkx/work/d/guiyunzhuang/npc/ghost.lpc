// NPC: /u/pingpang/npc/ghost.c
// Made by:pingpang

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("野鬼", ({ "ghost" }) );
	set("long",
		"这是一个人烟罕至的路，因而无法转世投胎的野鬼，它无依无靠，四处游荡。\n"
		"看见它一副孤苦伶仃的样子，你不禁起了一点怜悯之心。\n");		
	set("attitude", "peaceful");
	set("chat_chance", 80);
	set("chat_msg", ({
		HIW"野鬼用一双无神的眼睛看着你，空空洞洞的说到：“我想回家！”。\n"NOR,
	}) );      
	ghost = 1;
	set("combat_exp", 20000);

setup();
}
void init()
{
	object me, ob;
	object env;     
	add_action("do_lead", "lead");
	me = this_player();                                
	ob = this_object();
	env = environment(me);
	if( file_name(env)=="/d/guiyunzhuang/bridge"
	&& !me->query_temp("ghost")
	&& ob->query_temp("ghost") != 10)
	{
		ob->set_temp("ghost", 10);
		remove_call_out("lead");
		call_out("lead", 3, me);
	}      
	return;
}
void lead(object me)
{                        
	if( (int)me->query("kar") > 20 
	&& !me->query_temp("ghost")
	&& present("ghost",environment(me)) )
		tell_object(me,HIG"野鬼悄悄告诉你：“你能带我走(lead)吗？”\n"NOR);
}                                
int do_lead()
{            
	object me, ob;   
	string name;
	me = this_player();
	ob = this_object();   
	name = me->query("id");
	if( me->query_temp("ghost") == 5 )
		return notify_fail("你不是已经在为野鬼领路了吗？你还想干嘛啊？\n");
	if( me->query_temp("ghost") == 4)
		return notify_fail("人家不愿意跟你走，你干嘛，要强迫啊？\n");
	if( random((int)me->query("kar")) < 15 )
	{
		me->add_temp("ghost", 1);
		return notify_fail("看来野鬼似乎不愿意跟你走！\n");
	}
        command("follow"+" "+name);
	me->set_temp("ghost", 5);  
	ob->set_temp("leader",me->query("id"));
	return 1;
}	
