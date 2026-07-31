// luo-bing.c 骆冰
// Last Modified by winder on Sep. 12 2001

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_me();
void create()
{
	set_name("骆冰", ({ "luo bing", "luo" }));
	set("title", HIR"红花会"HIG"十一当家"NOR);
	set("nickname", HIG"鸳鸯刀"NOR);
	set("long","她是一个秀美的少妇。\n她是红花会文四当家的浑家，神刀骆元通的女儿。\n她一手短刀，一手握着一柄长刀。双手执白刃，如持鲜花枝。风姿嫣然。\n");
	set("gender", "女性");
	set("class", "swordman");
	set("age", 24);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 28);
	set("str", 21);
	set("int", 21);
	set("con", 21);
	set("dex", 21);
	
	set("max_qi", 1500);
	set("max_jing", 1200);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("score", 50000);

	set_skill("force", 80);
	set_skill("honghua-shengong", 80);
	set_skill("dodge", 80);
	set_skill("youlong-shenfa", 120);
	set_skill("hand", 80);
	set_skill("benlei-shou", 120);
	set_skill("blade", 80);
	set_skill("qiuge-dao", 120);
	set_skill("throwing", 80);
	set_skill("wuying-feidao", 120);
	set_skill("parry", 80);
	set_skill("literate", 50);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("hand", "benlei-shou");
	map_skill("parry", "qiuge-dao");
	map_skill("blade", "qiuge-dao");
	prepare_skill("hand", "benlei-shou");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({	
		(: perform_action, "blade.luohuaqiuge" :),			
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
        set("inquiry", ([

"营救" : (: ask_me :),
        ]));
	create_family("红花会", 2, "弟子");
	setup();
	carry_object("/clone/cloth/female2-cloth")->wear();
	carry_object("/clone/cloth/female-shoe")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
	object ob;

	::init();
	ob = this_player();
	if((int)ob->query("shen") < -1000 &&
		ob->query("family/master_id")=="luo bing")
	{
		command( "chat "+ob->query("name")+"！你这等邪恶奸诈之徒，我岂能仍是你的师父。\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","红花会" + RED + "弃徒" NOR);
	}
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 5000)
	{
		command("say 我红花会收徒极严。");
		command("say 这位" + RANK_D->query_respect(ob) + "平时还要多做一些行侠仗义之事！");
		return;
	}
	command("say 好，你这个年青人还不错，我收下你了！");
	command("recruit " + ob->query("id"));
}

int ask_me()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	if(!who->query_temp("book91"))
	{
		message_vision("$N对$n说道： 我的丈夫文泰来还给困在暗巷。\n",this_object(),who);
  
		return 1;	
	}
  	if(((int)who->query("combat_exp",1)<=500000))
	{
		message_vision("你的武功太差了，等武功好点再来吧！\n",who);
		return 1;	
	}
	  	if(((int)who->query("jinyong/book9")>=1))
	{
		message_vision("$N对$n说道： 多谢相救！\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}
	command("thank " + who->query("id"));
	message_vision("$N对$n说道： 谢谢大侠教命之恩。。\n",this_object(),who);
	message_vision("$N对$n说道： 我们夫妻打算去饿虎岗附近的铁胆庄 暂避一下。。\n",this_object(),who);
if(!who->query("jinyong/book9"))	
{
        i = 300+random(800);
	who->set("jinyong/book9",1);
	who->add("combat_exp",i+8880);
	who->add("potential",i*10);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"你赢得了"+chinese_number(i+8880)+"点经验"+
	           chinese_number(i*10)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	who->save();
}
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