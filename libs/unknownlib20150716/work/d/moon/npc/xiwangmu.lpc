// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit SUPER_NPC;
#include <ansi.h>

string begin_go();

void create()
{
   	set_name("西王母", ({"xi wangmu", "xi", "wangmu","master"}));
   	set("long", "西华至妙生伊川，穆王八骑访昆仑。\n");
   	create_family("月宫", 1, "红");
   	set("title", HIW"月宫祖师"NOR);
   	set("gender", "女性");
   	set("age", 40);
   	set("class","xian");
   	set("attitude", "friendly");
   	set("rank_info/respect", "老太太");
   	set("looking", "面色红润，满脸福态。");
   	set("force_factor", 125);
   	set("mana_factor", 100);
   	set_level(170);
   	set_skill("literate",1700);
   	set_skill("unarmed",1700);
   	set_skill("dodge",1700);
   	set_skill("force",1700);
   	set_skill("parry",1700);
   	set_skill("sword",1700);
   	set_skill("spells",1700);
   	set_skill("baihua-zhang",1700);
   	set_skill("moonforce",1700);
   	set_skill("snowsword",1700);
   	set_skill("moondance",1700);
    	set_skill("moonshentong",1700);
   	map_skill("spells", "moonshentong");
   	map_skill("unarmed", "baihua-zhang");
   	map_skill("force", "moonforce");
   	map_skill("sword", "snowsword");
   	map_skill("parry", "snowsword");
   	map_skill("dodge", "moondance");
   	set_skill("jiefeng",1700);
   	set_skill("huifeng-fanhuo",1700);
   	set_skill("zuohuo",1700);
   	set_skill("jianshu",1700);
   	set_skill("mengtou",1700);
   	set("inquiry", ([
   		"灵台观礼" : (: begin_go :),
	]));
	set("env/test","HIB");
	set_temp("weapon_level",60+random(60));
	set_temp("armor_level",60+random(60));
	setup();
        carry_object(0,"cloth",1)->wear();
        carry_object(0,"sword",1)->wield();
        carry_object(0,"shoes",1)->wear();
        carry_object(0,"kui",1)->wear();
        carry_object(0,"ring",1)->wear();
        carry_object(0,"neck",1)->wear();
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
	if( ob->query_level()<125 )
	{
   		tell_object(ob,CYN+name()+CYN"说道：" + RANK_D->query_respect(ob) +"的修为不够高深，有些绝学秘法恐怕难以领悟。\n"NOR);
   		return;
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
        if( !ob->query("shilian") || ob->query("shilian")!="moon" )
        {
        	EMOTE_D->do_emote(this_object(), "hehe",geteuid(ob),CYN,0,0,0);
        	tell_object(ob,CYN+name()+CYN"说道：先去过来本门的太阴大阵再说。\n"NOR);
        	return;
        } 
        EMOTE_D->do_emote(this_object(), "pat",geteuid(ob),CYN,0,0,0);
        tell_object(ob,CYN+name()+CYN"说道：好，希望" + RANK_D->query_respect(ob) +"多加努力，把我们月宫发扬光大。\n"NOR);
       	command("recruit " + geteuid(ob) );
   	return;
}

void recruit_apprentice(object ob)
{
	 if( ::recruit_apprentice(ob) )
	 {
	 	ob->set("class", "xian");
	 	if( !ob->is_titles("广寒宫传人") )
	 	{
	 		if( ob->set_titles("广寒宫传人") )
			{
	 			tell_object(ob,HIC"【系统】你获得了称号：「"HIW"广寒宫传人"NOR HIC"」。\n"NOR);
	 			tell_object(ob,HIY"【系统】你可以通过 "HIR"title 广寒宫传人"HIY" 命令来激活此称号。\n"NOR);
	 			ob->save();
	 		}
	 	}	 	
	 }	
}

int accept_fight(object me){return 0;}

void go_back()
{
	remove_call_out("go_back");
	if( !environment() )
		return;
	if( base_name(environment())=="/d/moon/wangmu_room" )
		return;
	message_vision("\n"HIC"西王母道：观礼事毕，老身这就回转广寒宫，老祖所议之事，容老身考虑考虑。\n"NOR,this_object());
        message_vision(HIM"$N"HIM"架起祥云，随着一阵花香，已消失在月光中……\n"NOR,this_object());
	delete_temp("no_return");
	this_object()->move("/d/moon/wangmu_room");
	message_vision(HIG"\n忽听得空中有一阵异香仙乐，飘飘而来,空中飘落一朵七彩祥云，$N"HIG"拨开云端走了出来……\n"NOR,this_object());			
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
    	if( base_name(environment())!="/d/moon/wangmu_room" )
    		return "此事待老身回广寒宫再议。";
	if( me->query_temp("pendding/fc_visite_moon") )
	{
        	message_vision("\n"HIC"西王母道：" + RANK_D->query_respect(me) + "，老身即刻赴灵台之约！\n"NOR,me);
        	message_vision(HIM"$N"HIM"架起祥云，随着一阵花香，已消失在月光中……\n"NOR,ob);
        	ob->set_temp("no_return",1);
    		ob->move("/d/lingtai/inside1");
    		message_vision(HIG"\n忽听得空中有一阵异香仙乐，飘飘而来,空中飘落一朵七彩祥云，$N"HIG"拨开云端走了出来……\n"NOR,ob);
		remove_call_out("go_back");
    		call_out("go_back",2700);
		return "老身与老祖正好有事相商。";
	}
	if( !me->query_temp("pendding/fc_visite_moonask") )
	{
		me->set_temp("pendding/fc_moonask",1);
		return "老身近日正为座下几位侍女纠纷搞得头疼，这些个小丫头\n为着近日由谁饲养青鸾而闹得不可开交，你去帮老身解决了此事罢。";
	}
	me->set_temp("pendding/fc_visite_moon",1);
	me->delete_temp("pendding/fc_visite_moonask");
	me->add_temp("pendding/fc_visited",1);
	CHANNEL_D->do_channel(this_object(),"chat",HIY+me->name()+HIC"助我平息「司女纠纷」,届时老身一定上灵台观礼！"NOR);
	if( !me->query("mark/guanli_moon") )
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
		me->set("mark/guanli_moon",1);
	}	
	tell_object(me,HIY"【灵台观礼】你已成功邀请到"+chinese_number(me->query_temp("pendding/fc_visited"))+"位圣贤参加灵台观礼。\n"NOR);
	if( me->query("family/family_name")=="方寸山三星洞")
		return "观礼之日还请" + RANK_D->query_respect(me) + "再来告知一声。";
	else	return "多谢多谢。";	
}

int prevent_learn(object me, string skill)
{
	object ob = me;	
  	if( skill != "jueqingbian")
  		return 0;
	if( me->is_knowing("moon_chimeng")!=2 )
	{
		tell_object(ob,CYN+name()+CYN"说道：汝与痴梦无缘，安得绝情鞭法？\n"NOR);
		return 1;
	} 
	return 0;		
}