// renying.c

inherit NPC;
inherit F_MASTER;
#include "riyue.h"

string inquiry_linghuchong();

void create()
{
	set_name("任莹莹", ({ "ren yingying","ren","ying"}) );
	set("gender", "女性" );
	set("title", "圣姑" );
	set("age", 20);
	set("shen_type", 1);
	set("combat_exp", 500000);
	set("per", 30);
	set("str", 16);
	set("dex", 27);
	set("con", 17);
	set("int", 18);
	set("attitude", "friendly");
	
	set("qi", 500);
	set("max_qi", 500);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 10);
	
	set_skill("force", 120);
	set_skill("sword", 120);
	set_skill("unarmed", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("whip", 120);
	
	set_skill("riyue-xinfa", 120);
	set_skill("liushui-bian", 120);
	set_skill("piaomiao-shenfa", 120);
	set_skill("riyue-jian", 120);
	set_skill("literate", 120);
	
	map_skill("force", "riyue-xinfa");
	map_skill("whip", "liushui-bian");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("parry", "liushui-bian");
	map_skill("sword", "riyue-jian");
	/*
	set("chat_msg_combat", ({
		(: perform_action, "whip.liuxing" :),
		(: perform_action, "whip.wang" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));
	*/
	set("chat_chance",60);
    	set("chat_msg",({
	"任莹莹说道：不知令狐聪他，怎样了，是否又和那小贱人在一起......\n",
	"任莹莹说道：你若能把这封信捎给他，可太谢谢你了.............\n",
	"任莹莹说道：也不知蓝幽凰见没见到他，可真急死我了.......\n",
	   }) );
       
	   create_family("日月神教", 3, "弟子");
       set("inquiry",([
		"令狐聪" : (: inquiry_linghuchong:),
	   ]) );
       set_temp("letter",1);
       setup();
       carry_object("/clone/cloth/female5-cloth")->wear();
       carry_object("/clone/weapon/changbian")->wield();
       carry_object("/d/heimuya/npc/obj/letter");
}

string inquiry_linghuchong()
{
 object me=this_player();
 object obn;

 message_vision("任莹莹说道：去年上华山一去就再无音信，他不会忘记我吧......\n", me );
 if(query_temp("letter")==0)
 {  message_vision("任莹莹又说道：这位"+ RANK_D->query_respect(me)+"，我已经派
蓝幽凰去寻找了，也不知道怎么样了。\n",me);
   return "";
 }
   message_vision("任莹莹又说道：这位"+ RANK_D->query_respect(me)+"，我这里有
信，你要是找到令狐聪，就把信交给他，他会明白的。\n" , me);
   obn=new("/d/heimuya/npc/obj/letter");
   obn->move(me);
   set_temp("letter",0);
   
   return ("这封信烦你交给令狐聪。\n");
}
void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	command("say 好吧！我以圣姑的名义收下你了。");
	command("recruit " + ob->query("id"));
}
