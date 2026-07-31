inherit SUPER_NPC;
inherit F_MASTER;
#include <ansi.h>

string give_zui(object me);
void create()
{
       	set_name(HIY"春三十娘"NOR, ({"chun sanshiniang", "chun", "sanshiniang","niang"}));
       	set("long",
"盘丝大仙座下的大弟子。本是一只蜘蛛精,随盘丝大仙修成正果,因帮助孙悟空盗取盘丝洞至宝月光宝合而
与其师妹白晶晶势成水火。很多年之后,她有个绰号叫做桃花娘子。\n");
       	set("title", HIM"桃花娘子"NOR);
       	set("gender", "女性");
       	set("age", 25);
       	set_level(89);	
       	set("class", "yaomo");
       	set("attitude", "friendly");
       	set("force_factor", 50);
       	set("mana_factor", 890);
	set("eff_dx", 200000);
	set("nkgain", 350);

	set_skill("literate", 890);
	set_skill("unarmed", 890);
	set_skill("dodge", 890);
	set_skill("force", 890);
	set_skill("parry", 890);
	set_skill("sword", 890);
	set_skill("spells", 890);
	set_skill("pansi-dafa",890);
	set_skill("lanhua-shou",890);
	set_skill("jiuyin-xinjing", 890);
	set_skill("qingxia-jian",890);
	set_skill("chixin-jian",890);
	set_skill("yueying-wubu", 890);
       	map_skill("spells", "pansi-dafa");
       	map_skill("unarmed", "lanhua-shou");
       	map_skill("force", "jiuyin-xinjing");
       	map_skill("sword", "qingxia-jian");
       	map_skill("parry", "qingxia-jian");
       	map_skill("dodge", "yueying-wubu");
   	set("inquiry", ([
		"醉生梦死" : (: give_zui :),
	]));
   	set("chat_chance",50);
    	set("chat_msg", ({
        	HIG"春三十娘轻声告诉你:桃花过处，寸草不生！\n"NOR,
        	HIG"春三十娘轻声告诉你:我以为在这世界上有一种人是不会有忌妒心的,因为她太骄傲了。在我出道的时候,我认识一个人,他叫孙
悟空，他喜欢在东边出没，他后来有个绰号叫齐天大圣。我认识他的那年，盘丝洞的桃花开得很美。\n"HIC,
        	HIG"春三十娘轻声告诉你:我叫春三十娘,我的职业是替人解决麻烦,就是帮助别人杀人！\n"NOR,
                HIG"春三十娘轻声告诉你:自从离开盘丝洞之后，我去了这个沙漠。我很想知道沙漠这边有什么，走过来发现其实什么也没有，除了
沙漠还是沙漠。我于是开始了另一种生活。在这种生活中，只有仇恨，只有杀人和被杀！\n"NOR,
                HIG"春三十娘轻声告诉你:其实醉生梦死只不过是一坛清水，你越想知道自己是不是已经忘记的时候，你反而记得越清楚。\n"NOR,
                HIG"春三十娘轻声告诉你:那个人走的当天一直在下雨。每次下雨，我就会想起他，我一直不相信自己会想他。\n"NOR,
        }));
	create_family("盘丝洞", 2, "弟子");
	set("env/test","HIB");
        setup();
        carry_object(0,"cloth",1)->wear();
        carry_object(0,"shoes",1)->wear();
        carry_object(0,"neck",1)->wear();
        carry_object(0,"ring",1)->wear();
        carry_object(0,"kui",1)->wear();
        carry_object(0,"pifeng",1)->wear();
        carry_object(0,"sword",1)->wield();
}

void attempt_apprentice(object ob)
{
	if( ob->query("class") && ob->query("class")!="yaomo" )
        {
       		EMOTE_D->do_emote(this_object(), "?",geteuid(ob),CYN,0,0,0);
		return ;
        }
	if( ob->query_level()<69 )
	{
		tell_object(ob,CYN+name()+CYN"说道："+RANK_D->query_respect(ob) +"的道行不够高深，有些绝学秘法恐怕难以领悟。"NOR"\n");
   		return;
   	}
	if( ob->is_knowing("pansi_apprentice") 
	 && (string)ob->is_knowing("pansi_apprentice")=="bai" )
	{
		EMOTE_D->do_emote(this_object(), "pei",geteuid(ob),CYN,0,0,0);
        	tell_object(ob,CYN+name()+CYN"说道：是不是白晶晶那个贱人差你来探老娘口风的？！"NOR"\n");
        	return;
        }
        EMOTE_D->do_emote(this_object(), "pai",geteuid(ob),CYN,0,0,0);
        tell_object(ob,CYN+name()+CYN"说道：好，希望" + RANK_D->query_respect(ob) +"多加努力，把我们盘丝洞发扬光大。"NOR"\n");
	command("recruit " + ob->query("id") );
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	{
	 	ob->set("class","yaomo");
	 	if( !ob->is_knowing("pansi_apprentice") ) 
	 		ob->set_knowing("pansi_apprentice","niang");
	}
}

string give_zui(object me)
{
	me=this_player();
	if( time()<query("last_give")+480 )
		return "醉生梦死已经给人了，你下次早点来。";
	me->set_temp("need_zui", 1);
	return "醉生梦死只不过是坛清水,你真的想要吗?(yes)？\n";
}

void init()
{
	add_action("do_yes", "yes");
}

int do_yes(string arg)
{
	object me;

	me=this_player();
	
	if(me->query_temp("need_zui")) 
	{
		message_vision("$N答道：想要！\n\n", me);
		if( time()<query("last_give")+480 )
			message_vision("春三十娘说道：一坛清水罢了,怎么这么多人想要,我已经给了别人。\n", me);
		else					
		{
                        message_vision("春三十娘说道：好！那我给了你吧！\n", me);
			me->delete_temp("need_zui");
			carry_object("/d/pansi/obj/zui");
			command("give zui to " + me->query("id"));
			set("last_give", time());
		}
		return 1;
	}
	return 0;
}