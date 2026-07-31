#pragma save_binary
// general.c

#include <ansi.h>

inherit NPC;


void create()
{
	set_name("ÑÏÍ¢Òó", ({ "master general","master","general" }) );
	set("title", "Õò¹ú´ó½«¾ü");
	set("nickname", YEL "Õò¹ú´ó½«¾ü" NOR);
	set("gender", "ÄÐÐÔ");
	set("age", 45);
	set("long",
        	"ÈÝ¹â»À·¢£¬×óÅåµ¶£¬ÓÒÅå½££¬Íþ·çÀïÀï£¬Æä¸ßÆß³ßÁù´ç£¬»¢±³\n"
        	"ÐÜÑü£¬ÄêÇáÊ±Í¬ºÍ´óÌìÐ°ÓÚÀ¼ÌìÎäÍ¬°ÝÒ»Ê¦£¬Îä¹¦\ÔìÒè²»ÔÚ´ó\n"
        	"ÌìÐ°Ö®ÏÂ£¬µ«Ö¾Ïò²»Í¬£¬ºó³ÉÁË¾©Ê¦Îä¹¦\µÚÒ»¡¢ÈËÈË³ÆÏÛµÄÕò\n"
        	"¹ú´ó½«¾ü¡£\n");

	set("attitude", "peaceful");

	set("str", 29);
	set("int", 28);

	set("inquiry",([
		"»ÆÊ¯°¯¿Ú" : "ÄãÑÛ¾¦ÍÑ´°°¡£¬ÕâÀï¾ÍÊÇ»ÆÊ¯°¯¿Ú¡£\n",
		"ºó±¸±ø" : "ÎÒ²»¹ÜÕâÖÖÊÂµÄ£¬Äã±ðÀ´·³ÎÒ¡£\n",
		"±øÆ÷¿â" : "ÄãÕÒËÀ°¡£¡ÎÊÕâÖÖÎÊÌâ£¬ÄãÏë¸ÉÂé°¡¡£\n",
		"Ó¡¼ø" : "ÄãÔõÃ´ÖªµÀµÄ£¿°ïÎÒÕÒÕÒ°É£¬ÕÒµ½ÁËÎÒËÍÄãÀñÎï¡£\n",
	]) );
	set("neili", 51800);
	set("max_neili", 51800);
	set("force_factor", 20);
	set("max_jing", 31200);
	set("eff_jing", 31200);
	set("qi", 31200);
	set("max_qi", 31200);
	set("eff_sen", 200);
	set("sen", 200);
	
	set("qi", 28000);
	set("max_qi", 28000);
	set("jing", 28000);
	set("max_jing", 28000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 600000);
	set("shen", 200000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
//prepare_skill("hand", "paiyun-shou");
//prepare_skill("strike", "yitian-zhang");
set("count",1);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	//map_skill("dodge", "zhongyunti");
	
	
	setup();

	carry_object( __DIR__"obj/broken_sword")->wield();
//carry_object( __DIR__"obj/broken_sword")->wield();
	carry_object( __DIR__"obj/cloud_armor")->wear();

}

int accept_object(object who,object ob)
{
	object obj;

	if ( (string)ob->name() == "[1;33mÓ¡¼ø[0m") {
		command("say ÕæÊÇÐ»Ð»ÄãÁË¡£");
		command("smile");
		command("say ÎªÁË´ðÐ»Äã£¬Õâ°Ñ¹Å½£ËÍÄã£¬µ±×ö±¨³ê°É¡£");
		obj=new(__DIR__"obj/old_sword");

		obj->move(who);
//		call_out( (: destruct :), 1, ob);
 		return 1;
 	}
 	
	if ( (string)ob->name() == "Ó¡¼ø" ) {
		command("say ÄãÄÃ¸øÎÒµÄÊÇÊ²Ã´¶«Î÷°¡!");
 		command("say ±ðÏëÄÃÕâÖÖ¶«Î÷À´Æ­ÎÒ");
		command("say ¸øÎÒ¹ö³öÈ¥");
 		who->set_temp("½«¾ü/kick", 1);
		//who->move(PATH);
		return 0;
	}
	
	if ( !ob->value() ) {
		command("say Ð»ÁË!!!");
		command("grin");
//		call_out( (: destruct :), 1, ob);
		return 1;
	}
	
	command("say °¡£¬ÕæÊÇÐ»Ð»ÄãÁË¡£");
	return 1;
}
void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;


if (who->query_temp("book941"))
{
		message_vision("$NÉíÉÏµôÏÂÒ»ÕÅÆß×åÃËÊé¡£$n°ÑÆß×åÃËÊéÄÃµ½ÁËÊÖÉÏ¡£\n",this_object(),who);
who->set_temp("book942",1);		
}
		
		
	::die();

}                        