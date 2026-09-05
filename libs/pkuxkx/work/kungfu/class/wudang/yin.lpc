#include <ansi.h>
// yu.c 殷梨亭
#include <title.h>
inherit NPC;
inherit F_MASTER;

void heal();
int ask_yang();
int ask_ji();
int ask_tongshou();

void create()
{
	set_name("殷梨亭", ({ "yin liting", "yin" }));
	set("nickname", RED "武当六侠" NOR);
	set("long",
		"这是武当六侠殷梨亭，他生的白白净净，一副秀气腼腆的样子。\n"
		"但他出招却是老练泼辣，与他的外表极不相符。\n");
	set("title",RED "武当派" NOR + GRN +"真人" NOR);
	set("gender", "男性");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: exert_function , "powerup" :)
	}) );
	
	set("chat_chance", 20);
	set("chat_msg", ({
		(: heal :),
		"殷梨亭咬牙切齿道：杨逍恶贼，总有一天我要把你碎尸万段。\n",
		"殷梨亭面容悲切：晓芙……晓芙……你好可怜，师太她太狠心了。\n",
		"殷梨亭忸怩的说：不悔她待我真好！\n",
	}));
	set("max_qi", 1500);
	set("max_jing", 800);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("score", 100000);
	
	set_skill("force", 140);
	set_skill("taiji-shengong", 140);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 150);
	set_skill("cuff", 150);
	set_skill("taiji-quan", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("taiji-jian", 150);
	set_skill("taoism", 80);
	set_skill("literate", 80);
	
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("cuff", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	prepare_skill("cuff", "taiji-quan");
	set("inquiry",([
		"杨逍"		: (: ask_yang :),
		"纪晓芙"	: (: ask_ji :),
		"杨不悔"	: "不悔，她就是拙荆啊，你找他有什么事吗？",
		"同归于尽"	: (: ask_tongshou :),
		]));
		
        create_family("武当派", 2, "弟子");
	
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/whiterobe")->wear();
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name")!="武当派" || (string)ob->query("class")!="taoist") {
		command("say 我武当乃是道家门派。");
		command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜我徒侄谷虚。"); 
		return;
	}
	if ((int)ob->query("shen") < 10000) {
		command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
		command("say " + RANK_D->query_respect(ob) + "若能做出" +
			"几件侠义之事，我一定收你。");
		return;
	}
	command("say 好吧，既然" + RANK_D->query_respect(ob) + "也是" +
		"我辈中人，今天就收下你吧。");
	command("recruit " + ob->query("id"));
	if ((string)ob->query("gender")!="女性")
		ob->set("title" ,RED "武当派" NOR + GRN "道长" NOR);
	else
		ob->set("title" ,RED "武当派" NOR + GRN "女道长" NOR);
//title系统记录玩家title by seagate@pkuxkx
	ob->set_title(TITLE_RANK, ob->query("title"));
}

void init()
{
	
	object ob;
	mapping fam;
	
	::init();
	
	ob = this_player();
	if ( (int)ob->query("shen") <1000 && (string)ob->query("family/master_id") == "yin liting")
	{
		command("say 你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
		command("expell "+ ob->query("id"));
	}
}		

void heal()
{
	object ob;
	ob=this_object();
	
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		command("enforce 50");
		return;
	}
	
	if (ob->query("qi") < ob->query("eff_qi"))
	{
		command("exert recover");
		return;
	}
	
	if (ob->query("jing") < ob->query("eff_jing"))
		command("exert regenerate");
	
	return;
}
int ask_yang()
{
	object me;
	me=this_player();
	if(me->query_temp("marks/ask_yin_about_纪晓芙",1))
	{
		message("vision",HIW"殷梨亭咬牙切齿的说：杨逍恶贼，就是他毁了晓芙妹子的清白，就算我杀不死，我也要跟他同归于尽。\n"NOR,environment(),this_object());
		me->set_temp("marks/ask_yin_about_杨逍",1);
	}
	else
		message("vision",HIW"殷梨亭狠道：魔教贼子，人人得而诛之。\n"NOR,environment(),this_object());
	return 1;
}
int ask_ji()
{
	object me;
	me=this_player();
	message("vision",HIW"殷梨亭面容悲切：晓芙……晓芙……你好可怜啊……，我定杀了杨逍恶贼为你报仇。\n"NOR,environment(),this_object());
	me->set_temp("marks/ask_yin_about_纪晓芙",1);
	return 1;
}
int ask_tongshou()
{
	object me;
	string msg;
	me=this_player();
	if(me->query_temp("marks/ask_yin_about_杨逍",1)==1)
	{
		msg=HIW "殷梨亭面色凝重的说：我自知武功不比那姓杨得恶贼高，所以自创了这招“天地同寿”，我便将它传授于你，希望你能为我晓芙妹子报得此仇。\n"+
			"殷梨亭又道：这招“天地同寿”威力极大，轻易不可使用，切记切记。\n"NOR;
		message_vision(msg,this_object());
		if(me->query_skill("taiji-jian",1)<100&&me->query("tongshou",1)<10)
		{
			msg=HIW "可是$N的太极剑法不够纯熟，未能领会到“天地同寿”这一绝招。\n"NOR;
			message_vision(msg,me);
			if(me->query("tongshou",1)<5)
				me->set("tongshou",me->query("tongshou",1)+1);
		}
		else if(me->query("tongshou",1)!=5)
		{
			msg=HIW"$N听着殷梨亭的指导，学会了“天地同寿”这一招。\n"NOR;
			message_vision(msg,me);
			me->set("tongshou",10);
		}
		else
		{
			msg=HIW"$N听着殷梨亭的指导，觉得殷梨亭所说和以前并无什么两样，又比划了几下，终觉无趣，便自睡觉去了。\n"NOR;
			message_vision(msg,me);
		}
	}
	return 1;
}
