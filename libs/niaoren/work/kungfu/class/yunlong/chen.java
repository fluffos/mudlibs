// chen.c 陳近南

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_weiwang();
string ask_me();

void create()
{
	set_name("陳近南", ({ "chen jin nan", "chen","nan" }));
	set("nickname", HIC "英雄無敵" NOR);
	set("long", 
		"\n這是一個文士打扮的中年書生，神色和藹。\n"
		"他就是天下聞名的天地會總舵主陳近南，\n"
		"據說十八般武藝，樣樣精通。\n"
		"偶爾向這邊看過來，頓覺他目光如電，英氣逼人。\n");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("houquan", 150);
	set_skill("yunlong-xinfa", 200);
	set_skill("yunlong-shengong", 200);
	set_skill("wuhu-duanmendao", 150);
	set_skill("yunlong-jian", 200);
	set_skill("yunlong-shenfa", 150);
	set_skill("yunlong-bian", 150);
	set_skill("yunlong-shou", 150);
	set_skill("yunlong-zhua", 150);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	create_family("云龍門",1, "開山祖師");
	set("book_count", 1);
        set("inquiry", ([
		"天地會" :  "\n只要是英雄好漢，都可以入我天地會(join tiandihui)。\n",
		"入會" :  "\n只要入我天地會，可以向各位好手學武藝。\n",
                "反清復明" : "去棺材店和回春堂仔細瞧瞧吧！\n",
                "暗號" : "敲三下！\n",
                "切口" : "敲三下！\n",
                "威望" :  (: ask_weiwang :),
                "江湖威望" : (: ask_weiwang :),
		"云龍劍譜" : (: ask_me :),
	]) );
	set("env/wimpy", 60);
        set("chat_chance_combat", 60);  
        set("chat_msg_combat", ({
                "\n陳近南搖頭嘆道：螳臂當車，不自量力。唉，你這又是何苦呢?\n",
                (: command("smile") :),
                (: command("poem") :),
                (: command("nomatch") :),
                (: command("haha") :),
                (: command("chat 這位" + RANK_D->query_respect(this_player())+",你我無冤無仇，何必如此?\n") :),
                (: command("unwield changjian") :),
                (: command("wield changjian") :),
                (: command("wield bian") :),
                (: perform_action, "sword.yu1" :),
                (: perform_action, "whip.yu1" :),
                (: perform_action, "blade.wu1" :),
                (: exert_function, "p" :),
                (: exert_function, "re1" :),
                (: command("unwield bian") :),
                (: command("wield blade") :),
                (: command("unwield blade") :),
                      }) );
 	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
	carry_object("/d/city2/obj/yaodai")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city2/obj/hlbian");
	carry_object("/d/city/obj/gangdao");
}

string ask_me()
{
        mapping fam; 
        object ob;

        if (!(fam = this_player()->query("family")) 
	    || fam["family_name"] != "云龍門")
                return RANK_D->query_respect(this_player()) + 
                "與本派素無來往，不知此話從何談起？";
        if (query("book_count") < 1)
                return "你來晚了，本派的云龍真經不在此處。";
        add("book_count", -1);
        ob = new("/clone/book/yljianpu");
        ob->move(this_player());
        return "好吧，這本「云龍劍譜」你拿回去好好鑽研。";
}

void init()
{
	::init();
	add_action("do_skills","skills");
	add_action("do_skills","cha");
	add_action("do_join","join");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("yunlong-shengong", 1) < 50)
	{
		command("say 我云龍神功\乃內家武功\，最重視內功\心法。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否還應該在云龍神功\上多下點功\夫？");
		return;
	}
	if ((int)ob->query("weiwang") <60)
	{
		command("say 我云龍門武功\天下無敵，凡入我門，\n必闖蕩江湖，行俠仗義，為天下蒼生謀福利。\n"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否應該先出去闖一闖，做几件驚天動地的大事？");
		return ;
	}
	if ((int)ob->query("shen") >0&&(int)ob->query("shen") < 5000) {
		command("say 學武之人，德義為先，功\夫的高低倒還在其次，未練武，要先學做人。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否還做得不夠？");
		return ;
	}
	if(ob->query("weiwang")<80)
	{
		if((int)ob->query("shen")<0)
 command("say "+ RANK_D->query_respect(ob) +"雖然是邪派中人，但也還做了些好事。\n");
		command("chat 我天地會所作所為，無一不是前人所未行之事。\n");
		command("chat 萬事開創在我，駭人聽聞，物議沸然，又何足論？\n");
		command("chat 今天就收了你吧！！\n");
		command("chat 想不到我一身驚人藝業，今日終于有了傳人，哈哈哈哈！！！！\n");
		message_vision(HIC "$N的江湖威望提高了！\n" NOR,this_player());
		ob->set("weiwang",80);
	}
	command("recruit " + ob->query("id"));
	if((!(string)ob->query("class")) || ((string)ob->query("class") != "fighter"))
		ob->set("class","fighter");
}

int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="chen" )
		return 0;
	if(wizardp(ob))  return 0;
	if (ob->query("weiwang")<50)
	if (ob->query("party/party_name") != HIR "天地會" NOR )
	{
		message_vision("$N搖了搖頭。\n",this_object());
		command("tell "+ob->query("id")+" 不是天地會弟子不能察看。\n"); 
		return 1;
	}

	command("tell "+ob->query("id")+" 我所有的基本武功\如下：\n"+
	"  基本刀法 (blade)                         - 深不可測 200/   \n"+
	"  基本爪法 (claw)                          - 深不可測 200/   \n"+
	"  基本輕功\ (dodge)                         - 深不可測 200/    \n"+
	"  基本內功\ (force)                         - 深不可測 200/    \n"+
	"  基本手法 (hand)                          - 深不可測 200/    \n"+
	"  基本拳腳 (unarmed)                       - 深不可測 200/    \n"+
	"  基本鞭法 (whip)                          - 深不可測 200/    \n"+
	"  基本招架 (parry)                         - 深不可測 200/    \n"+
	"  基本劍法 (sword)                         - 深不可測 200/    \n"+
	"  云龍心法 (yunlong-xinfa)                 - 深不可測 200/    \n"+
	"  讀書寫字 (literate)                      - 深不可測 100/    \n");
	command("tell "+ob->query("id")+" 我所有的高深武功\如下：\n"+
	"□猴拳 (houquan)                           - 深不可測 150/    \n"+
	"□五虎斷門刀 (wuhu-duanmendao)             - 深不可測 150/    \n"+
	"□云龍神功\ (yunlong-shengong)              - 深不可測 150/    \n"+
	"□云龍身法 (yunlong-shenfa)                - 深不可測 150/    \n"+
	"□云龍劍法 (yunlong-jian)                  - 深不可測 200/    \n"+
	"□云龍鞭 (yunlong-bian)                    - 深不可測 150/    \n"+
	"□云龍手 (yunlong-shou)                    - 深不可測 150/    \n"+
	"□云龍爪 (yunlong-zhua)                    - 深不可測 150/    \n");
	return 1;
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" 你現在的江湖威望是 " +(string)(this_player()->query("weiwang")));
	say("\n陳近南說道：如果你威望值很高，有些人見了你不但不會殺你，還會教你武功\，送你寶貝。\n"
	+"而且你還可以加入幫會，率領會眾去攻打目標，就連去錢庄取錢也會有利息 。。。。。\n");
	say("陳近南又說：殺某些壞人或救某些好人可以提高江湖威望。\n");
	return 1;
}

int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="tiandihui" )
	return notify_fail("你要加入什么\組織？\n"); 
   if (ob->query("weiwang")<20)
        {
	command("tell "+this_player()->query("id")+" 你現在的江湖威望是 " +(string)(this_player()->query("weiwang")));
	message_vision(HIC "陳近南對$N搖了搖頭說：你的江湖威望值太低。\n" NOR,this_player());
	return 1;
  	}
   if(ob->query("weiwang")<50)
   {
    ob->set("weiwang",50);
    message_vision(HIC "$N的江湖威望提高了！\n" NOR,this_player());
    command("tell "+this_player()->query("id")+" 你現在的江湖威望是 " +(string)(this_player()->query("weiwang")));
    return 1;	
   }
   else message_vision(HIC "陳近南對$N搖了搖頭說：你已經加入天地會了。\n" NOR,this_player());
   return 1;
}
