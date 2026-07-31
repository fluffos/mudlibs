// qiu.c 丘处机
// By Lgg,1998.10

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "teamjob.c"
string ask_job();
void reward_dest(object obj,object ob);
void thank_dest(object obj,object ob);

void create()
{
        set_name("丘处机", ({"qiu chuji", "qiu"}));
        set("gender", "男性");
        set("age", 36);
        set("class", "taoist");
        set("nickname",HIM"长春子"NOR);
        set("long",
                "他就是江湖上人称‘长春子’的丘处机丘真人，他方面大耳，\n"
                "满面红光，剑目圆睁，双眉如刀，相貌威严，平生疾恶如仇。\n");
        set("attitude", "heroism");
        set("shen_type",1);
        set("str", 52);
        set("int", 50);
        set("con", 50);
        set("dex", 50);

        set("title","全真七子之四");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.jianqi" :),
                (: perform_action, "sword.qixing" :),
                (: perform_action, "sword.qixinggongyue" :),
                (: perform_action, "sword.sanqing" :),

        }));

        set("qi", 18000);
        set("max_qi", 18000);
        set("jing", 33600);
        set("max_jing",33600);
        set("neili", 46000);
        set("max_neili", 46000);
        set("jiali", 100);

        set("combat_exp", 6500000);
        set("score", 300000);

        set_skill("force", 200);
        set_skill("xiantian-qigong", 350);    //先天气功
        set_skill("sword", 200);
set_skill("qixing-jian",280);
set_skill("qixing-shou",280);
set_skill("qixing-array",280);
        set_skill("quanzhen-jian",250);  //全真剑
        set_skill("dodge", 250);
        set_skill("jinyan-gong", 300);   //金雁功
        set_skill("parry", 200);
        set_skill("haotian-zhang", 250);    //昊天掌
        set_skill("literate",200);
        set_skill("strike",200);
        set_skill("taoism",250);
set_skill("hand", 250);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");
	set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 250);

        create_family("全真教", 2, "弟子");

        set("book_count",1);
        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",
		 "job"  : (: ask_jianxi :),
		"采药" : (: ask_job :),
		"yaojob" : (: ask_job :),
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("d/quanzhen/npc/obj/grayrobe")->wear();

}

void init()
{
        ::init();
        remove_call_out("greeting");
        call_out("greeting", 1, this_player());
}


void greeting(object ob)
{
        mapping fam;
        int i;
        object me;

        me = this_object();
if (!ob) return;
        if (interactive(ob) && !environment(ob)->query("no_fight"))
        {
             if (!(fam = ob->query("family")) || fam["family_name"] != "全真教")
 {
                if (ob->query("shen")>-5000) {
                        command("say 这里是本教重地，你走动小心些。");
                }
                else {
                        command("say 你这魔头，竟敢闯入我全真重地，我一定要杀了你！");
                        me->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                }
             }
             else {
                command("smile "+ob->query("id"));
             }
        }
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_skill("xiantian-qigong",1) < 50 ) {
                command("say 你的本门内功心法火候不足,难以领略更高深的武功。");
                return;
        }
        if ((int)ob->query("shen")<5000) {
                command("say 行侠仗义是我辈学武人的基本品质，你若能多做些狭义之
事，我一定收你为徒。\n");
                return;
        }
        command("say 好吧，我就收下你这个徒弟了。");
        command("recruit " + ob->query("id"));
}

string ask_job()
{
	  mapping job_stat;
	  object ob2;
	  object ob = this_player();
	  object me = this_object();

	  job_stat = ob->query_temp("qz_caiyao");

   if(this_object()->is_busy())
{
message_vision("丘处机对$N说道：“我正忙着呢！”\n",me);
				return "等会！\n";
}

	  if ( ob->query("family/family_name") != "全真教" )
					 return "这位"+RANK_D->query_respect(ob)+"非我全真教弟子，岂敢劳烦。\n";

	  if(job_stat){
				command("hammer "+ob->query("id"));
				return "你还没完成任务，就又想要新的？\n";
	  }



	  command("nod");
	  command("say 好，最近炼丹用的草药都用完了，你去山下树林里去采一些回来。");
	  ob2 = new(__DIR__"obj/yaochu");
	  ob2->move(me);
	  ob->set_temp("qz_caiyao",1);
          ob->set_temp("qz/caiyao",1);
	  command("give yao chu to "+ob->query("id"));

	  return "早去早回，路上要小心一些！\n";
}

int accept_object(object me, object obj)
{
		  object ob = this_player();

		  command( "say "+obj->name()+"?");

   if(this_object()->is_busy())
{
message_vision("丘处机对$N说道：“我正忙着呢！”\n",me);
return 0;
}

if (userp(obj) )
{
		  command( "say 你给我这东西做什麽？" );
		  return 0;
}
if( obj->query("ownmake") )
{
		  command( "say 你给我这东西做什麽？" );
		  return 0;
}

        if( !obj->query("yaocai") )
{
		  command( "say 你给我这东西做什麽？" );
		  return 0;
}
        if( obj->query_temp("byname")!=me->query("id") )
{
		  command( "say 这个不是你找到的吧，我要你找的!" );
		  return 0;
}
		  if (
				 obj->query("id") == "chuanbei" ||
				 obj->query("id") == "fuling" ||
				 obj->query("id") == "gouzhi zi" ||
				 obj->query("id") == "heshouwu" ||
				 obj->query("id") == "huanglian" ||
				 obj->query("id") == "jugeng" ||
				 obj->query("id") == "jinyin hua" ||
				 obj->query("id") == "shengdi"
			)
			{

			  if ( ob->query("family/family_name") == "全真教" ) {
this_object()->start_busy(2);
					 remove_call_out("reward_dest");
					 call_out("reward_dest", 0, obj, ob);
			  }
			  else {
this_object()->start_busy(2);
					 remove_call_out("thank_dest");
					 call_out("thank_dest", 0, obj, ob);
			  }

			  return 1;
		  }

		  command( "hmm" );
		  command( "say 你给我这东西做什麽？" );

		  return 0;
}

void reward_dest(object obj,object ob)
{
		  int exp;
	object yaochu = present("yao chu",this_player() );
   if(yaochu)destruct(yaochu);
	command( "pat "+ob->query("id"));
	command( "say "+ob->query("name")+"干的不错，下去休息一下吧！\n");
	if(ob->query_temp("qz_caiyao",1) )
	{
		ob->delete_temp("qz_caiyao");
		ob->delete_temp("qz/caiyao");
		exp = 80+random(80);
		ob->add("combat_exp",exp);
		ob->add("potential",exp*2/3);
		ob->add("herb/times",1);
              message_vision( "\n$N获得了：\n"
                + chinese_number(exp ) + "点实战修为，\n"
                + chinese_number(exp*2/3) + "点潜能，\n" NOR, ob);
	}
	destruct(obj);
}


void thank_dest(object obj,object ob)
{
	command( "jump");
	command( "say 我们很需要这些药材，多谢啦！\n");
	destruct(obj);
}

