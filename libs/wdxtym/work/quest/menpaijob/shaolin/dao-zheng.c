// Npc: /kungfu/class/shaolin/dao-zheng.c
// Date: YZC 96/01/19
#include <ansi.h>
inherit NPC;
int ask_job2();
int ask_job();
int ask_fail();
int ask_fail2();
mixed names = ({
        ({
        "少林弹腿","韦驮掌","波罗蜜手","摩诃指","寂灭爪",
        "大金刚神掌","多罗叶指","少林身法","韦驮棍","达摩剑",
       "醉棍","无常杖","普渡杖","修罗刀","慈悲刀",                
        "大金刚拳","拈花指","一指禅","鹰爪功","龙爪功", 
        "风云手","如来千叶手","般若掌","散花掌","罗汉拳",
        }),
        ({
         "澄志","澄观","澄和","澄寂","澄坚","澄净","澄灵","澄灭","澄明",
	"澄尚","澄识","澄思","澄心","澄信","澄行","澄意","澄欲",
	 "澄知","道一禅师","道象禅师","道相禅师","道品禅师","道觉禅师","道果禅师","道成禅师",
	 "道尘禅师","慧合尊者","慧真尊者","慧洁尊者","慧空尊者","慧名尊者","慧如尊者","慧色尊者",
	 "慧修尊者","慧虚尊者","清法比丘","澄坚","清观比丘","清乐比丘","清善比丘","清为比丘",
	 "清闻比丘","清无比丘","清晓比丘","道象禅师","澄灵","澄明","道尘禅师",
        }),
        });
void create()
{
	set_name("道正禅师", ({
		"daozheng chanshi",
		"daozheng",
		"chanshi",
	}));
	set("long",
		"他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵\n"
		"刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 40000);
	set("max_jing", 30000);
	set("neili", 14500);
	set("max_neili", 14500);
	set("jiali", 400);
	set("combat_exp", 8000000);
	set("score", 100);

	set_skill("force", 350);
	set_skill("hunyuan-yiqi", 350);
	set_skill("dodge", 350);
	set_skill("shaolin-shenfa", 350);
	set_skill("strike", 350);
	set_skill("sanhua-zhang", 350);
	set_skill("parry", 350);
	set_skill("damo-jian", 350);
	set_skill("buddhism", 350);
	set_skill("literate", 350);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "sanhua-zhang");
	map_skill("parry", "sanhua-zhang");
	set("inquiry", ([
                "武僧堂" : (: ask_job2() :),
                "wsjob" : (: ask_job2() :),
                "救援" : (: ask_job() :),
                "job" : (: ask_job() :),
                "fail" : (: ask_fail() :),
                "失败" : (: ask_fail() :),
                "不做武僧了" : (: ask_fail2() :),
                "wsfail" : (: ask_fail2() :),
	]) );
	create_family("少林派", 39, "弟子");

	setup();

        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}

int ask_job()
{

        object me = this_player();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        quest = (__DIR__"lagjob")->query_quest();

        skl = me->query_skills();
        if ( !skl ) {
                tell_object(me, "你去学一些本事先吧！\n");
                return 1;
                }
        sname  = sort_array( keys(skl), (: strcmp :) );
        for(i=0; i<sizeof(skl); i++) 
                if (skl[sname[i]] >= skill && sname[i] != "literate" && sname[i] != "taoism")

                        skill = skl[sname[i]];
                        
        if (skill < 80) skill = 80;

        if( me->query("family/family_name") != "少林派" && me->query("family/family_name") != "南少林派")
           {
                      message_vision("$N对着$n说道。你是哪里来的奸细？\n", this_object(), me);
                      return 1;
            }

        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：你等会再来!\n", this_object(), me);
                      return 1;
            }
      if( (int)me->query_skill("yijinjing",1) < 50)
            {
                message_vision("$N对着$n大喝一声：你的本门内功不够！\n", this_object(), me);
                return 1;
            }

           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "你还是练高修为再来吧");
                return 1;
}
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say 你的潜能太少了!!");
                return 1;
        }

        if (me->query("shaolinjob") == 1) {
                command("kick " + me->query("id"));
                command("say 我不是给了你任务了吗？");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "我派玄难大师遭敌围困。");
                command("say " + me->query("id") + " 玄难大师现在『" + quest["short"]             + "』的附近！\n" NOR);
                command("say " + me->query("id") + "你把玄难大师大师护送回少林！\n" NOR);
                me->set("shaolinjob", 1);
                me->apply_condition("menpai_busy",22);
                me->set("quest/quest_type", "护送");
                me->set("quest/quest", "玄难大师");
                me->set("task_time", time() + 300);
                ob = new(__DIR__"dashi",1);
                ob->move(quest["place"]);
                ob->set("combat_exp", me->query("combat_exp"));
                return 1;
               }                              
}

int ask_job2()
{

        object me = this_player();
        object ob;
string skl,tar;

        skl = me->query_skills();

        if( me->query("family/family_name") != "少林派"  && me->query("family/family_name") != "南少林派")
           {
                      message_vision("$N对着$n说道。你是哪里来的奸细？\n", this_object(), me);
                      return 1;
            }

        if ( !skl ) {
                tell_object(me, "你去学一些本事先吧！\n");
                return 1;
                }

        if ((int)me->query_condition("slwsd_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：你刚要过任务,等会再来!\n", this_object(), me);
                      return 1;
            }
if ((int)me->query_condition("guojob2_busy"))
           {
                      message_vision("$N对着$n说:现在没有任务,你等会再来吧!\n", this_object(), me);
                      return 1;
            }  
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say 你的潜能太少了!!");
                return 1;
        }
      if( (int)me->query_skill("yijinjing",1) < 10)
            {
                message_vision("$N对着$n大喝一声：你的本门内功不够！\n", this_object(), me);
                return 1;
            }
        if (me->query_temp("wsdjob")) {
                command("kick " + me->query("id"));
                command("say 我不是给了你任务了吗？");
                return 1;
                }
        else {

tar = names[1][random(sizeof(names[1]))];
skl = names[0][random(sizeof(names[0]))];        
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "我派武功繁多，需要武僧帮助钻研。");
                command("say " + me->query("id") + " 你去和『" + tar  + "』一起钻研一下『" + skl  + "』吧！\n" NOR);
                me->set_temp("wsdjob", tar);
                me->set_temp("wsdskl", skl);
                ob = new(__DIR__"ling");
                ob->set("usename",me->query("name"));
                ob->move(me);
                command("say " + me->query("id") + "这个武僧令，你拿好，凭这个去帮助弟子们钻研吧！\n" NOR);
                return 1;
               }                              
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query("shaolinjob") == 1) {
                command("sigh");
                command("say 你保护不利,扣你150点POT.");
                me->add("potential",-50);
                me->apply_condition("shaolin_song",0);
                me->apply_condition("menpai_busy",10);
me->delete("shaolinjob");
                return 1;
                }
}

int ask_fail2()
{
        object me = this_player();
        
        if (me->query_temp("wsdjob")) {
                command("sigh");
                command("say 这么点事，你都做不好，也罢，你去吧.");
                me->apply_condition("slwsd_busy", 5 +
                        (int)me->query_condition("slwsd_busy"));

//                me->apply_condition("slwsd_busy",6);
me->delete_temp("wsdjob");
me->delete_temp("wsdskl");
me->delete_temp("wsjob");
                return 1;
                }
}

