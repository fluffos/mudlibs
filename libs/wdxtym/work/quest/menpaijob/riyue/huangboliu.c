// huangboliu.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

#include <ansi.h>;
int do_gongzuo();
int ask_done();
mapping *changxi = ({ 
         ([ "changxi":"白驼","where":"baituo"   ]),
         ([ "changxi":"娥眉","where":"emei"  ]),
         ([ "changxi":"恒山","where":"hengshan"   ]),   
         ([ "changxi":"古墓","where":"gumu" ]),   
         ([ "changxi":"衡山","where":"henshan"]),   
         ([ "changxi":"华山","where":"xx"]),   
         ([ "changxi":"灵鹫","where":"lingjiu"]),   
         ([ "changxi":"明教","where":"mingjiao"]),   
         ([ "changxi":"全真","where":"quanzhen"]),   
         ([ "changxi":"少林","where":"shaolin"]),   
         ([ "changxi":"天龙寺","where":"tianlongsi"]),   
         ([ "changxi":"武当","where":"wudang"]),   
         ([ "changxi":"逍遥","where":"xiaoyao"]),   
         ([ "changxi":"星宿海","where":"xingxiuhai"]),   
         ([ "changxi":"泰山","where":"taishan"]),   
         ([ "changxi":"雪山寺","where":"xueshan"]),   
         ([ "changxi":"慕容世家","where":"mr"]),   
         ([ "changxi":"铁掌门","where":"tiezhang"]),            
         ([ "changxi":"凌宵城","where":"lingxiao"]),            
         ([ "changxi":"昆仑山","where":"kunlun"]),            
         ([ "changxi":"五毒教","where":"wudujiao"]),            
                   });
mapping query_changxi()
{
        return changxi[random(sizeof(changxi))];
}

void create()
{
	set_name("黄伯流", ({ "huang boliu","huang","boliu"}) );
	set("gender", "男性" );
	set("title", HIB"日月神教风雷堂香主"NOR);
	set("nickname", HIW"银髯蛟"NOR);
	set("age", 85);
	set("long", "一部白须，直垂至胸，身材魁梧之极。\n");
	set("attitude", "friendly");
	set("shen_type", 1);

	set("per", 21);
	set("str", 53);
	set("int", 53);
	set("con", 52);
	set("dex", 50);

	set("max_qi", 10000);
	set("max_jing",10000);
	set("neili", 50000);
	set("max_neili", 50000);
	set("combat_exp", 2000000);
	set("jiali", 100);
	set("score", 30000);

          set_skill("sword", 200);
          set_skill("parry", 200);
        set_skill("literate",200);
          set_skill("dodge", 200);
          set_skill("unarmed", 200);
          set_skill("whip", 200);
          set_skill("force", 200);
        set_skill("staff", 200);
          set_skill("strike",200);
         set_skill("blade", 200);

         set_skill("tmjian", 200);
         set_skill("tmzhang", 200);
         set_skill("tmdao", 250);
         set_skill("pmshenfa", 200);
         set_skill("tmdafa", 200);

        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.moxiao" :),
                (: perform_action, "blade.moxiao" :),
                (: perform_action, "unarmed.huashen" :),                
                (: perform_action, "unarmed.tmduan" :),                
        }) );

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 800);
        set_temp("apply/damage", 800);
        set("inquiry", ([
                "游说工作" : (: do_gongzuo :),
                "work"  : (: do_gongzuo :),
                "done" : (: ask_done    :),
                "完成" : (: ask_done    :),
                "奖励" : (: ask_done    :),
	]) );

	create_family("日月神教",2,"弟子 风雷堂香主");

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
         if (ob->query_int() < 20) {
              command("say " + RANK_D->query_respect(ob) +
                        "走开走开，我不想和傻瓜说话。");
                return;
        }
         if (ob->query_dex() < 20) {
                command("say " + RANK_D->query_respect(ob) +
                        "身手不捷，还是另求高师吧。");
                return;
        }
        if ((int)ob->query("shen") > -10000) {
                command("say " + RANK_D->query_respect(ob) +
                        "你还不够心狠手辣，我还不能收你。");
                return;
        }
        command("say 哈哈！ 那我就收下你吧。");
        command("recruit " + ob->query("id"));
}


int do_gongzuo()
{      
        mapping changxi,changxiwhere;
        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("ryjob2/changxi")>0)
    {
                tell_object(me,HIW"你快去光大圣教吧！\n"NOR);
                return 1;
    } 
        if ((int)me->query_condition("ry2_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：你刚要过任务,等会再来!\n", this_object(), me);
                      return 1;
            }

        if( me->query("family/family_name") != "日月神教")
           {
                      message_vision("$N对着$n说道。你是哪里来的奸细？\n", this_object(), me);
                      return 1;
            }

    changxi = this_object()->query_changxi();
    changxiwhere = changxi["where"];
    message_vision(HIC"黄伯流对$N说道：你去" + changxi["changxi"] + "去光大我圣教，扬我圣教之威！\n"NOR,me); 
        me->set_temp("ryjob2/changxi", 1);
        me->set_temp("ryjob2/where",changxiwhere);
        me->set_temp("ryjob2/cx",changxi["changxi"]);

me->apply_condition("ry2_busy", 2);
        ob=new(__DIR__ "ling");
        ob->move(me);
    message_vision(HIC"黄伯流对$N说道：这些传单你拿去做游说(youshuo)用吧。\n"NOR,me); 
        return 1;   
}

int ask_done()
{      

        object me,ob;
int exp,pot;
exp=80+random(60);
pot=60+random(45);

        me = this_player(); 
        
        if( me->query("family/family_name") != "日月神教")
           {
                      message_vision("$N对着$n说道。你是哪里来的奸细？\n", this_object(), me);
                      return 1;
            }
  
    if( me->query_temp("ryjob2/changxi")< 1)
    {
                tell_object(me,CYN"你没事做吗？。\n"NOR);
                return 1;
    } 

    if( me->query_temp("ryjob2/done")< 1)
    {
                tell_object(me,HIW"我听说好像游说的目的还没有达到？快去游说吧。\n"NOR);
                return 1;
    }
    message_vision(HIG"黄伯流对$N说道：做得不错！光大了我圣教。\n"NOR,me); 
    me->add("combat_exp",exp);
    me->add("potential",pot);
        me->delete_temp("ryjob");
    me->delete_temp("ryjob2");
	   tell_object(me,HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战修为\n" +
                       chinese_number(pot) + "点潜能\n"+
                       NOR);

    return 1;
}