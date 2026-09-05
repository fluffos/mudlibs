// danqing.c 丹青生
//by bing
#include "riyuenpc.h"
#include "riyuenpc2.h"

string askren();

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("丹青生", ({ "danqing sheng", "sheng" }));
        set("title",HIC "江南四友" NOR);
        set("long","他髯长及腹，左手拿着一只酒杯，脸上醺醺然大有醉意。\n");
	set("gender", "男性");
        set("age", 48);
        set("shen_type", -1);
        set("str", 30);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        set("max_qi", 800);
        set("max_jing", 600);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);
        set("combat_exp", 300000);
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

        set_skill("force", 100);
        set_skill("riyue-shengong", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
	set_skill("sword",100);
	set_skill("pomo-jianfa",120);
        set_skill("feitian-shenfa", 100);
        set_skill("literate",140);
        map_skill("force", "riyue-shengong");
        map_skill("parry", "pomo-jianfa");
        map_skill("dodge", "feitian-shenfa");
        map_skill("sword","pomo-jianfa");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.yulong" :),
        }) );
	create_family("日月神教", 21, "弟子");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/changjian")->wield();
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
        if ( arg != "danqing sheng" && arg != "sheng" )
           {
             return 0;
            }
        if ( ob2->query_temp("busy") )
                return notify_fail("我正忙着呢。\n");
        if (!ob2 = present(arg,environment(ob1)) )
                return notify_fail("你想跟谁比划？\n");
        if (ob1 == ob2)    return notify_fail("你不能攻击自己。\n");
      if(!ob1->query_temp("riyue/fight丹") || ob1->query_temp("riyue/赢丹"))
	{
		command("say 老夫已多年不跟人动手,岂能为你破例?");
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
               command("say 怎么不比了？打不过我是不是？\n");
               return 1;
         }
        if ( ob1->query("qi")*2 > ob1->query("max_qi"))
        {
                command("say " + RANK_D->query_respect(ob1)
                        + "武功高强，佩服佩服！\n");
		ob1->set_temp("riyue/赢丹",1);
		if (ob1->query_temp("riyue/给画"))
		{
			command("say 我就不拦" + RANK_D->query_respect(ob1) + "了，不过我的功夫是四个庄主里最弱的，你一定打不过我的几位哥哥。");
			ob = new(__DIR__"obj/key1");
                	ob->move(ob1);
			ob1->set_temp("riyue/丹ok",1);
			return 1;
		}
		command("say 可是虽然你打赢了我，但是我一样不能让你进去。");
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
	if( ob->id("xishan tu") ) 
	{
		message_vision("丹青生大叫一声：「啊哟！」目光牢牢钉住了那幅图画，再也移不开来，
隔了良久，才道：「这是北宋范宽的真迹，你……你……却从何处得来？」\n",who);
		who->set_temp("riyue/给画",1);
		if ( who->query_temp("riyue/赢丹"))
		{
			command("这样吧，这幅画给了我，你进去问我几位大哥吧！");
			key = new(__DIR__"obj/key1");
			key->move(who);
			who->set_temp("riyue/丹ok",1);
		}
        else if(random(10)==1&&who->query("safari_skill/riyue_pomo"))
        {
                command("say 好吧，我便传你几招「泼墨剑法」做交换。");
                who->improve_skill("pomo-jianfa", 4);
                who->delete_temp("riyue/给画");
        }
          call_out("destroying",0,who,ob);
		return 1;
	}
	else return 0;
}

string askren()
{
	object me = this_player();
	me->set_temp("riyue/问丹",1);
	if (me->query_temp("riyue/killer"))
	{
		return "他不是已经在这儿了吗？\n";
	}
	if (objectp(present("heimu ling",me)) && (me->query_temp("riyue/怀疑") != 1) )
	{
		command("say " + RANK_D->query_respect(me) + "是东方教主派来的吧？");
		command("say 东方教主已经谕示我们助您一臂之力。");
		command("say 是否要在那人饮食里下毒呢？这样最方便。(y/n)");
		input_to("xiadu",me);
		return "你回去吧！\n";
	}
	return "东方教主让我们在这里看护，谁也不许见他。\n";
}

void xiadu(string arg, object me)
{
	object obj;
	if (arg == "y")
	{
		message_vision("丹青生点了点头，叹了口气，走了出去。\n",me);
		message_vision("过了一会儿，丹青生抬着一具尸体走了进来。\n",me);
		command("say 都在这儿了。我们四兄弟跟日月教的关系也就到此为止吧，从此我们在此不问世事，专心于琴棋书画。");
		obj = new("/d/riyuejiao/obj/corpse");
		obj->move(environment(me));
		me->set_temp("riyue/killer",1);
		return;
	}
	if (arg == "n")
	{
		message_vision("丹青生怀疑的看了看$N。说道：「你一心要见到任我行，是什么意思？」\n",me);
		message_vision("显然丹青生已经不相信$N的黑木令是真的了。\n",me);
		me->set_temp("riyue/怀疑",1);
		return;
	}
	
}	


