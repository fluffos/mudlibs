// chen.c 陈家洛 by hubo

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;
int ask_job();
int ask_fail();

void create()
{
	set_name("陈家洛", ({ "chen jialuo", "chen","jialuo" }));
	set("title", HIR "红花会"HIG"总舵主" NOR);
	set("long", 
"他一副模样直是个富贵人家的纨裤子弟，丰姿如玉，目朗似星，轻
袍缓带，手中摇着一柄折扇，神采飞扬，气度闲雅，吐属斯文。服
饰俨然是个贵介公子。\n");
	set("nickname", HIY"玉面神龙"NOR);
	set("gender", "男性");
	set("class", "scholar");
	set("age", 22);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 30);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 4000);
	set("max_jing", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("combat_exp", 20000000);
	set("score", 500000);

	set_skill("literate", 300);
	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("cuff", 400);
	set_skill("bingchuan-xinfa", 400);
	set_skill("zhuangzi-mengwu", 400);
//	set_skill("baihua-cuoquan", 400);

	map_skill("dodge", "zhuangzi-mengwu");
	map_skill("force", "bingchuan-xinfa");
//	map_skill("cuff", "baihua-cuoquan");
// 	map_skill("parry", "baihua-cuoquan");

	prepare_skill("cuff","baihua-cuoquan");
	set("env/wimpy", 60);
	create_family("红花会", 3, "弟子");
	 set("inquiry", ([
/*
                "job" : (: ask_job() :),
                "失败" : (: ask_fail() :),
*/
	]) );

 	setup();
	carry_object("/clone/misc/cloth")->wear();

}

void init()
{
        add_action("do_baoxin", "baoxin");
        add_action("do_jiuren", "jiuren");
}

int do_baoxin()
{
        object me = this_player();
        
        if (me->query_temp("hhh_wt1") != 2)
        	return 0;
        
        if (me->query_temp("hhh_wt1") == 2)
        	write(HIW"你向陈家洛详细的讲述了发现文泰来行踪的消息。\n"NOR);
        	write(HIW"陈家洛说道：本派正在为文四当家的事发愁呢。多亏大侠为本派送信。可提督府怎么进去呢？\n"NOR);
        	write(HIW"说完陈家洛眉头紧皱，一言不发。\n"NOR);
        	me->set_temp("hhh_wt1",3);
        	
          return 1;
      	
}

int do_jiuren()
{
        object me = this_player();
        
        if (me->query_temp("hhh_wt1") != 3)
        	return 0;
        	
         if(me->query("combat_exp") < 1000000)
        {
                command("haha");
                command("say 我真不希望你去送死。");
                return 1;
        }
                  
        if (me->query_temp("hhh_wt1") == 3)
        	write(HIY"你向陈家洛大声说：总舵主不必发愁，在下不才，可救文四当家的出来！\n"NOR);
        	write(HIY"陈家洛大喜道：有大侠肯帮忙，何事不愁，大侠可去提督府门前的炮仗店，\n"NOR);
        	write(HIY"那里有本帮弟兄接应。事成之后，必有重谢！！\n"NOR);
        	me->set_temp("hhh_wt1",4);
        	
          return 1;
      	
}

void attempt_apprentice(object ob)
{
         if ((string)ob->query("family/family_name")!="红花会" )
        {
         command("say 我不收外派弟子。");
         command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜马善均。");
                return;
        }if ((int)ob->query("shen") < 100000) {
                command("say 红花会所作所为都是扶危济困。");
                command("say " + RANK_D->query_respect(ob) + "若能做出" +
                        "几件侠义之事，本座一定收你。");
                return;
        }
        if ((int)ob->query("score")<1700){
            command("sigh"+ob->query("id"));
            command("say 你若为本门立点功劳,本座一定收你");
            return;      
            }
        if ((int)ob->query_skill("bingchuan-xinfa", 1) < 50) {
          command("say 你的冰川心法太低了，无法修习我的功夫。");
          command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在冰川心法上多下点功夫？");
                return;
        }
        if((int)ob->query("betrayer")>=1)
        {
      command("say "+RANK_D->query_respect(ob)+"多次背信弃义，我怎可收你。");
                return;
        }
      command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
      command("recruit "+ob->query("id"));
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
          ob->set("title",HIR "红花会" NOR + HIY +"分舵舵主" NOR);
//title系统记录玩家title by seagate@pkuxkx
	        ob->set_title(TITLE_RANK, HIR "红花会" NOR + HIY +"分舵舵主" NOR);
        }
        return;
}
void re_rank(object student)
{
        student->set("title",HIR "红花会" NOR + HIY +"分舵舵主" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      student->set_title(TITLE_RANK, HIR "红花会" NOR + HIY +"分舵舵主" NOR);
        return;
}

void heal()
{
        object ob=this_object();
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

int ask_job()
{

        object me = this_player();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        quest = ("/d/hangzhou/npc/job/lagjob")->query_quest();

        skl = me->query_skills();
        if ( !skl ) 
        	      {
                   tell_object(me, "你去学一些本事先吧！\n");
                   return 1;
                }
        sname  = sort_array( keys(skl), (: strcmp :) );
        for(i=0; i<sizeof(skl); i++) 
                if (skl[sname[i]] >= skill && sname[i] != "literate" && sname[i] != "taoism")

                        skill = skl[sname[i]];
                        
        if (skill < 80) skill = 80;

        if (me->query("combat_exp") < 1000000) 
        	{
                command("say " + RANK_D->query_respect(me) + "救反清义士的事没那么容易，你还是练高经验再来吧");
                return 1;
          }
        
        if (me->query("combat_exp") > 50000000) 
        	{
                command("say " + RANK_D->query_respect(me) + "怎敢麻烦您呢，你老已经是准变态牛人了。");
                return 1;
          }
          
        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：哪有那么多任务做，等会再来!\n", this_object(), me);
                      return 1;
            }
        if (me->query("potential") < 2000 || me->query("combat_exp") < 3000) 
        	{
                command("say 你的潜能经验太少了!!");
                return 1;
          }

        if (me->query("hhh_kill") == 1) 
        	{
                command("kick " + me->query("id"));
                command("say 我不是给了你任务了吗？");
                return 1;
          }
        else 
        	{
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "反清复明，就要坚贞志士，你去吧!");
                command("say " + me->query("id") + " 有一个反清义士被抓了，要送往京城，要在『" + quest["short"]             + "』路过，快去救人吧！\n" NOR);
                me->set("hhh_kill", 1);
                me->set("hhh/quest_type", "救");
                me->set("hhh/quest", "反清义士");
                me->set("hhh/task_time", time() + 500);
                me->delete("hhh/killer");
                ob = new("/d/hangzhou/npc/job/shangdui",1);
                ob->move(quest["place"]);
                ob->set_temp("owner/id",me->query("id"));                 
                return 1;
           }                              
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query("hhh_kill") == 1) 
        	{
                command("sigh");
                command("say 我看错你了，我只能派别人去救反清义士,扣你1000点经验.");
                me->add("combat_exp",-50);
                me->apply_condition("menpai_busy",300);
                me->delete("hhh_kill");
                return 1;
          }
}

