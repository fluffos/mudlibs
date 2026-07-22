#include <ansi.h>
inherit NPC;

void create()
{
	string gender;
	mapping name;

	gender = ({"male","female"})[random(2)];
	name = NAME_D->random_name(gender);
	set_name(name["name"],name["id"]);
	if( gender=="male" )
		set("gender","男性");
	else	set("gender", "女性");
	set("long", "这是一位外地游客，看起来风尘仆仆，但依然兴致不减。\n");
        set("age", 20+random(20));
	set("str", 30);
	set("con", 30);
        set("combat_exp", 35000);
	set("max_kee", 500);
	set("force", 100);
	set("max_force", 100);
	set("force_factor", 5);
        set("shen_type", 1);
	set("attitude", "heroism");
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
	set_skill("force", 50);

        setup();
        if( query("gender")=="男性" )
        	carry_object("/d/obj/cloth/linen")->wear();
        else	carry_object("/d/obj/cloth/skirt")->wear();	
	add_money("gold",5); 
}

void die()
{
	string name;
	object target,owner;
	
	owner = query("owner");
	if( !owner || !objectp(owner) || !living(owner) )
	{
		::die();
		return;
	}
	
	target = query_temp("last_damage_from");
	
	if( !userp(target) )
	{
		message_vision("$N死了。\n",this_object());
		destruct(this_object());
		return;
	}
	
	if( target!=owner )
	{
		CHANNEL_D->do_channel(this_object(),"rumor","听说"+owner->query("name")+"需拜访的贤士被"HIR+target->name()+HIM"杀害了！"NOR);
		target->add("kill/player_npc",1);
	}
	else	
	{
		CHANNEL_D->do_channel(this_object(),"rumor","听说"+owner->query("name")+"将其需拜访的贤士杀害了！"NOR);	
		target->add("kill/player_npc",2);
	}
	
	if( target->query("kill/player_npc")>=5 )
	{
		message_vision("$N死了。\n",this_object());
		target->add("赌场/钱",1500000);
		tell_object(target,HIR"你杀害了过多的贤士，遭到了官府的通缉！\n"NOR);
		message_vision("\n但见一旁杀出一干六扇门高手，将$N团团围住！\n",target);
		name = ({"赵","钱","孙","李",})[random(4)] + ({"铁","慕","啸",})[random(3)]+({"衣","霜","天",})[random(3)];
		target->set_temp("block_msg/all",1); 
		message_vision(name+"对着$N喝道：「"+RANK_D->query_rude(target)+"！今日不是你死就是我活！」\n"target);
		tell_object(target,HIR"看起来"+name+"想杀死你！\n"NOR);
		message_vision(CYN+name+CYN"注视着$N的行动，企图寻找机会出手。\n",target);
		message_vision(name+"身形忽高忽低，双掌如刀，掌缘带起阵阵寒意，向$N周身不断的砍去！\n",target);
		message_vision("结果只听见「砰」地一声巨响，$N像一捆稻草般飞了出去！\n",target);
		message_vision("( $N"RED"已经陷入半昏迷状态，随时都可能摔倒晕去。"NOR" )\n",target);
		message_vision("\n\n$N受伤过重，脚下一个不稳，瘫倒在地，动弹不得。\n",target);
		message_vision("\n众衙役将$N捆绑个结结实实，押往大牢去也。\n",target);
		target->move("/d/city/dalao",1);
		target->set("startroom","/d/city/dalao");
		message_vision("到了，官差将$N往牢了一丢，转身离去。\n",target); 
		destruct(this_object());
		return;
	}
	::die();
}

void unconcious()
{
	die();
}

		





		

			
