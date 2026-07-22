// honglingbo.c 洪凌波
// By Kayin @ CuteRabbit Studio 99-3-29 11:48 new 
inherit BHNPC;
inherit F_MASTER;
#include <ansi.h>
int do_look(string target);
string ask_zhen();
void create()
{
	set_name("洪凌波", ({ "hong ling bo", "hong" }));
	set("long",
		"她肤色白润 ，双颊晕红，两眼水汪汪的。让人看了还想看。\n");
	set("gender", "女性");
	set("age", 17);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("per",27);
	set("str", 26);
	set("dex", 35);
	set("con", 17);
	set("int", 25);

	set("shen",-5000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);

	set("combat_exp", 1000000);
	set("score", 8500);	
	
	set_skill("force",150);
	set_skill("yunu-xinfa",150);
	set_skill("literate",100);
	set_skill("meinu-quanfa",100);
	set_skill("wudu-shenzhang",100);
	set_skill("swsb-shou",100);
	set_skill("unarmed",100);
	set_skill("dodge",100);
	set_skill("whip",300);
	set_skill("xianyun-bufa",400);
	set_skill("throwing",400);
	set_skill("parry",300);

	map_skill("force","yunu-xinfa");
	map_skill("unarmed","wudu-shenzhang");
	map_skill("dodge","xianyun-bufa");
	map_skill("parry","swsb-shou");
	map_skill("whip","swsb-shou");
        set("inquiry", ([
	    "李莫愁":"那是我师傅，不该问的别问，小心我宰了你。",	
	    "林朝英" : "那是我的师祖，不该你问的你别问，小心我宰了你。",

	]));
	
	create_family("古墓派", 4, "弟子");
	setup();
        carry_object("/clone/weapon/changjian")->wield();
           carry_object("/d/city/obj/cloth")->wear();

}
void attempt_apprentice(object ob)
{
        mapping myfam;
	if ((int)ob->query("shen") > 100) {
		command("say " + RANK_D->query_respect(ob) +
			"做事不够狠毒，我不能收你.");
		return;
	}
	if( (string)ob->query("gender") != "女性" )
	{
		command ("say 对不起，本派只收女弟子，你还是另投师们吧。");
		return;
	}
	if( (int)ob->query_dex()< 20){
		command("say 你的身法太差，不适合学古墓派的武功.");
		return;
	}
	if( (int)ob->query_int() < 25){
		command("say 你的悟性太差，不适合学古墓派的武功。");
		return;
	}
	if( (int)ob->query_int()< 20){
		command("say 你长的太丑了。");
		return;
	}
			
        	command("say 好吧，我就收下你了。");
		command("recruit " + ob->query("id"));
		if( (string)ob->query("class") != "taoist")
		ob->set("class", "taoist");
}
