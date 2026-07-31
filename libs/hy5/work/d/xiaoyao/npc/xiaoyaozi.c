// xiaoyaozi.c 逍遥子
// shilling 97.2

inherit NPC;
inherit F_MASTER;
int ask_me2();

void create()
{
	set_name("逍遥子", ({ "xiaoyao zi", "xiaoyao","zi" }));
	set("title", "逍遥派开山祖师");
	set("long", 
		"他就是逍遥派开山祖师、但是因为逍遥派属于一个在江湖中\n"
		"的秘密教派，所以他在江湖中不是很多人知道，但其实他的\n"
		"功夫却是。。。。他年满七旬，满脸红光，须眉皆白。\n");
	set("gender", "男性");
	set("age", 75);
	set("class", "scholar");
	set("attitude", "friendly");
		set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 60);
	set("int", 60);
	set("con", 60);
	set("dex", 60);
	set("per", 26);
	
	set("max_qi", 15500);
	set("max_jing", 13000);
	set("neili", 33000);
	set("max_neili", 33000);
	set("jingli", 2000);
	set("max_jingli", 2000);
	set("jiali", 100);
	set("combat_exp", 9800000);
	set("score", 200000);

	set_skill("force", 300);
        set_skill("yangyanshu", 380);
	set_skill("bahuang-gong", 380);
	set_skill("beiming-shengong", 380);
	set_skill("dodge", 300);
	set_skill("goplaying", 105);
	set_skill("luteplaying", 105);
	
	set_skill("painting", 105);
	set_skill("medicine", 105);
	set_skill("construction", 105);
	set_skill("horticulture", 105);
	set_skill("dramaturgy", 105);
	
	
	set_skill("lingboweibu", 380);
	set_skill("unarmed", 260);
	set_skill("liuyang-zhang", 380);
	set_skill("parry", 260);
	set_skill("blade", 260);
	set_skill("ruyi-dao", 380);
	set_skill("zhemei-shou", 380);
	set_skill("hand", 300);
	set_skill("literate", 300);
	set_skill("strike", 280);
	set_skill("sword", 380);
	set_skill("hand", 280);
	set_skill("qingyun-shou", 380);
	set_skill("panyang-zhang", 380);
	set_skill("liuyue-jian", 380);
	map_skill("force", "beiming-shengong");
	map_skill("dodge", "lingboweibu");
	map_skill("unarmed", "zhemei-shou");
	map_skill("hand", "zhemei-shou");
	map_skill("strike", "liuyang-zhang");
	
	map_skill("parry", "ruyi-dao");
	map_skill("blade", "ruyi-dao");

	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.shishiruyi" :),
                (: perform_action, "blade.ruyi" :),
                (: perform_action, "dodge.lingbo" :),
                (: perform_action, "strike.zhong" :),
                (: perform_action, "strike.lianzhong" :),
                (: perform_action, "hand.tanmei" :),
                (: perform_action, "hand.zhemei" :),          
	}) );
	

	set("inquiry" ,([
	"巫行云" : (: ask_me2 :),
	]));
	
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 300);
	create_family("逍遥派", 1, "开山祖师");
	set("class", "taoist");

	setup();
	carry_object(__DIR__"obj/blade")->wield();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("beiming-shengong", 1) < 150) {
		command("say 我逍遥派内功的源泉来自于北冥神功的心法。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"的北冥神功是否还应该有所提高啊？");
		return;
	}

	if (ob->query_int() < 35) {
		command("say 我逍遥派武功最重视“逍遥”二字。");
		command("say 而何谓“逍遥”，这只能靠你自己去领悟。");
		command("say 但是" + RANK_D->query_respect(ob) + "的悟性似乎还有待提高啊。");
		return;
	}
	command("smile");
	command("say 想不到在这世上竟然还有人可以继承我的逍遥心法！");
	command("recruit " + ob->query("id"));
	ob->set("title","逍遥派护法使者");
}


int ask_me2()
{
	object ob, me;
	int i;
	object fang,who,where;
	
	me = this_player();
	who=me;
	where = environment(who);
	  	if(((int)me->query("jinyong/book4")!=5))
	{
		message_vision("$N对$n说道： 你在说什么啊? \n",this_object(),me);
                return 1;	
	}

	  	if(!me->query_temp("qijuok"))
	{
		message_vision("$N对$n说道： 要知道这件事，你先去解开玲珑棋局吧。 \n",this_object(),me);
                return 1;	
	}

      if(!query("iskillok"))
      {
      message_vision("突然从门外突然丁春秋杀了进来说道：老鬼 你太不公平了!\n",this_object(),who);	
      	fang = load_object("/quest/menpaijob/xingxiu/ding");
	fang->move(environment(who));	
	fang->kill_ob(who);
     this_object()->set("iskillok",1);
     set("iskillok",1);
      }	

        fang = present("ding chunqiu",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"先帮我战败丁春秋吧。\n",this_object(),who);
		return 1;
	}

	  	if(((int)me->query("jinyong/book4")==5))
	{
		
 	i = 1900+random(1900);
	me->set("jinyong/book4",6);
	me->add("combat_exp",i+15880);
	me->add("potential",i*16);
	me->add("mpgx",10);
	me->add("expmax",2);

	tell_object (me,"你赢得了"+chinese_number(i+15880)+"点经验"+
	           chinese_number(i*16)+"点潜能"+"十点门派贡献 二点成长上限！！\n");

		
         }		
		message_vision("$N对$n说道： 唉 你去天山找巫行云吧。\n",this_object(),who);
		return 1;

	
}