//【蜀山剑派】dhxy-evil 2000.7.5
// Modified by vikee 2000.12.9
#include <ansi.h>
inherit SUPER_NPC;

string begin_go();

void create()
{
	set_name("剑圣", ({ "jian sheng", "sheng", "jiansheng" }));
	create_family2("蜀山派","天枢宫", 1, "掌门人");
        set("title","蜀山派第三代掌门");
        set("long","蜀山派现任掌门，主执天枢宫。满头白发的老人，两眼炯炯有神。\n");
        set("gender", "男性");
        set("age", 65);
        set("attitude", "peaceful");
        set("class","taoist");
        set_level(170);

        set_skill("spells",1700);
        set_skill("force", 1700);
        set_skill("dodge", 1700);
        set_skill("parry", 1700);
        set_skill("sword", 1700);
        set_skill("xianfeng-yunti", 1700);
        set_skill("zuixian-wangyue", 1700);
        set_skill("chuanyun-zhang", 1700);
        set_skill("literate", 1700);
        set_skill("unarmed", 1700);
	set_skill("yujianshu", 1700);
        set_skill("tianshi-fufa",1700);
        map_skill("spells", "tianshi-fufa");
        map_skill("dodge", "zuixian-wangyue");
        map_skill("force", "xianfeng-yunti");
        map_skill("parry", "yujianshu");
        map_skill("sword", "yujianshu");
        map_skill("unarmed", "chuanyun-zhang");
        set_skill("jianshu",1700);
        set_skill("zhili",1700);
        set_skill("tundao",1700);
	set("inquiry", ([
          	"灵台观礼"    : (: begin_go :),
        ]) );
        
        set("env/wimpy",10);
	set("force_factor", 250);
	set("mana_factor", 200);

	set("env/test","HIR");
	set_temp("weapon_level",100+random(50));
	set_temp("armor_level",100+random(50));    
        
        setup();
        carry_object(0,"pifeng",random(2))->wear();
        carry_object(0,"shoes",random(2))->wear();
        carry_object(0,"kui",random(2))->wear();
        carry_object(0,"sword",random(3))->wield();
        carry_object(0,"cloth",random(2))->wear();
        carry_object(0,"armor",random(2))->wear();
}

void go_back()
{
	remove_call_out("go_back");
	if( !environment() )
		return;
	if( base_name(environment())=="/d/shushan/dadian" )
		return;
	message_vision("\n"HIC"剑圣道：观礼事毕，老夫这就回去，老祖所议之事，容某考虑考虑。\n"NOR,this_object());
        message_vision(HIC"$N"HIC"口捻个口诀，扔出一把宝剑，$N飞驰而上，一招「御剑飞行」向远方飞去。。。。\n"NOR,this_object());
	delete_temp("no_return");
	this_object()->move("/d/shushan/dadian");
	message_vision(HIC"\n一道蓝光闪过,$N"HIC"从剑上跳了下来。 \n"NOR,this_object());			
}

string begin_go()
{
	int f;
	mapping job;
	object me,ob;
	me=this_player();
	ob=this_object();

	if( !me->query_temp("pendding/fc_visite")
    	 || me->is_knowing("puti_panlong") )
    		return 0;	
	if( base_name(environment())!="/d/shushan/dadian" )
    		return "此事待老夫回转蜀山后再说。";
        if( me->query_temp("pendding/fc_visite_shushan") )
        {	
		message_vision("\n"HIC"剑圣道：" + RANK_D->query_respect(me) + "，老夫即刻赴灵台之约！\n"NOR,me);
        	message_vision(HIC"$N"HIC"口捻个口诀，扔出一把宝剑，$N飞驰而上，一招「御剑飞行」向远方飞去。。。。\n"NOR,ob);
        	ob->set_temp("no_return",1);
    		ob->move("/d/lingtai/inside1");
    		message_vision(HIC"\n一道蓝光闪过,$N"HIC"从剑上跳了下来。 \n"NOR,ob);
		remove_call_out("go_back");
    		call_out("go_back",2700);
		return "老夫与老祖正好有事相商。";
	}
	job = me->query_xy_job();
	if( !job || !mapp(job) )
		f = 1;
	else if( undefinedp(job["门派任务"]) )
		f = 1;
	else
	{
		job = job["门派任务"];
		if( undefinedp(job["succ"]) )
			f =1;
		else if( random(job["succ"]/10+1)<50 )
			f = 1;
		else	f = 2;		
	}		
        if( f==1 )
		return "先去助你师门完成一些任务吧。";
	me->set_temp("pendding/fc_visite_shushan",1);
	me->add_temp("pendding/fc_visited",1);
	tell_object(me,HIY"【灵台观礼】你已成功邀请到"+chinese_number(me->query_temp("pendding/fc_visited"))+"位圣贤参加灵台观礼。\n"NOR);
	return "观礼之日还请" + RANK_D->query_respect(me) + "再来告知一声。";	
}

void _attempt_apprentice(object ob)
{
	if( !ob )
		return;
	if( ob->query_level()>=125 )
	{
		if( ob->query("shilian")!="shushan" )
		{
			EMOTE_D->do_emote(this_object(), "hmm",geteuid(ob),CYN,0,0,0);
			tell_object(ob,CYN+name()+CYN"说道：斩妖除魔之心不可懈，你去于我入那锁妖塔。"NOR"\n");
			return;
		}
		EMOTE_D->do_emote(this_object(), "nod",geteuid(ob),CYN,0,0,0);
		tell_object(ob,CYN+name()+CYN"说道：好，希望" + RANK_D->query_respect(ob) +"多加努力，把我们蜀山剑派发扬光大。\n"NOR);
        	command("recruit " + geteuid(ob) );
        	return;
	}	
	else
	{
		EMOTE_D->do_emote(this_object(), "pat",0,CYN,0,0,0);
		tell_object(ob,CYN+name()+CYN"说道：嗯，有志不在年高，你先去打好基础再来吧。\n"NOR);
		return;
	}
}

void attempt_apprentice(object ob)
{
	if( ob->query("class") )
	{
		if( ob->query("class")=="yaomo" )
		{
			EMOTE_D->do_emote(this_object(), "pei",geteuid(ob),CYN,0,0,0);
			tell_object(ob,CYN+name()+CYN"说道：兀那妖魔，也想窥那天道？！\n"NOR);
			this_object()->kill_ob(ob);
			return;
		}
		else if( ob->query("class")=="bonze" )
		{
			EMOTE_D->do_emote(this_object(), "shake",geteuid(ob),CYN,0,0,0);
			tell_object(ob,CYN+name()+CYN"说道：你我道不同。\n"NOR);
			return;
		}
	}	
	return _attempt_apprentice(ob);
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
		ob->set("class", "taoist");
		if( !ob->is_titles("剑圣传承") 
		 && ob->query("taoist/class")=="shushan" )
 		{
 			if( ob->set_titles("剑圣传承") )
	 		{
	 			tell_object(ob,HIC"【系统】你获得了称号：「"HIC"剑圣传承"NOR HIC"」。\n"NOR);
	 			ob->save();
	 		}	
	 	}
	 }
}