// 秀才
// created by Zine 5 Sep 2010

inherit NPC;


int ask_knowledge();
void create()
{
	switch( random(1) ) 
	{case 0:
	set_name("卓秀才", ({ "zhuo xiucai","xiucai","zhuo"}) );
	set("title", "书到用时方恨少");
	set("gender", "男性" );
	set("long", "卓秀才来这里之前是朝廷的官员，朝廷精兵简政之后被开革了。\n");
	set("chat_chance", 20);
	set("chat_msg", ({
		"卓秀才道：我朝威武，和谐盛世啊！\n",
	}) );
	case 1:
	set_name("卓秀才", ({ "zhuo xiucai","xiucai","zhuo"}) );
	set("title", "书到用时方恨少");
	set("gender", "男性" );
	set("long", "卓秀才来这里之前是朝廷的官员，朝廷精兵简政之后被开革了。\n");
	set("chat_chance", 5);
	set("chat_msg", ({
		this_object()->query("name")+"道：我朝威武，和谐盛世啊！\n",
		this_object()->query("name")+"突然激动起来，脸色突显一片病态的潮红，激动地手舞足蹈，自言自\n语道：“吾大天朝全盛之世，威镇四海，名传八方，万国来朝！”\n",
		this_object()->query("name")+"神情严肃，皱着眉头好像在思考什么，忽然慎重的摇摇头，轻声的自\n语道：“天朝体制，断不可失！外夷衅端，断不可启。”\n",
	}) );
	}
    set("age", 45);
	set("str", 40);
	set("int", 40);
	set("dex", 40);
	set("kar", 40);       
	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 200);
	set("max_jing", 200);
	set("eff_jingli", 200);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("shen_type", 800);
    set("combat_exp", 1000000);
    set_skill("literate", 200);
	
	
       	set("inquiry", ([
        	"学问" : (: ask_knowledge :),
         	"知识" : (: ask_knowledge :),
         	

	]));
	
	setup();
	carry_object("/d/jinyang/obj/heibuxie")->wear();
    carry_object("/d/jinyang/obj/ybcloth")->wear();
}

int ask_knowledge()
{
	object ob=this_player();
	command("nomatch" +this_object()->query("id"));
	command("say 我可以很诚实的告诉你，我们晋阳城内，月色学问第一，我第二。\n");
	command("say 相信你也很同意我的观点吧？\n");
	command("sure " + ob->query("id"));
	return 1;
}

int recognize_apprentice(object ob)
{
     return 1;
}

#include "die.h"