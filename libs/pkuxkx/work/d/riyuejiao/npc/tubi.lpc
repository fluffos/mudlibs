// tubi.c 秃笔翁
//by bing
#include "riyuenpc.h"
#include "riyuenpc2.h"

string askren();

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("秃笔翁", ({ "tubi weng", "weng" }));
        set("title",HIC "江南四友" NOR);
        set("long","这人矮矮胖胖，头顶秃得油光滑亮，一根头发也无，右手提着一枝大笔，衣衫上都是墨迹。\n");
	set("gender", "男性");
        set("age", 50);
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

        set_skill("force", 120);
        set_skill("riyue-shengong", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
	set_skill("sword",120);
	set_skill("panguan-bifa",120);
        set_skill("feitian-shenfa", 120);
        set_skill("literate",140);
        map_skill("force", "riyue-shengong");
        map_skill("parry", "panguan-bifa");
        map_skill("dodge", "feitian-shenfa");
        map_skill("sword","panguan-bifa");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.xiezi" :),
        }) );
	create_family("日月神教", 21, "弟子");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/panguanbi")->wield();
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
        if ( arg != "tubi weng" && arg != "weng" )
           {
             return 0;
            }
        if ( ob2->query_temp("busy") )
                return notify_fail("我正忙着呢。\n");
        if (!ob2 = present(arg,environment(ob1)) )
                return notify_fail("你想跟谁比划？\n");
        if (ob1 == ob2)    return notify_fail("你不能攻击自己。\n");
      if (!ob1->query_temp("riyue/问秃") || ob1->query_temp("riyue/赢秃"))
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
		ob1->set_temp("riyue/赢秃",1);
		if (ob1->query_temp("riyue/给字"))
		{
			command("say 我就不拦" + RANK_D->query_respect(ob1) + "了，不过你还要得到另外几位庄主的同意才行。");
			ob = new(__DIR__"obj/key2");
                	ob->move(ob1);
			ob1->set_temp("riyue/秃ok",1);
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
	if( ob->id("shuaiyi tie") ) 
	{
		message_vision("秃笔翁突然双目直瞪，呼呼喘气，颤声道：「这……这是真迹！真是……真是
唐朝……唐朝张旭的《率意帖》，假……假……假不了！」接着伸出右手食指，顺着率意帖
中的笔路一笔一划的临空钩勒，神情如醉如痴，\n",who);
		who->set_temp("riyue/给字",1);
		if ( who->query_temp("riyue/赢秃"))
		{
			command("say 这样吧，这幅字帖给了我，你进去问我几位大哥吧！");
			key = new(__DIR__"obj/key2");
			key->move(who);
			who->set_temp("riyue/秃ok",1);
		}
        else if(random(4)==1)
        {
                command("say 好吧，我便传你几招「判官笔法」做交换。");
                who->improve_skill("panguan-bifa", 4);
                who->delete_temp("riyue/给字");
        }
                call_out("destroying",0,who,ob);
		return 1;
	}
	else return 0;
}

string askren()
{
	object me = this_player();
	me->set_temp("riyue/问秃",1);
	return "东方教主让我们在这里看护，谁也不许见他。\n";
}

