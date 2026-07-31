//change.c
inherit SUPER_NPC;
#include <ansi.h>

string do_huimeng();
string do_shiyue();
string do_diezhang();

void create()
{
	set_name("嫦娥", ({"chang e", "change", "chang","master"}));
	set("long",
"广寒宫之主。早年因帮助丈夫盗取西王母之灵药而与其师势成水火。后得和解并邀西王母坐镇月宫一门。\n");
	set_level(120);
	set("gender", "女性");
	set("age", 20);
	set("class", "xian");
	set("attitude", "friendly");
	set("rank_info/respect", "仙姑");
	set("per", 300);
	set("force_factor",0);
	set("mana_factor", 240);
 	set("eff_dx", 200000);
	set_skill("literate", 1200);
	set_skill("unarmed", 1200);
	set_skill("dodge", 1200);
	set_skill("force",1200);
	set_skill("parry",1200);
	set_skill("sword",1200);
	set_skill("spells",1200);
 	set_skill("moonshentong",1200);
 	set_skill("baihua-zhang",1200);
 	set_skill("moonforce",1200);
 	set_skill("snowsword",1200);
 	set_skill("moondance", 1200);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");
	create_family("月宫", 2, "弟子");
	set_skill("jiefeng",1200);
	set_skill("jianshu",1200);
	set_skill("zuohuo",1200);
	set("title", HIW"广寒宫主人"NOR);
	set("inquiry", ([
		"回梦咒" : (: do_huimeng :),
		"蚀月咒" : (: do_shiyue :),
		"叠掌"	 : (: do_diezhang :),
	]));
	set("env/test","HIM");
	setup();
        carry_object(0,"cloth",1)->wear();
        carry_object(0,"sword",1)->wield();
        carry_object(0,"shoes",1)->wear();
        carry_object(0,"pifeng",1)->wear();
        carry_object(0,"neck",1)->wear();
        carry_object(0,"ring",1)->wear();
        powerup(0,1);
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
		EMOTE_D->do_emote(this_object(), "kick",geteuid(ob),CYN,0,0,0);
           	tell_object(ob,CYN+name()+CYN"说道：我们月宫不收妖魔鬼怪，你还是另请高就吧。\n"NOR);
           	return ;
        }
	if( ob->query_level()<75 )
        {
        	EMOTE_D->do_emote(this_object(), "addoil",geteuid(ob),CYN,0,0,0);
           	tell_object(ob,CYN+name()+CYN"说道：这位"+RANK_D->query_respect(ob)+"还是先找月奴妹纸先打好基础。\n"NOR);
           	return ;
        }
        if( ob->query_level()>125 )
        {
        	EMOTE_D->do_emote(this_object(), "hmm",geteuid(ob),CYN,0,0,0);
           	tell_object(ob,CYN+name()+CYN"说道：这位"+RANK_D->query_respect(ob)+"说笑了，"+RANK_D->query_self_close(this_object())+"何德何能？\n"NOR);
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
        	EMOTE_D->do_emote(this_object(), "heng",geteuid(ob),CYN,0,0,0);
           	tell_object(ob,CYN+name()+CYN"说道：这位" +RANK_D->query_respect(ob) + "既然已被痴梦妹纸看中，呵呵，我这里恐怕容不下你这尊大佛，呵呵。\n"NOR);
           	EMOTE_D->do_emote(this_object(), "bite",0,CYN,0,0,0);
        	return;
	}
	EMOTE_D->do_emote(this_object(), "addoil",geteuid(ob),CYN,0,0,0);
	tell_object(ob,CYN+name()+CYN"说道：好，希望" + RANK_D->query_respect(ob) +"多加努力，把我们月宫发扬光大。\n"NOR);
        command("recruit " + geteuid(ob) );
        return;
}

void recruit_apprentice(object ob)
{
	 if( ::recruit_apprentice(ob) )
	 {
	 	ob->set("class", "xian");
	 	if( !ob->is_titles("嫦娥亲传弟子") )
	 	{
	 		if( ob->set_titles("嫦娥亲传弟子") )
	 			tell_object(ob,HIC"【系统】你获得了称号：「"HIM"嫦娥亲传弟子"NOR HIC"」。\n"NOR);
	 	}
		if( ob->is_titles("痴梦仙姑亲传弟子") )
		{
			if( ob->remove_title("痴梦仙姑亲传弟子",1) )
				tell_object(ob,HIC"【系统】你失去了称号：「"HIG"痴梦仙姑亲传弟子"NOR HIC"」。\n"NOR);
		}
		if( ob->is_knowing("moon_chimeng")>1 )
		{
			if( ob->set_knowing("moon_chimeng",1) )
				tell_object(ob,HIC"【师门】你失去了痴梦仙姑的好感。\n"NOR);
		}
		ob->save();
	 }
}

string do_huimeng()
{
	object me = this_player();
	if( me->query("family/family_name")!="月宫" )
		return 0;
	if( base_name(environment())!="/d/moon/change_room" )
		return "此事还是待我回宫后再说。";
	if( me->is_knowing("moon_huimeng") )
		return "不是已经教过你了吗？";	
	if( time()<me->query("mark/last_huimeng_ask")+300 )
		return "你不是刚刚问过吗？还是歇会再来吧。";	
	if( this_object()->is_busy() )
		return "我现在正忙，你待会儿再来。";
	if( (time()-me->query("last_sleep"))<90 )
		return "你刚刚睡醒，不能体味回梦的真谛。";
	if( me->query_level()<45 )
		return "你的人物等级不够。";
	if( (int)me->query_skill("moonshentong",1) < 350 )
		return "你的月宫仙法等级过低。";
	if( !me->query_temp("moon_huimeng_asked") )
	{
		me->set_temp("moon_huimeng_asked",1);
		return "想要体味回梦真谛，需得入梦，你可愿意(agree)？";
	}
	return "想要体味回梦真谛，需得入梦，你可愿意(agree)？";
}

void init()
{
	add_action("do_agree","agree");
	add_action("do_get","get");
}

int do_get(string arg)
{
	object hua,me = this_player();
	if( !arg )
		return 0;
	if( base_name(environment())!="/d/moon/change_room" )
		return 0;
	hua = present(arg,environment());	
	if( hua && base_name(hua)=="/d/obj/flower/juhua" )
		return err_msg(name()+"朝你摇了摇头。\n");
	return 0;
}	

int do_agree()
{
	object me = this_player();
	string msg;
	int success, ap, dp, howlong;
	int dayphase;
	
	if( me->query("family/family_name")!="月宫" 
	 || !me->query_temp("moon_huimeng_asked") 
	 || !this_object()->visible(me) )
		return 0;
	if( base_name(environment())!="/d/moon/change_room" )
		return 0;
	if( me->is_knowing("moon_huimeng") )
		return err_msg(CYN+name()+CYN"说道：不是已经教过你了吗？\n"NOR);	
	if( time()<me->query("mark/last_huimeng_ask")+300 )
		return err_msg(CYN+name()+CYN"说道：你不是刚刚问过吗？还是歇会再来吧。\n"NOR);	
	if( this_object()->is_busy() || this_object()->is_fighting() )
		return err_msg(CYN+name()+CYN"说道：我现在正忙，你待会儿再来。\n"NOR);
	if( me->is_busy() || me->is_fighting() )
		return err_msg("你现在正忙着呢。\n");
	if( (time()-me->query("last_sleep"))<90 )
		return err_msg(CYN+name()+CYN"说道：你刚刚睡醒，不能体味回梦的真谛。\n"NOR);

	me->delete_temp("moon_huimeng_asked");
	write("你想让"+name()+"告知「回梦咒」的真谛。\n");
	EMOTE_D->do_emote(this_object(), "nod",geteuid(me),CYN,0,0,0);

	this_object()->start_busy(3);
	CHANNEL_D->do_channel(this_object(),"chat","我派弟子"+me->name()+HIC"开始领悟我广寒咒法「"HIY"回梦咒"HIC"」。"NOR);
	msg = HIM"$N"HIM"凝视着$n"HIM"的双眼，温柔地拍着$n的头，在$n耳边轻声唱着：“小宝宝，快睡觉。。。”$n"HIM"顿时觉得神倦眼困，全身无力。\n"NOR;
	dayphase =NATURE_D->query_current_day_phase();
	if (dayphase < 6)
		success = 2;
	else	success = 4;	
	ap = this_object()->query_level();
	dp = me->query_level();
	if( random(ap+dp)>=dp )
		success+= 3;
	else	success-= 1;	
	ap = this_object()->query_skill("spells");
	dp = me->query_skill("spells");
	if( random(ap+dp)>=dp )
		success+= 3;
	else	success-= 1;	
	ap = this_object()->query("mana");
	dp = me->query("mana");
	if( random(ap+dp)>=dp )
		success+= 3;
	else	success-= 1;	
	ap = this_object()->query_per();
	dp = me->query_cps();
	if( random(ap+dp)>=dp )
		success+= 3;
	else	success-= 1;	
	ap = this_object()->query("daoxing");
	dp = me->query("daoxing");
	if( random(ap+dp)>=dp )
		success+= 3;
	else	success-= 1;	
	if( random(success)>0 )
	{
		msg +=  HIM"$n"HIM"不知不觉的哈欠连连，眼皮沉重，终于支持不住，合上了双眼。\n"NOR;
            	message_vision(msg, this_object(), me);
		me->set_temp("force_sleep",1);
		me->delete_temp("last_sleep");
		if(!me->command("sleep")) 
		{
			message_vision(HIM"\n$N晃了晃脑袋，似乎清醒了不少，又把眼睛睁开了。\n"NOR,me);
	            	command("chat* sigh"+geteuid(me));
        	    	me->set("mark/last_huimeng_ask",time());
            		this_object()->start_busy(1);
            		return err_msg(CYN+name()+CYN"说道：你都无心睡眠，如何能领悟回梦的奥妙？\n"NOR);
		}
		this_object()->start_busy(3);	
		me->delete_temp("force_sleep");
		me->set_temp("last_sleep",time());
		remove_call_out("check");
		call_out("check",1,me);
	}	    
	else 
	{
		msg +=HIM"$n忽觉不妥，大喝一声，双目一张，精光四射！$N猝不及防，吓了一跳！\n" NOR;	
            	message_vision(msg, this_object(), me);
            	command("chat* sigh"+geteuid(me));
            	me->set("mark/last_huimeng_ask",time());
            	this_object()->start_busy(1);
            	return err_msg(CYN+name()+CYN"说道：你都无心睡眠，如何能领悟回梦的奥妙？\n"NOR);
	} 
	return 1;
}	
	
void check(object who)
{
	if( !who )
		return;
	if( base_name(environment())!="/d/moon/change_room" 
	 || !present(who,environment()) )
	{
		remove_call_out("check");
		command("chat* sigh"+geteuid(who));
            	who->set("mark/last_huimeng_ask",time());
            	this_object()->start_busy(1);
		tell_object(who,CYN+name()+CYN"说道：可惜可惜，你一觉睡去了其他地方。\n"NOR);
		return;
	}
	if( who->query_temp("block_msg/all") )
	{
		message_vision(HIY"\n$N"HIY"甜蜜的睡着，嘴角流着幸福的哈喇子，也不知是梦到了什么。\n\n"NOR,who);
		remove_call_out("check");
		call_out("check",1+1,who);
		return;	
	}	
	if( random( (who->query_kar()+who->query_per())/10 )>4 )
	{
		remove_call_out("check");
		this_object()->start_busy(1);
		write(HIY"【师门】恭喜！你成功领悟了「"HIR"回梦咒"HIY"」的使用。\n"NOR);
		who->set_knowing("moon_huimeng",1);
		who->save(1);
		CHANNEL_D->do_channel(this_object(),"chat","本派弟子"HIY+who->name(1)+HIC"福至心灵，成功领悟到了「"HIY"回梦咒"HIC"」的奥妙。"NOR);
		EMOTE_D->do_emote(this_object(), "great",geteuid(who),CYN,0,0,0);		
	}
	else
	{
		remove_call_out("check");
		this_object()->start_busy(1);
		write(HIY"【师门】你领悟「"HIR"回梦咒"HIY"」失败。\n"NOR);
		who->set("mark/last_huimeng_ask",time());
		who->save(1);
		EMOTE_D->do_emote(this_object(), "sigh",geteuid(who),CYN,0,0,0);		
	}
}

string do_shiyue()
{
	object book,me = this_player();
	if( me->query_level()<25 || me->is_knowing("moon_shiyue") )
		return 0;
	if( me->query("family/family_name")!="月宫" )
		return 0;
	if( time()<me->query("family/last_shiyue_give")+1800 )
		return "你刚刚不是来拿过领悟心得了吗？";	
	if( time()<me->query("family/last_shiyue_fail")+2700 )
		return "你刚刚领悟失败了，还是下去修行修行。";
	book = new("/d/moon/obj/shiyue_book");
	book->set("owner_id",me->query("id"));
	EMOTE_D->do_emote(this_object(), "nod",geteuid(me),CYN,0,0,0);
	if( book->move(me) )
	{
		message_vision("$N将一本"+book->name()+"交给$n。\n",this_object(),me);
		me->set("family/last_shiyue_give",time());
	}
	else	destruct(book);
	return "加油加油。";
}	

string do_diezhang()
{
	return "圆月之夜，潮汐之力最为猛烈。叠掌就是以层层劲力相叠，其中奥妙也只有使用此招者才能领悟。";
}

int prevent_learn(object me, string skill)
{
	object ob = me;	
	if( me->is_knowing("moon_chimeng")==2 )
	{
		EMOTE_D->do_emote(this_object(), "heng",geteuid(me),CYN,0,0,0);
		tell_object(ob,CYN+name()+CYN"说道：你既然与痴梦师妹有缘，就别来找我！！\n"NOR);
		return 1;
	}
	if( skill=="jianshu" )
	{
		if( me->query_skill("mengtou",2)>1 )
		{
			tell_object(ob,CYN+name()+CYN"说道：呵呵，你既然从痴梦师妹那学了鞭法精髓，我就不教你剑术了。\n"NOR);
			return 1;
		}
	} 
	return 0;		
}