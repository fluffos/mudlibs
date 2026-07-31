
#include <ansi.h>
inherit NPC;
int ask_me();
void create()
{
   set_name("霍青桐",({"huo qingtong"}));
   set("gender","女性");
   set("long","木卓伦的大女儿,慷慨豪爽,女中豪杰!\n");
   set("score",4000);
   set("combat_exp",150000);
   set("title",HIY"翠羽黄袖"NOR);
   set("area_name","回族牧群");
   
set("per",35);
set("age",21);
   set("qi",1000);
   set("max_qi",1000);
set("food",250);
set("water",250);
   set("neili",500);
   set("max_neili",500);
   set("force_factor",30);

   set_skill("dodge",100);
   set_skill("force",100);
   set_skill("parry",100);
   set_skill("unarmed",80);
   set_skill("whip",80);
   set_skill("sword",100);
        set("inquiry", ([

"古兰经" : (: ask_me :),
        ]));
   setup();
   add_money("silver",30);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/sword")->wield();
}


int ask_me()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	if(!who->query_temp("book931"))
	{
		message_vision("$N对$n说道： 我族圣物古兰经给泰山老云寨的强盗给抢走了。真不知如何是好。\n",this_object(),who);
  
		return 1;	
	}

	command("thank " + who->query("id"));
	message_vision("$N对$n说道： 多谢大侠帮我们找回圣物古兰经。\n",this_object(),who);
	message_vision("$N对$n说道： 七族盟书给张召重这个狗贼抢走了。事关我族生死存亡。\n",this_object(),who);
if(((int)who->query("jinyong/book9")==2))	
{
        i = 500+random(2800);
	who->set("jinyong/book9",3);
	who->add("combat_exp",i+12880);
	who->add("potential",i*19);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"你赢得了"+chinese_number(i+12880)+"点经验"+
	           chinese_number(i*19)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	who->save();
}
                     
	return 1;
}