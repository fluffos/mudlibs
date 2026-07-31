//tomcat
//lishanmu.c 2001 by lestat
#include <ansi.h>
inherit SUPER_NPC;
inherit F_MASTER;

string begin_go();

void create()
{
	set_name(HIY"金灵圣母"NOR, ({"jinling shengmu", "jinling", "shengmu"}));
	set("long", "她就是通天教主座下得意门生：金灵圣母，在这里替紫霞仙子教教徒弟。\n");
	set("title", HIB"坎宫斗母正神"NOR);
	set("gender", "女性");
	set("age", 20);
	set_level(150);
	set("class","yaomo");
	set("attitude", "friendly");
	set("force_factor", 100);
	set("mana_factor", 150);

	set_skill("literate", 1500);
	set_skill("unarmed", 1500);
	set_skill("dodge", 1500);
	set_skill("force", 1500);
	set_skill("parry", 1500);
	set_skill("sword", 1500);
	set_skill("spells", 1500);
	set_skill("whip", 1500);
   	set_skill("pansi-dafa", 1500);
   	set_skill("lanhua-shou", 1500);
   	set_skill("jiuyin-xinjing", 1500);
   	set_skill("chixin-jian", 1500);
   	set_skill("qingxia-jian", 1500);
	set_skill("yueying-wubu", 1500);
   	set_skill("yinsuo-jinling", 1500);
   	map_skill("spells", "yaofa");
   	map_skill("unarmed", "lanhua-shou");
   	map_skill("force", "jiuyin-xinjing");
   	map_skill("sword", "chixin-jian");
   	map_skill("parry", "yinsuo-jinling");
   	map_skill("dodge", "yueying-wubu");
   	map_skill("whip", "yinsuo-jinling");
	create_family("盘丝洞", 1, "红");
	set("env/test","HIB");
	set_temp("weapon_level",60+random(60));
	set_temp("armor_level",60+random(60));
	set("inquiry", ([ 
		"灵台观礼" : (: begin_go :),
	]));	
	setup();
	carry_object(0,"cloth",1)->wear();
        carry_object(0,"whip",1)->wield();
        carry_object(0,"shoes",1)->wear();
        carry_object(0,"kui",1)->wear();
        carry_object(0,"ring",1)->wear();
        carry_object(0,"neck",1)->wear();
        powerup(0,1);
}

void attempt_apprentice(object ob)
{
	if( ob->query_level()<100 )
	{
   		tell_object(ob,CYN+name()+CYN"说道：" + RANK_D->query_respect(ob) +"的修为不够高深，有些绝学秘法恐怕难以领悟。\n"NOR);
   		return;
   	}
   	if( !ob->query("shilian") || ob->query("shilian")!="pansi" )
        {
        	EMOTE_D->do_emote(this_object(), "hehe",geteuid(ob),CYN,0,0,0);
        	tell_object(ob,CYN+name()+CYN"说道：先去过来本门的祖师试炼任务再说。\n"NOR);
        	return;
        } 
        EMOTE_D->do_emote(this_object(), "pat",geteuid(ob),CYN,0,0,0);
        tell_object(ob,CYN+name()+CYN"说道：好，希望" + RANK_D->query_respect(ob) +"多加努力，把我们盘丝洞发扬光大。\n"NOR);
       	command("recruit " + geteuid(ob) );
   	return;
}

int recruit_apprentice(object ob)
{
  	if( ::recruit_apprentice(ob) )
    		ob->set("class", "yaomo");
}

void go_back()
{
	remove_call_out("go_back");
	if( !environment() )
		return;
	if( base_name(environment())=="/d/pansi/hubian" )
		return;
	message_vision("\n"HIC"金灵圣母道：观礼事毕，老身这就回转金光洞，老祖所议之事，容老身考虑考虑。\n"NOR,this_object());
        message_vision(MAG"$N"MAG"把口一张，吐出一道七色神光，笼罩其身，但见霞光一闪,$P"MAG"化作一道彩虹消失的无影无踪……\n"NOR,this_object());
	delete_temp("no_return");
	this_object()->move("/d/pansi/hubian");
	message_vision(MAG"\n但见霞光万道，瑞彩千条，光婵灿烂，映目射眼，一道彩虹从天空划过，$N"MAG"随彩虹飘然而至…… \n"NOR,this_object());			
}

string begin_go()
{
	mapping temp;
	mixed *files,*obj;
	object room,gui,me,ob;
	int dx,wx,qn,i;
    	
    	me=this_player();
	ob=this_object();
	
	if( !me->query_temp("pendding/fc_visite")
    	 || me->is_knowing("puti_panlong") )
    		return 0;
    	if( base_name(environment())!="/d/pansi/hubian" )
    		return "此事待老身回金光洞再议。";
	if( me->query_temp("pendding/fc_visite_pansi") )
	{
        	message_vision("\n"HIC"金灵圣母道：" + RANK_D->query_respect(me) + "，老身即刻赴灵台之约！\n"NOR,me);
        	message_vision(MAG"$N"MAG"把口一张，吐出一道七色神光，笼罩其身，但见霞光一闪,$P"MAG"化作一道彩虹消失的无影无踪……\n"NOR,ob);
        	ob->set_temp("no_return",1);
    		ob->move("/d/lingtai/inside1");
    		message_vision(MAG"\n但见霞光万道，瑞彩千条，光婵灿烂，映目射眼，一道彩虹从天空划过，$N"MAG"随彩虹飘然而至…… \n"NOR,ob);
		remove_call_out("go_back");
    		call_out("go_back",2700);
		return "老身与老祖正好有事相商。";
	}
	if( !me->query_temp("pendding/fc_visite_pansikill") )
	{
		if( time()<me->query("family/guanli_pansi_fail")+3600 )
			return "唉，你我刚刚被那昭惠灵显王识破过，还是缓缓吧。";
		if( !me->query_temp("pendding/fc_pansiask") )
		{
			me->set_temp("pendding/fc_pansiask",1);
				return "
紫青二仙与那西方佛陀事端未了，近日老身算得二仙有场劫难，为此老身特在花果山顶摆下
偷天换日之法，届时还望"+RANK_D->query_respect(me)+"能助吾等一臂之力。
你先下去准备，好了我们便开始(start)。";
		}				
		return "准备好了吗？好了我们便开始(start)。";
	}
	me->set_temp("pendding/fc_visite_pansi",1);
	me->delete_temp("pendding/fc_visite_pansikill");
	me->delete_temp("pendding/fc_pansiask");
	me->delete_temp("pendding/fc_zixia");
	me->delete_temp("pendding/fc_qingxia");
	me->add_temp("pendding/fc_visited",1);
	CHANNEL_D->do_channel(this_object(),"chat",HIY+me->name()+HIC"助我解除「二仙劫难」,届时老身一定上灵台观礼！"NOR);
	if( !me->query("mark/guanli_pansi") )
	{
		dx = ((me->query("daoxing")/1000)/10+1)*1000;
		if( dx>=81000) 
			dx = 81000;
		wx = dx+random(dx);	
		qn = 10000;
		me->add("daoxing",dx);
		me->add("combat_exp",wx);
		me->add("potential",qn);
		tell_object(me,HIY"【灵台观礼】你得到了"+wx+"点武学经验、"+chinese_number(dx/1000)+"年道行以及"+qn+"点潜能的奖励！\n"NOR);
		me->set("mark/guanli_pansi",1);
	}	
	tell_object(me,HIY"【灵台观礼】你已成功邀请到"+chinese_number(me->query_temp("pendding/fc_visited"))+"位圣贤参加灵台观礼。\n"NOR);
	if( me->query("family/family_name")=="方寸山三星洞")
		return "观礼之日还请" + RANK_D->query_respect(me) + "再来告知一声。";
	else	return "多谢多谢。";	
}

void init()
{
	::init();
	add_action("do_start","start");
}

void create_npc(object npc,object me)
{
	mapping skill;
	string *skills;
	int i,level;
	if( !me || !living(me) || base_name(environment(me))!="/quest/family/pansi/hgs" )
		return;
	if( !npc || userp(npc) )
		return;	
	level = me->query_level();
	if( level<40 )
		level = 40;
	npc->set_level(level);
	level = (level*2/3+random(level/3))*10;
	skill = npc->query_skills();
	skills = keys(skill);
	for(i=0;i<sizeof(skills);i++)
		npc->set_skill(skills[i],level);
		
	npc->set_temp("weapon_level",level/2);
	npc->set_temp("armor_level",level/2);
	npc->set("env/test","HIB");
	if( npc->query("id")=="xiaotian quan" )
	{
		npc->setup();
		npc->powerup(0,1);
		return;
	}		
	if( npc->query("id")=="erlang zhenjun" )
	{
		npc->carry_object(0,"spear",1)->wield();
		npc->carry_object(0,"armor",1)->wear();
		npc->carry_object(0,"shield",1)->wear();
	}	
	else	npc->carry_object(0,"sword",1)->wield();
	npc->carry_object(0,"cloth",1)->wear();
	npc->carry_object(0,"kui",1)->wear();
	npc->carry_object(0,"shoes",1)->wear();
	npc->carry_object(0,"ring",1)->wear();
	npc->carry_object(0,"neck",1)->wear();
	npc->carry_object(0,"hand",1)->wear();
	npc->carry_object(0,"waist",1)->wear();
	npc->carry_object(0,"wrists",1)->wear();
	npc->setup();
	npc->powerup(0,1);
}

void start_room2(object me)
{
	object zixia,qingxia,erlang,dog;
	if( !me || !living(me) || base_name(environment(me))!="/quest/family/pansi/hgs" )
		return;
	erlang = new("/quest/family/pansi/yangjian");
	create_npc(erlang,me);
	erlang->move(environment(me));
	message_vision(HIY"\n\n金光一闪，一道人影从半空中落下！正是昭惠灵显王二郎真君杨戬！\n"NOR"$N哼哼笑道：二妖还不束手就擒，更待何时？！\n",erlang);
	erlang->set_temp("my_killer",me);
	
	zixia = me->query_temp("pendding/fc_zixia");
	if( zixia )
		zixia->set("my_killer",erlang);
	qingxia = me->query_temp("pendding/fc_qingxia");
	if( qingxia )
		qingxia->set("my_killer",erlang);
	dog = new("/quest/family/pansi/dog");
	create_npc(dog,me);	
	dog->move(environment(me));
	message_vision("\n\n$N将手一招，祭出了$n！\n",erlang,dog);
	erlang->set_temp("invoker",dog);
	erlang->kill_ob(zixia);
	dog->kill_ob(zixia);
	erlang->kill_ob(qingxia);
	dog->kill_ob(qingxia);
	
	zixia->kill_ob(erlang);
	zixia->kill_ob(dog);
	qingxia->kill_ob(erlang);
	qingxia->kill_ob(dog);
	
	tell_object(me,HIY"【灵台观礼】速速协助二仙子假身，千万别让二郎真君看破真伪。放胆攻击(kill)吧！\n"NOR);
}

void start_room(object me)
{
	object zixia,qingxia;
	if( !me || !living(me) || base_name(environment(me))!="/quest/family/pansi/hgs" )
		return;
	zixia = new("/quest/family/pansi/zixia");
	create_npc(zixia,me);
	zixia->move(environment(me));
	message_vision("\n\n半空中忽然落下一根枯草，就地一滚，顿时化作了$N！\n$N嘻嘻一笑，道：一切就绪，只待那昭惠灵显王到来。\n",zixia);
	me->set_temp("pendding/fc_zixia",zixia);
	zixia->set("owner",me);
	
	qingxia = new("/quest/family/pansi/qingxia");
	create_npc(qingxia,me);
	qingxia->move(environment(me));
	message_vision("\n\n半空中忽然落下一根枯草，就地一滚，顿时化作了$N！\n$N嘻嘻一笑，道：一切就绪，只待那昭惠灵显王到来。\n",qingxia);
	me->set_temp("pendding/fc_qingxia",qingxia);
	qingxia->set("owner",me);
	
	zixia->set("my_sister",qingxia);
	qingxia->set("my_sister",zixia);
	
	message_vision("\n\n顿时间，天空中乌云蔽日，电闪雷鸣。。。。\n\n",me);	
	call_out("start_room2",3+random(5),me);		
}

int do_start()
{
	object room,me = this_player();
	if( base_name(environment())!="/d/pansi/hubian" )
		return 0;
	if( !me->query_temp("pendding/fc_visite")
    	 || me->is_knowing("puti_panlong")
    	 || me->query_temp("pendding/fc_visite_pansi")
    	 || me->query_temp("pendding/fc_visite_pansikill")
    	 || !me->query_temp("pendding/fc_pansiask") )
		return 0;
	room = clone_object("/quest/family/pansi/hgs");
	if( !room )
		return err_msg("金灵圣母道：等等，再等等，时机还不成熟。\n");	
	REMOVE_D->add_room(room,1800);			
	me->delete_temp("pendding/fc_pansiask");
	message_vision("$N朝$n点了点头。\n",this_object(),me);
	room->set("owner",me);
	tell_object(me,CYN+name()+CYN"说道：我这就送你去。\n"NOR);
	tell_object(me,HIC+name()+HIC"念了几句咒语，一道旋风卷起你，朝着花果山高处飞去。\n\n"NOR);
	me->move(room,2);
	message_vision("\n\n到了，$N从半空落下云头。\n\n",me);
	call_out("start_room",1,me);
	return 1;
}
		    	 