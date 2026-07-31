// last updated by Jingxue 12.5.2002
//snowtu 2007.05.01 加入对特殊NPC check时的描述
#include <combat.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
	object ob;
	int mana_cost,sen_cost;
	string msg,msg2;
	if(!arg) 
	{
		msg = RANK_D->dx_need();
		msg2= RANK_D->exp_need();
		msg = mix_str( msg, msg2,24);
		me->start_more(msg);
		return 1;
	}
	if((int)me->query_level()<40 )
        	return notify_fail("你的武学修为不够"+RANK_D->describe_exp(40)+"。\n");
        if((int)me->query("mana")<60) 
        	return notify_fail("你的法力不够，用不了地耳灵。\n");
	if((int)me->query("sen")<=50)
        	return notify_fail("你现在太累了，休息休息吧！\n");
	if(me->query_temp("last_check_time") && !wizardp(me) && (me->query_temp("last_check_time")+6)>time() )
		return notify_fail("等等,系统喘气中......\n");
		
	mana_cost=-(100-(int)me->query_skill("spells"))/4-40;
	mana_cost=mana_cost+10;
	if(mana_cost > -50) mana_cost=-50;
	me->add("mana", mana_cost);
	me->set_temp("last_check_time",time());        
	message_vision(HIY "$N"HIY"口中念了几句咒文，眼中突然精光一闪，大喝一声“顺风耳何在！”\n只听嘿嘿几声奸笑，不知从哪里钻出来一个肥头大耳的家伙，在$P耳边低声说了几句话。\n" NOR, me);
	ob = find_player(arg);
	if(!ob) 
        {
        	ob=present(arg,environment(this_player()));
        	if(ob && !living(ob)) 
        		ob=0;
        }
	if( !ob ) ob = find_living(arg);
	if(!ob || (ob->query("env/invisibility") && wizardp(ob) )
	 || ob->is_yinshen() )
        	return notify_fail("顺风耳告诉你：奇怪，找不到这个人．．．\n");
    
	if( msg=ob->query_check_msg() )
        	write(msg);
	else    
	{
        	write("顺风耳告诉你："+ob->name()+"的道行修为已达"+RANK_D->describe_dx((int)ob->query("daoxing"))+"的境界。\n");  
        	write("顺风耳告诉你："+ob->name()+"的武学经验已达"+RANK_D->describe_exp((int)ob->query_level())+"的境界。\n");
        	write("顺风耳告诉你："+ob->name()+"的法力修为已达"+RANK_D->describe_fali((int)ob->query("max_mana"))+"的境界。\n");  
        	write("顺风耳告诉你："+ob->name()+"的内力修为已有"+RANK_D->describe_neili((int)ob->query("max_force"))+"的火候。\n");    
        	write("顺风耳告诉你："+ob->name()+"的武功修为与你相比，"+RANK_D->gettof(me,ob)+NOR"。\n");  
		//write("顺风耳告诉你："+ob->query("name")+"的武功修为已达"+gettof(me,ob)+"的境界。\n");  
        }
        if( ob==me )
        	return 1;
	message_vision("$N忽然莫名其妙地哆嗦了一下。\n",ob); 
	msg="你急忙掐指一算，";
	if( COMBAT_D->check_level(me,ob)==1 || me->query_level()>ob->query_level()+5 )
        	msg+="原来是"+me->name()+"("+me->query("id")+")"+"正在打听你的道行。\n";
	else    msg+="心中却只是一片茫然。\n";
	tell_object(ob, msg);
	ob->reply_check(me);
	return 1;
}

int help(object me)
{
string desc_dx, desc_fali, desc_exp;

write(@HELP
指令格式 : check|cha [<某人>]
地耳灵: 打听别人现在的道行,武学,法力及武功级别。
HELP
    );
write(HIG"------------------------道行境界------------------------\n"NOR);
write(RANK_D->query_description(0));
write(HIG"\n\n------------------------武学境界------------------------\n"NOR);
write(RANK_D->query_description(1));
write(HIG"\n\n------------------------法力修为------------------------\n"NOR);
write(RANK_D->query_description(2));
write(HIG"\n\n------------------------武功修为------------------------\n"NOR);
write(RANK_D->query_description(3));
write("\n");
return 1;
}
