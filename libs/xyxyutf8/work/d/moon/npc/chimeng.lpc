// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
//change.c
inherit SUPER_NPC;
#include <ansi.h>

string ask_sanshou();

void create()
{
   	set_name("痴梦仙姑",({"chi meng","dream", "fairy"}));
   	set("long","此乃迷津痴梦仙姑也；不受金银之谢，但遇有缘者渡之！\n");
   	create_family("月宫", 2, "弟子");
   	set("title", HIM"迷津渡者"NOR);
   	set("gender", "女性");
   	set("age", 18);
   	set("class", "xian");
   	set("attitude", "friendly");
   	set("rank_info/respect", "仙姑");
   	set("force_factor", 150);
   	set("mana_factor", 240);
    	set("eff_dx", 100000);
    	set("nkgain", 300);
	set_level(115);
   	set_skill("literate",1150);
   	set_skill("parry", 1150);
   	set_skill("unarmed",1150);
   	set_skill("dodge", 1150);
   	set_skill("force", 1150);
   	set_skill("whip", 1150);
   	set_skill("unarmed", 1150);
   	set_skill("spells", 1150);
   	set_skill("baihua-zhang", 1150);
    	set_skill("moonshentong",1150);
    	set_skill("jueqingbian", 1150);
    	set_skill("moonforce", 1150);
    	set_skill("moondance", 1150);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("whip", "jueqingbian");
        map_skill("parry", "jueqingbian");
        map_skill("dodge", "moondance");
        set_skill("jiefeng",1150);
        set_skill("zuohuo",1150);
        set_skill("mengtou",1150);
    	set("inquiry",([
      		"三无三不手": (: ask_sanshou :),
      	]));
	set("env/test","HIB");
	setup();
	set("env/test","HIM");
	setup();
        carry_object(0,"cloth",1)->wear();
        carry_object(0,"whip",1)->wield();
        carry_object(0,"shoes",1)->wear();
        carry_object(0,"pifeng",1)->wear();
        carry_object(0,"neck",1)->wear();
        carry_object(0,"ring",1)->wear();
        powerup(0,1);
}

string ask_sanshou()
{
	object me=this_player();
    	if(me->query("family/family_name") != "月宫" )
        	return ("你不是我月宫弟子。\n");
    	if(me->query("faith")<500)
       		return ("你对本门做了多少贡献，就想打听三无三不手！");
    	if( (string)me->query("gender") !="女性")
                return ("你非为纯阴之身,怎能知哓女儿家的心思。");
	if( me->query("first_sleep") )
		return "哼！你已非处子之身。";
    	if(me->query("family/master_id") != "chi meng")
		return ("你不是我的弟子，不传。\n");
	if( me->is_knowing("moon_chimeng")!=2 )
		return "你我无缘，还是不要多问。";
	if( query_temp("sanshou_doing") )
		return "等我空闲下来再告诉你。";
	EMOTE_D->do_emote(this_object(), "pat",geteuid(me),CYN,0,0,0);
	me->set_temp("pending/chimeng_ask",1);
    	return "我只掩饰一遍，能领悟几分，全看你的悟性，准备好了我们就开始(start)。";
}

void init()
{
	::init();
	add_action("do_start","start");
}

void finish_sanshou(object me)
{
	int p;
	remove_call_out("finish_sanshou");
	if( !me || !living(me) || !present(me,environment()) )
	{
		command("chat* sigh");
		delete_temp("sanshou_doing");
		return;
	}
	me->delete_temp("pending/chimeng_ask");
	p = 1;
	p+= random((100-me->query_kar())/20);
	p+= me->is_knowing("moon_sanshou");
	if( wizardp(me) )  write(p+"\n");
	if( random(p)!=0 )
	{
		tell_object(me,HIR"\n然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
		EMOTE_D->do_emote(this_object(), "sigh",geteuid(me),CYN,0,0,0);
		delete_temp("sanshou_doing");
		tell_object(me,HIR"你目前对三无三不手的领会度为"+me->is_knowing("moon_sanshou")+"。\n"NOR);
		return;
	}
	tell_object(me,HIR"\n你突然福至心灵，对绝情鞭的三无三不手一式的领悟有了更深的理解！\n"NOR);
	EMOTE_D->do_emote(this_object(), "gongxi",geteuid(me),CYN,0,0,0);
	delete_temp("sanshou_doing");
	me->set_knowing("moon_sanshou",1);
	tell_object(me,HIR"你目前对三无三不手的领会度为"+me->is_knowing("moon_sanshou")+"。\n"NOR);
	me->save();
	me->start_busy(1);
}

int do_start()
{
	string str;
	mapping action;
	object me = this_player();
    	if( me->query("family/family_name") != "月宫"
    	 || me->query("faith")<500
    	 || (string)me->query("gender") !="女性"
    	 || me->query("family/master_id") != "chi meng"
    	 || !me->query_temp("pending/chimeng_ask") )
		return 0;
	if( query_temp("sanshou_doing") )
		return err_msg("痴梦仙姑说道：稍微等等，我现在正忙。\n");
	if( !wizardp(me) && time()<me->query("family/chimeng_test")+900 )
		return err_msg("痴梦仙姑说道：你刚刚领悟过，等"+CHINESE_D->chtime(me->query("family/chimeng_test")+900-time())+"再来吧。\n");
	EMOTE_D->do_emote(this_object(), "nod",geteuid(me),CYN,0,0,0);
	set_temp("sanshou_doing",me->query("id"));
	me->set("family/chimeng_test",time());
	action = query("actions");
	if( !action || !mapp(action) || undefinedp(action["action"]) )
		str = "\n$N将绝情鞭三无三不手的奥妙演示了一遍。\n";
	else	str = "\n"+action["action"]+"。\n";
	set_temp("JQB_perform",1);
	action = query("actions");
	if( !action || !mapp(action) || undefinedp(action["action"]) )
		;
	else	str+= action["action"]+"。\n";
	set_temp("JQB_perform",2);
	action = query("actions");
	if( !action || !mapp(action) || undefinedp(action["action"]) )
		;
	else	str+= action["action"]+"。\n";
	set_temp("JQB_perform",3);
	action = query("actions");
	if( !action || !mapp(action) || undefinedp(action["action"]) )
		;
	else	str+= action["action"]+"。\n";
	delete_temp("JQB_perform");	
	if( !query_temp("weapon") )
		str = replace_string(str,"$w","长鞭");
	else	str = replace_string(str,"$w",query_temp("weapon")->name());
	str = replace_string(str,"$l","要害");
	str = replace_string(str,"$n","对手");
	message_vision(str,this_object());
	me->start_busy(5);
	tell_object(me,HIR"\n\n你看了一遍演示，盘膝坐下，沉静心神，细细揣摩方才的一招一式。。。。\n\n"NOR);
	call_out("finish_sanshou",5+random(5),me);
	return 1;
}

void attempt_apprentice(object ob)
{
        if( !((string)ob->query("gender")=="女性"))
        {
        	EMOTE_D->do_emote(this_object(), "shake",geteuid(ob),CYN,0,0,0);
        	tell_object(ob,CYN+name()+CYN"说道：我们月宫只收女徒，这位" +RANK_D->query_respect(ob) + "还是另请高就吧。\n"NOR);
		return;
        }
        if( ob->query("class")=="yaomo" || ob->query("class")=="ghost" )
        {
		EMOTE_D->do_emote(this_object(), "bite",geteuid(ob),CYN,0,0,0);
           	tell_object(ob,CYN+name()+CYN"说道：我们月宫不收妖魔鬼怪，你还是另请高就吧。\n"NOR);
           	return ;
        }
        if( ob->query_level()<20 )
        {
        	EMOTE_D->do_emote(this_object(), "addoil",geteuid(ob),CYN,0,0,0);
           	tell_object(ob,CYN+name()+CYN"说道：这位"+RANK_D->query_respect(ob)+"还是先找月奴妹纸先打好基础。\n"NOR);
           	return ;
        }
        if( ob->query("class") && ob->query("family/family_name")!="月宫" )
        {
        	if( !ob->query_temp("mark/moon_class") )
        	{
        		EMOTE_D->do_emote(this_object(), "wow",geteuid(ob),CYN,0,0,0);
        		tell_object(ob,CYN+name()+CYN"说道：以前并未见门内有"+RANK_D->query_respect(ob)+"，莫非你是散修出身？\n"NOR);
        		EMOTE_D->do_emote(this_object(), "hmm",geteuid(ob),CYN,0,0,0);
           		tell_object(ob,CYN+name()+CYN"说道：你乃带艺拜师，还是先去问问麻姑管家关于「拜师」一事吧。\n"NOR);
           		return ;
           	}	
        }
        if( ob->is_knowing("moon_chimeng")==2 )
        {
        	EMOTE_D->do_emote(this_object(), "pat",geteuid(ob),CYN,0,0,0);
           	tell_object(ob,CYN+name()+CYN"说道：既然" + RANK_D->query_respect(ob) +"与我有缘，我就收下你了。\n"NOR);
		command("recruit " + geteuid(ob) );
        	return ;
        }
	if( ob->is_knowing("moon_chimeng")==1 )
	{
		EMOTE_D->do_emote(this_object(), "shake",geteuid(ob),CYN,0,0,0);
           	tell_object(ob,CYN+name()+CYN"说道：你我无缘，还是另请高就吧。\n"NOR);
		ob->set_knowing("moon_chimeng",1);
		return ;
        }
        if( !ob->is_knowing("moon_chimeng") 
         && random(ob->query_kar())<10 )
	{
     		ob->set_knowing("moon_chimeng",1);
		EMOTE_D->do_emote(this_object(), "shake",geteuid(ob),CYN,0,0,0);
           	tell_object(ob,CYN+name()+CYN"说道：你我无缘，还是另请高就吧。\n"NOR);
		return ;
        }
        ob->set_knowing("moon_chimeng",2);
	EMOTE_D->do_emote(this_object(), "pat",geteuid(ob),CYN,0,0,0);
	
	if( ob->query_level()<75 )
	{
		create_family("月宫", 3, "弟子");
   		set("title", HIM"迷津渡者"NOR);
   		tell_object(ob,CYN+name()+CYN"说道：既然" + RANK_D->query_respect(ob) +"与我有缘，我就收你做个记名弟子吧。\n"NOR);
	}
	else
	{
		create_family("月宫", 2, "弟子");
   		set("title", HIM"迷津渡者"NOR);
   		tell_object(ob,CYN+name()+CYN"说道：既然" + RANK_D->query_respect(ob) +"与我有缘，我就收下你了。\n"NOR);
	}
        command("recruit " + geteuid(ob) );
        return ;

}

void recruit_apprentice(object ob)
{
	 if( ::recruit_apprentice(ob) )
	 {
	 	create_family("月宫", 2, "弟子");
   		set("title", HIM"迷津渡者"NOR);
	 	ob->set("class", "xian");
	 	if( ob->query_level()<75 && !ob->is_titles("痴梦仙姑亲传弟子") )
	 	{
	 		if( ob->set_titles("痴梦仙姑亲传弟子") )
			{
	 			tell_object(ob,HIC"【系统】你获得了称号：「"HIG"痴梦仙姑亲传弟子"NOR HIC"」。\n"NOR);
	 			ob->save();
	 		}
	 	}
		if( ob->is_titles("嫦娥亲传弟子") )
		{
			if( ob->remove_title("嫦娥亲传弟子",1) )
				tell_object(ob,HIC"【系统】你失去了称号：「"HIM"嫦娥亲传弟子"NOR HIC"」。\n"NOR);
		}	 	
	 }	
} 

void die()
{
	if( environment() )
		message_vision("\n$N脸色一变，勉力逼住伤势，念动月华真言，化作一道霞光直冲太阴而去！\n\n");
	destruct(this_object());
}

int prevent_learn(object me, string skill)
{
	object ob = me;	
	if( me->is_knowing("moon_chimeng")!=2 )
	{
		tell_object(ob,CYN+name()+CYN"说道：汝与吾无缘，无谓妄想。\n"NOR);
		return 1;
	}
	if( skill=="mengtou" )
	{
		if( me->query_skill("jianshu",2)>1 )
		{
			tell_object(ob,CYN+name()+CYN"说道：汝既已学得「剑术」神通，此鞭法精髓不可得也。\n"NOR);
			return 1;
		}
	}
	if( skill=="mengtou" || skill=="zuohuo" )
	{
		if( me->query_level()<75 )
		{
			tell_object(ob,CYN+name()+CYN"说道：你现在修为还不够。\n"NOR);
			return 1;
		}
	} 
	return 0;		
}