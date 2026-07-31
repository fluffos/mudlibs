// /d/yixing/npc/zhan.c 展飞
// Last Modified by winder on Jul. 12 2002
#include <ansi.h>
inherit NPC;

int ask_me();

void create()
{
	set_name("展飞", ({ "zhan fei", "zhan" }));
	set("party/party_name", HIC"长乐帮"NOR);
	set("party/rank", "豹捷堂香主");
	set("long", "他是一个身披斑衣的汉子。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 25);
	set("con", 24);
	set("dex", 25);

	set("max_qi", 700);
	set("max_jing", 400);
	set("max_neili", 500);
	set("neili", 500);
	set("jiali", 30);
	set("combat_exp", 120000);
	set("score", 6000);

	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("parry", 90);
	set_skill("strike", 90);
/*
	set_skill("ding-force", 90);
	set_skill("wuxingbu", 90);
	set_skill("cuixin-zhang", 90);

	map_skill("force", "ding-force");
	map_skill("dodge", "wuxingbu");
	map_skill("strike", "cuixin-zhang");
	map_skill("parry", "cuixin-zhang");

	prepare_skill("strike", "cuixin-zhang");
*/
	set("inquiry", ([
		"长乐帮" : "我为长乐帮赴汤蹈火十几年竟落得这个下场。",
		"司徒横" : "这贼帮主凶淫毒辣，不知要想什么新镣古怪的花样来折磨我？",
		"帮主"   : "这贼帮主凶淫毒辣，不知要想什么新镣古怪的花样来折磨我？",
		"豹捷堂" : "没有我的管辖，豹捷堂眼看要垮了。",
		"贝海石" : (: ask_me :),
		"香主"   : "各位香主的任命由帮主老人家说了算。",
	]));

	setup();
}
int ask_me()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	if(!who->query_temp("book1131"))
	{
		message_vision("$N对$n说道： 唉，不知道如何说了。\n",this_object(),who);
  
		return 1;	
	}

	  	if(((int)who->query("jinyong/book11")>=3))
	{
		message_vision("$N对$n说道： 多谢相救！\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}
	command("thank " + who->query("id"));
	message_vision("$N对$n说道： 谢谢大侠教命之恩。。\n",this_object(),who);
	message_vision("$N对$n说道： 贝海石阴谋谋害帮主，然后让石中玉做傀儡。。\n",this_object(),who);
who->set_temp("book1132",1);
	call_out("destroying", 0);                       
	return 1;
}
void destroying()
{   
object ob=this_object();
   message_vision(HIM"$N说完闪了闪身就消失在门外......\n"NOR,ob);
destruct(this_object());
   return;      
}