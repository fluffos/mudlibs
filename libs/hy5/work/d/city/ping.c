// ping.c 平一指

inherit NPC;
inherit F_DEALER;
int ask_wu();
string ask_me();
void create()
{
	set_name("平一指", ({ "ping yizhi", "ping", "yizhi" }));
	set("title", "药铺老板");
	set("gender", "男性");
	set("long", "他就是医术高超的「杀人神医」平一指。可是他性格古怪，不是什么人都医的。\n");
	set("age", 65);

	set("int", 30);
	
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);

	set("combat_exp", 500000);
	set("attitude", "heroism");
          set("chat_chance", 1);
             set("chat_msg", ({
(: command("say 这段时间总感觉自己老了，干活力不从心。看来要找人帮我磨药才行！\n") :),
(: command("say 请来的小伙子干活还挺卖力的，真是长江后浪推前浪,不认老都不行了！\n") :),
                 }) );

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 60);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 50);
        set("inquiry", ([
                "何首乌" : (: ask_wu :),
                "job" : (: ask_me :),
             	"工作" : (: ask_me :),
        ]));

	set("vendor_goods", ({
	}));

	setup();
	add_money("gold", 1);
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
//	add_action("do_buy", "buy");
}
int ask_wu()
{
	object ob;
	ob = this_player ( ) ;
message_vision("平一指上上下下打量了$N一下：什么！何首乌？拿三十两黄金来！\n",ob);
	ob->set_temp ("何首乌" , 1 );
	return 1;
}

int accept_object(object who, object ob)
{
	object obj ;
	if (!(int)who->query_temp("何首乌"))
	{
        message_vision("平一指对$N说：医一人，杀一人，老夫不收钱！\n", who);
		return 0 ;
	}
	if (ob->query("money_id") && ob->value() >= 300000)
	{
	        add_temp("he",-1);
		message_vision("平一指给了$N何首乌！\n" , who);
		this_player()->delete_temp("何首乌" );
		obj=new(__DIR__"obj/shouwu");
		obj->move(this_player());
	}
	return 1;
}

string ask_me()
{
	object ob;
          ob=this_player();
         if (ob->query("combat_exp")<100000)
                return "我的工作你现在还做不了吧！";
          if (ob->query("combat_exp")>180000)
                return "以你的本事已经不用在我这工作了！";
       if (ob->query("job_moyao") >0)
		return "我交给你的事情你还没做呢！";
       ob->set("job_moyao",1);
        return "好吧，你就帮我磨药(moyao)吧！";
}
