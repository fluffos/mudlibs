//huangzhong.c 黄钟公
//by bing
#include "riyuenpc.h"
#include "riyuenpc2.h"

string askren();

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("黄钟公", ({ "huangzhong gong", "gong" }));
        set("title",HIC "江南四友" NOR);
        set("long","这老者六十来岁年纪，骨瘦如柴，脸上肌肉都凹了进去，直如一具骷髅，双目却炯炯有神，\n");
	set("gender", "男性");
        set("age", 64);
        set("shen_type", -1);
        set("str", 30);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        set("max_qi", 1200);
        set("max_jing", 600);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 100);
         set("combat_exp", 800000);
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

        set_skill("force", 150);
        set_skill("riyue-shengong", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
		set_skill("sword",150);
		set_skill("qixian-jian",150);
		set_skill("wuxian-jianfa",150);
        set_skill("feitian-shenfa", 150);
        set_skill("literate",170);
        map_skill("force", "riyue-shengong");
        map_skill("parry", "qixian-jian");
        map_skill("dodge", "feitian-shenfa");
        map_skill("sword","qixian-jian");
         set("chat_chance_combat", 70);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                 (: perform_action, "sword.kaishan" :),
                 (: perform_action, "sword.kaishan" :),
                 (: perform_action, "sword.kaishan" :),
                 (: perform_action, "sword.kaishan" :),
                (: perform_action, "sword.kaishan" :),
        }) );
	create_family("日月神教", 21, "弟子");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/guqin")->wield();
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
        if ( arg != "huangzhong gong" && arg != "gong" )
           {
             return 0;
            }
            ob2->set("eff_qi",ob2->query("max_qi"));
             ob2->set("qi",ob2->query("max_qi"));
             ob2->set("neili",ob2->query("max_neili"));
        if ( ob2->query_temp("busy") )
                return notify_fail("我正忙着呢。\n");
        if (!ob2 = present(arg,environment(ob1)) )
                return notify_fail("你想跟谁比划？\n");
        if (ob1 == ob2)    return notify_fail("你不能攻击自己。\n");
      if (!ob1->query_temp("riyue/问黄") || ob1->query_temp("riyue/赢黄"))
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
		ob1->set_temp("riyue/赢黄",1);
		if (ob1->query_temp("riyue/给谱"))
		{
			command("say 我就不拦" + RANK_D->query_respect(ob1) + "了，不过你还要得到另外几位庄主的同意才行。");
			ob = new(__DIR__"obj/key4");
                	ob->move(ob1);
			ob1->set_temp("riyue/黄ok",1);
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
	if( ob->id("guangling san") ) 
	{
		message_vision("黄钟公苍白的脸上竟然现出血色，显得颇为热切。欠身接过，说道：“《广陵散》绝响于
人间已久，今日得睹古人名谱，实是不胜之喜，只是……只是不知……”言下似乎是说，却又
如何得知这确是《广陵散》真谱，并非好事之徒伪造来作弄人的。他随手翻阅，说道：“唔，
曲子很长啊。”从头自第一页看起，只瞧得片刻，脸上便已变色。他右手翻阅琴谱，左手五根
手指在桌上作出挑捻按捺的抚琴姿式，赞道：“妙极！和平中正，却又清绝幽绝。”翻到
第二页，看了一会，又赞：“高量雅致，深藏玄机，便这么神游琴韵，片刻之间已然心怀
大畅。”\n",who);
		who->set_temp("riyue/给谱",1);
		if ( who->query_temp("riyue/赢黄"))
		{
              command("say 这样吧，这琴谱给了我，如果我几位兄弟都同意了，那我也就没异议了！");
			key = new(__DIR__"obj/key4");
			key->move(who);
			who->set_temp("riyue/黄ok",1);
		}
        else if(random(4)==1)
        {
                command("say 好吧，我便传你几招「五弦剑法」做交换。");
                who->improve_skill("wuxian-jianfa", 4);
                who->delete_temp("riyue/给谱");
        }

//		command("say " + RANK_D->query_respect(who) + "一番好意，老朽深实感谢。可是老朽不能白占这个便宜。咱们便来比划几招如何？");
            call_out("destroying",0,who,ob);
		return 1;
	}
	else return 0;
}

string askren()
{
	object me = this_player();
	me->set_temp("riyue/问黄",1);
	return "东方教主让我们在这里看护，谁也不许见他。\n";
}

