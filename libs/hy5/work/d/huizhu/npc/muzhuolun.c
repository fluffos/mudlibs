inherit NPC;
#include <ansi.h>
int ask_me();
void create()
{
   set_name("木卓伦",({"muzhuolun"}));
   set("gender","男性");
      set("long","木卓伦是回族部落的英雄!\n");
   set("shen",25000);
   set("combat_exp",500000);
     set("age",45);
    set("food",250);
    set("water",250);
   set("neili",2500);
   set("max_neili",2500);
   set("force_factor",60);

   set_skill("dodge",160);
   set_skill("force",160);
   set_skill("parry",160);
   set_skill("unarmed",160);
   set_skill("blade", 200);
        set("title",HIY"回族英雄"NOR);
        set("inquiry", ([

"七族盟书" : (: ask_me :),
        ]));

	setup();
   carry_object("clone/weapon/gangdao")->wield();
   carry_object("clone/cloth/cloth")->wear();
	add_money("gold",1);
}


int ask_me()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	if(!who->query_temp("book941"))
	{
		message_vision("$N对$n说道： 七族盟书给张召重抢走了。真不知如何是好。\n",this_object(),who);
  
		return 1;	
	}

	if(!who->query_temp("book942"))
	{
		message_vision("$N对$n说道： 七族盟书给张召重抢走了。据说他已经把盟书上交给了朝廷。\n",this_object(),who);
  
		return 1;	
	}

	command("thank " + who->query("id"));
	message_vision("$N对$n说道： 多谢大侠帮我们找回七族盟书。\n",this_object(),who);
	message_vision("$N对$n说道： 听说陈家洛去杭州找乾隆算账去了。\n",this_object(),who);
if(((int)who->query("jinyong/book9")==3))	
{
        i = 800+random(2800);
	who->set("jinyong/book9",4);
	who->add("combat_exp",i+15880);
	who->add("potential",i*19);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"你赢得了"+chinese_number(i+15880)+"点经验"+
	           chinese_number(i*19)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	who->save();
}
                     
	return 1;
}