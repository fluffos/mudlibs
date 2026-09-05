#include <ansi.h>
string ask_me();
inherit NPC;
void create()
{
set("title",RED"花侍"NOR);
set_name("阿牧",({"a mu","mu"}));
set("long","他是陆乘风的弟子，受命在此看管"GRN"含羞草"NOR".\n");
set("gender","男性");
set("age",30);
set("attitude","friendly");
set("count",1);
set("str",21);
set("int",20);
set("con",20);
set("dex",17);
set("max_qi",200);
set("max_jing",200);
set("neili",200);
set("max_neili",200);
set("combat_exp",3000);
set("score",1000);
set_skill("force",30);
set_skill("dodge",20);
set_skill("unarmed",20);
set_skill("parry",10);
set_temp("apply/attack",5);
set_temp("apply/defense",10);
set_temp("apply/damage",10);
set("chat_chance_combat",100);
set("inquiry",(["含羞草":(:ask_me:),]));
set("shen_type",1);set("score",200);setup();
set("chat_chance",8);
set("chat_msg",({"当年师兄王铁由于偷了"GRN"含羞草"NOR",被师傅逐出师门.\n"}));
//	({"昨晚上总管去我的厢房，把烟斗忘在了那儿.\n"}));
carry_object("/d/city/obj/cloth")->wear();
}
string ask_me()
{	
	object ob;
	ob=new(__DIR__"obj/hanxiucao");
	if ( this_object()->query("count") < 1 )
		return "你来晚了，含羞草已经给别人要走了。\n";
	if(this_player()->query_temp("been_get"))
		return "你有完没完?\n";
	else
		{
			ob->move(this_player());
			this_player()->set_temp("been_get",1);
			this_object()->set("count", 0);
			return ("好吧，我就给你一棵吧。\n");
		}
}
