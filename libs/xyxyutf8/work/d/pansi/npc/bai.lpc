//niang.c/2001 by lestat
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
// int accept_object(object me, object ob);
void create()
{
	set_name(HIC"白晶晶"NOR, ({"bai jingjing", "bai", "jingjing","master"}));
	set("long",
"盘丝大仙座下的二弟子白骨精,随盘丝大仙修成正果,因孙悟空盗取盘丝洞至宝月光宝合而与其师姐春
十三娘势成水火。她一生爱穿白衣，当真如风拂玉树，雪裹琼苞，兼之生性清冷，实当得起“冷浸溶
溶月”的形容。\n");
	set_level(89);
	set("title", HIW"白骨洞主"NOR);
	set("gender", "女性");
	set("age", 22);
	set("class", "yaomo");
	set("attitude", "friendly");
	set("force_factor",890);
	set("mana_factor",890);
 	set("eff_dx", 200000);
 	set("nkgain", 350);

	set_skill("literate",890);
	set_skill("unarmed",890);
	set_skill("dodge",890);
	set_skill("force",890);
	set_skill("parry",890);
	set_skill("spells",890);
	set_skill("pansi-dafa",890);
	set_skill("lanhua-shou",890);
	set_skill("jiuyin-xinjing",890);
	set_skill("chixin-jian",890);
	set_skill("yueying-wubu",890);
	map_skill("spells", "pansi-dafa");
	map_skill("unarmed", "lanhua-shou");
	map_skill("force", "jiuyin-xinjing");
	map_skill("sword", "chixin-jian");
	map_skill("parry", "chixin-jian");
	map_skill("dodge", "yueying-wubu");
	set("chat_chance",50);
	set("chat_msg", ({
        	HIG"白晶晶轻声告诉你:十八岁那年他说过会来娶我，我等了他三年……原来一切都是骗我的！\n"NOR,
        	HIG"白晶晶轻声告诉你:我遇上一个人，送给我一坛酒，他说那叫醉生梦死，喝了之后，可以叫你忘掉以做过的任何事。\n"HIC,
        	HIG"白晶晶轻声告诉你:那天我跟他在月亮下喝酒，他对我说，如果我有个妹妹，他一定娶她为妻。他明知我是女子，为什么要这样说！\n"NOR,
		HIG"白晶晶轻声告诉你:不知道是巧合还是其他原因，以前每次他来盘丝洞的时候，天都会下雨！\n"NOR,
		HIG"白晶晶轻声告诉你:他本来就不属于这个世界，他是一个逃下天界的神仙。听说逃下天界的神仙命运往往是不幸的，尤其是动了凡心的那种。神仙是不该有感情的，这可能也是命运！\n"NOR,
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
        carry_object(0,"whip",1)->wield();
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
	 && (string)ob->is_knowing("pansi_apprentice")=="niang" )
	{
		EMOTE_D->do_emote(this_object(), "pei",geteuid(ob),CYN,0,0,0);
        	tell_object(ob,CYN+name()+CYN"说道：是不是春十三娘那个贱人差你来探老娘口风的？！"NOR"\n");
        	return;
        }
	command("say 好！" + RANK_D->query_respect(ob) + "投入我的门下，他日必有所成！\n");
	command("recruit " + ob->query("id") );
	return ;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	{
	 	ob->set("class","yaomo");
	 	if( !ob->is_knowing("pansi_apprentice") ) 
	 		ob->set_knowing("pansi_apprentice","bai");
	}
}

int accept_object(object me, object ob)
{
    
    if(ob->query("name") == "[1;32m醉生梦死[2;37;0m" && ob->query("realzui"))
    {
        command("say 啊,醉生梦死，居然只是一坛清水罢了！\n");
    
	command("say 这就是醉生梦死?谢谢你,终于可以忘掉那个臭猴子了。");
	command("jump");
    	me->set_temp("marks/zui",1);
	return 1;}
	return 0;
}

