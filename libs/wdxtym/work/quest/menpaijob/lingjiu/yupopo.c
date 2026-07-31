// NPC yupopo.c

#include <ansi.h>
#define QUEST_KILL __DIR__"quest"  
string ask_me();
inherit NPC;
int ask_job2();
int ask_job();
int ask_fail();

void create()
{
	set_name("余婆婆", ({ "yu popo", "yu", "popo" }));
	set("long",
	    "她是「灵鹫宫」九天九部中昊天部的首领.\n"+
	    "她跟随童姥多年, 出生入死,饱经风霜.\n");
	set("title", "昊天部首领");
	set("gender", "女性");
	set("age", 60);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("max_qi", 40000);
	set("max_jing", 30000);
	set("neili", 14500);
	set("max_neili", 14500);
	set("jiali", 400);
	set("combat_exp", 2500000);
	set("score", 100);
	set("score", 100);
	set_skill("force", 300);
	set_skill("unarmed", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("hand",300);
	set_skill("strike", 300);
        set_skill("sword",300);

        set_skill("tianyu-qijian",300);
	set_skill("zhemei-shou",300);
	set_skill("liuyang-zhang",300);
	set_skill("yueying-wubu",300);
	set_skill("bahuang-gong", 300);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
   	map_skill("sword", "tianyu-qijian");
	set("inquiry", ([
                "救援" : (: ask_job() :),
                "job" : (: ask_job() :),
                "失败" : (: ask_fail() :),
                "讨贡品" : (: ask_job2() :),
                "work" : (: ask_job2() :),
                "守山门" : (: ask_me :),
                "job3" : (: ask_me :),

	]) );
        prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "sword.yushijufen" :),
                (: perform_action, "dodge.yueguangruying" :),                
        }));
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 1000);
        set_temp("apply/damage", 800);

	create_family("灵鹫宫",2,"弟子");
	setup();
        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",40);
}
void init()
{
        add_action("do_work", "shouwei");
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

        if( me->query("family/family_name") != "灵鹫宫")
           {
                      message_vision("$N对着$n说道。你是哪里来的奸细？\n", this_object(), me);
	                      return 1;
            }
      if( (int)me->query_skill("bahuang-gong",1) < 50)
            {
                message_vision("$N对着$n大喝一声：你的本门内功不够！\n", this_object(), me);
                return 1;
            }
        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：你等会再来!\n", this_object(), me);
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

        if (me->query("lingjiujob") == 1) {
                command("kick " + me->query("id"));
                command("say 我不是给了你任务了吗？");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "我派有一个女弟子遭敌围困。");
                command("say " + me->query("id") + " 她现在『" + quest["short"]             + "』的附近！\n" NOR);
                command("say " + me->query("id") + "你把她护送回这里，此事要保密行事！\n" NOR);
                me->set("lingjiujob", 1);
                me->set("quest/quest_type", "护送");
                me->set("quest/quest", "小女孩");
                me->set("task_time", time() + 300);
                me->apply_condition("menpai_busy",22);
                ob = new(__DIR__"dashi",1);
                ob->move(quest["place"]);
                ob->set("combat_exp", me->query("combat_exp"));
                return 1;
               }                              
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query("lingjiujob") == 1) {
                command("sigh");
                command("say 你保护不利,扣你150点POT.");
                me->add("potential",-50);
                me->apply_condition("menpai_busy",10);
                me->apply_condition("lingjiu_song",0);
me->delete("lingjiujob");
                return 1;
                }
}

int do_work()
{
        object me, ob, weapon,obn;
int exp,pot;
        me=this_player();

        if( me->query("family/family_name") != "灵鹫宫")
                return notify_fail("这个事不能由外人做!");

if (me->query("qi") <30)
                return notify_fail("你的气不够了。");
if (me->query("jing") <30)
                return notify_fail("你的精不够了。");
        if (!me->query_temp("player_working"))
                return notify_fail("你想做什么。");

        if (me->query_temp("player_working")) {
                if (me->is_busy())
                        return notify_fail("你正忙着呢。\n");

                tell_object(me, HIG"你和余婆婆威风的在灵鹫山走了一圈。\n"NOR);

                        message_vision(HIW"山风好大啊,$N觉得有点冷，打了一个喷涕。\n"NOR, me);
                        me->add("jing",-20);
                        me->add("qi", -10);
                        me->set_temp("working_times",me->query_temp("working_times")+1);
                        me->start_busy(1);

                if (me->query_temp("working_times")>=me->query_temp("player_working"))
                {
                        message_vision(HIW"余婆婆对$N说：“有人来换班了，你先去休息一下吧。\n"NOR, me);
                        me->delete_temp("working_times");
                        me->delete_temp("player_working");
exp=random(20)+12;
pot=random(10)+10;
                        me->add("combat_exp", exp);
                        me->add("potential", pot);
             tell_object(me,HIW"你被奖励了：" + chinese_number(exp)
               + "点实战修为，"+ chinese_number(pot) + "点潜能。\n"NOR);
                        me->start_busy(6);
                }
                return 1;
        }
        return 1;
}
string ask_me()
{
        object me;
        me=this_player();

        if( me->query("family/family_name") != "灵鹫宫")
                return "这个事不能由外人做!";

        if (me->query_temp("player_working"))
                return "你不是和我正在守山门吗。";

                if (me->is_busy())
                        return "你正忙着呢。";

        me->set_temp("player_working",random(20)+10);
        me->set_temp("working_times",0);
        return "好你就和我一起守山门(shouwei)吧。";
}
int ask_job2()
{
        mapping quest ;
        object me,obn;
        int combatexp, timep;
        string room;
        me = this_player();
        if( me->query("family/family_name") != "灵鹫宫")
           {
                      message_vision("$N对着$n说道。你是哪里来的奸细？\n", this_object(), me);
	                      return 1;
            }

        if (me->query_temp("ljjob2"))  
            {
                      message_vision("$N对着$n说:我不是给过你任务了吗?\n", this_object(), me);
                      return 1;
            }

        if ((int)me->query_condition("ljjob2"))  
            {
                      message_vision("$N对着$n摇了摇头说：你刚刚要过任务，等会现来!\n", this_object(), me);
                      return 1;
            }
if ((int)me->query_condition("guojob2_busy"))
           {
                      message_vision("$N对着$n说:现在没有任务,你等会再来吧!\n", this_object(), me);
                      return 1;
            }  
        quest = QUEST_KILL->query_quest();
             tell_object(me,HIM" "+quest["quest"]+HIC"搞了一些贡品要献给童姥，你去收(shougongpin)一下!\n" NOR);

        me->set_temp("ljjob2", quest["quest"]);
          me->apply_condition("ljjob2",4);
          obn=new(__DIR__"ling");
          obn->set("usename",me->query("name"));
          obn->move(me);

        return 1;
}
int accept_object(object who, object ob)
{
        int bonus, exp, pot, score;
        string test;
        mapping quest;
object obj,me;
int maxpot;
me=who;

        if (me->is_busy())
        {
          tell_object(me,"你正忙着呢！\n");
          return 0;
        }
	if( me->is_fighting() )
        {
          tell_object(me,"等打完了，再说吧，！\n");
          return 0;
        }

        if( who->query("family/family_name") != "灵鹫宫")
           {
                      message_vision("$N对着$n说道。你是哪里来的奸细？\n", this_object(), who);
	                      return 0;
            }

        if(!who->query_temp("ljjob2"))
        {
             tell_object(who,"我没有叫你去做什么事啊。\n");
             return 0;
        }

	if( userp(ob) ) {
        tell_object(who,"这是什么？我不是要你去要贡品吗！\n");
        return 0;
        }

	if( ob->query("id")=="gong pin" &&
	ob->query("ljby")!=who->query("name")) {
        tell_object(who,"这不是我要你要的贡品！\n");
        return 0;
        }

	if( ob->query("id")!="gong pin" ) {
        tell_object(who,"这是什么？我不是要你去要贡品吗！\n");
        return 0;
        }


if ( random(30)==1 && me->query("combat_exp") > 1000000
&& !environment(me)->query("no_fight"))
{
tell_object(who,HIR"谁知话刚说完...\n"NOR);
obj=new(__DIR__"menggu"); 
obj->move(environment(me));
obj->do_copy(me,maxpot,2);
obj->set("title",HIR"七十二洞弟子"NOR);
obj->set("usename",me->query("name"));
me->start_busy(1);
message_vision(HIR"突然附近，闪出一人！\n"NOR, obj);
message_vision(HIR"$N说道：我是七十二洞的，快把生死符解药交出来！\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
me->start_busy(2);
return 0;
}

if (ob->query("id")=="gong pin" &&
	ob->query("ljby")==who->query("name")) 
{
             tell_object(who,HIW"幸苦你了。\n"NOR);

             exp = 80 + random(80);
             pot = 60 + random(50);
             score = 3 + random(5);

             bonus = (int) who->query("combat_exp");
             bonus += exp;
             who->set("combat_exp", bonus);
             bonus = (int) who->query("potential");
             bonus = bonus - (int) who->query("learned_points");
             bonus = bonus + pot;
             bonus += (int) who->query("learned_points");
             who->set("potential", bonus );
             bonus = (int) who->query("score");
             bonus += score;
             who->set("score", bonus);
             tell_object(who,HIW"你做得不错，童姥知道会高兴的！\n"NOR);
             tell_object(who,HIW"你被奖励了：" + chinese_number(exp)
               + "点实战修为，\n"+ chinese_number(pot) + "点潜能，\n"
               + chinese_number(score)+"点江湖阅历。\n"NOR);
             who->delete_temp("ljjob2");
who->start_busy(2);
       call_out("destroying", 0,ob);                              
return 1;
}
else return 0;
}
void destroying(object ob)
{   
   destruct(ob);
}
