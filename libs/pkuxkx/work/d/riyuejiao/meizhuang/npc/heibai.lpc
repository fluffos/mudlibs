//heibai.c 黑白子
//by bing
#include "riyuenpc.h"
#include "riyuenpc2.h"

string askren();

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("黑白子", ({ "heibai zi", "zi" }));
        set("title",HIC "江南四友" NOR);
        set("long","这人眉清目秀，只是脸色泛白，似乎是一具僵尸模样，令人一见之下，
心中便感到一阵凉意。他头发极黑而皮肤极白，果然是黑白分明。\n");
	set("gender", "男性");
        set("age", 56);
        set("shen_type", -1);
        set("str", 30);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        set("max_qi", 1000);
        set("max_jing", 600);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 80);
        set("combat_exp", 400000);
	set("score",1000);
        set("chat_chance", 30);
        set("chat_msg", ({
                (: heal :),
        }));
        set("inquiry", ([
            "东方不败" : "东方教主的名字也是你叫得的？",
	    "圣药" : "你怎么会知道这件事的？",
	    "三尸脑神丹" : "你怎么会知道这件事的？",
            "东方教主" : (: ask_df :),
	    "任我行" : (: askren :),
       ]) );

        set_skill("force", 140);
        set_skill("riyue-shengong", 140);
        set_skill("dodge", 140);
        set_skill("parry", 140);
	set_skill("sword",140);
	set_skill("qipan-gong",140);
        set_skill("feitian-shenfa", 140);
        set_skill("literate",150);
        map_skill("force", "riyue-shengong");
        map_skill("parry", "qipan-gong");
        map_skill("dodge", "feitian-shenfa");
        map_skill("sword","qipan-gong");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.xi" :),
        }) );
	create_family("日月神教", 21, "弟子");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/qicheng")->wield();
       }
void init()
{
	object ob;
	mapping fam;
        ::init();
	ob = this_player();
	if (interactive(ob) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_bihua", "fight");
	add_action("do_halt","halt");

}

int do_bihua(string arg)
{
        object ob1, ob2;
        object old_target;
        ob1 = this_player();
	ob2 = this_object();
        if( !arg || arg=="" ) return 0;
        if ( arg != "heibai zi" && arg != "zi" )
           {
             return 0;
            }
        if ( ob2->query_temp("busy") )
                return notify_fail("我正忙着呢。\n");
        if (!ob2 = present(arg,environment(ob1)) )
                return notify_fail("你想跟谁比划？\n");
        if (ob1 == ob2)    return notify_fail("你不能攻击自己。\n");
      if (!ob1->query_temp("riyue/问黑") || ob1->query_temp("riyue/赢黑"))
	{
		command("say 老夫久已不跟人动手，岂能为你破例？");
		return 1;
	}
        message_vision("\n$N对着$n说道"
                        + RANK_D->query_self(ob1)
                        + ob1->name() + "领教"
                        + RANK_D->query_respect(ob2) + "的高招ⅵ\n\n", ob1, ob2
			);
        ob1->set_temp("pending/fight", ob2);
        ob1->delete_temp("halted");
        ob2->delete_temp("halted");
        remove_call_out("check");
        call_out("check",0, ob1, ob2);
        remove_call_out("fighting");
        call_out("fighting",2, ob1, ob2);
        return 1;
}
void fighting(object ob1, object ob2)
{
        ob1->fight_ob(ob2);
        ob2->fight_ob(ob1);
}
void check(object ob1, object ob2)
{
	command("fight " + ob1->query("id"));	
        call_out("observe",1,ob1,ob2);
}
int observe(object ob1,object ob2)
{
        object ob;
        if(ob1->is_fighting())
        {
                call_out("observe",1,ob1,ob2);
                return 1;
        }
        ob1->delete_temp("pending/fight");
        ob2->delete_temp("pending/fight");
        if ( !present(ob1, environment()) )
        {
                return 1;
        }
        if (ob1->query_temp("halted"))
         {
               ob1->delete_temp("halted");
               command("say 承让！");
               return 1;
         }
        if ( ob1->query("qi")*2 > ob1->query("max_qi"))
        {
                command("say " + RANK_D->query_respect(ob1)
                        + "武功高强，佩服佩服！\n");
		ob1->set_temp("riyue/赢黑",1);
		if (ob1->query_temp("riyue/给棋"))
		{
			command("say 我就不拦" + RANK_D->query_respect(ob1) + "了，不过你还要得到另外几位庄主的同意才行。");
			ob = new(__DIR__"obj/key3");
                	ob->move(ob1);
			ob1->set_temp("riyue/黑ok",1);
			return 1;
		}
		command("say 可是你就是打赢了我，也不能放你进去。");
        }
        else
        {
		command("say " + RANK_D->query_respect(ob1) + "的武功还需再练练啊！");
        }
        return 1;
}
int do_halt()
{
	object me = this_player();
	if (me->is_fighting())
	 me->set_temp("halted",1);
	return 0;
}
int destroying(object who,object ob)
{
      destruct(ob);
}


int accept_object(object who, object ob)
{
	object key;
	who = this_player();
	if( ob->id("ouxue pu") ) 
	{
		message_vision("黑白子惊喜地说：「这当真是刘仲甫和骊山仙姥对弈的图谱？难道世上真有这局《呕血谱》？」
他一贯神情冷漠，此刻却是十分的热切。\n",who);
		who->set_temp("riyue/给棋",1);
		if ( who->query_temp("riyue/赢黑"))
		{
			command("say 这样吧，这局棋谱给了我，你进去问我几位兄弟吧！");
			key = new(__DIR__"obj/key3");
			key->move(who);
			who->set_temp("riyue/黑ok",1);
		}
                call_out("destroying",0,who,ob);
		return 1;
	}
	else return 0;
}

string askren()
{
	object me = this_player();
	me->set_temp("riyue/问黑",1);
	return "东方教主让我们在这里看护，谁也不许见他。\n";
}

