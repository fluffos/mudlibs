//long.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_me();
int ask_zhou();
void create()
{
        set_name("龙亦凡", ({ "long", "dragon" }));
        set("long", "他就是天下闻之色变的侠客岛岛主，号称“不死神龙”。\n"
                   +"他须眉全白，脸色红润，有如孩童。看不出他的实际年纪。\n"
                   );
        set("title", "侠客岛主");
        set("gender", "男性");
        set("age", 75);
        set("nickname", HIR "不死神龙" NOR);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 60);
        set("int", 69);
        set("con", 60);
        set("dex", 68);

        set("qi", 53900);
        set("max_qi", 53900);
        set("jing", 53900);
        set("max_jing", 53900);
        set("neili", 61500);
        set("max_neili", 61500);
        set("jiali", 50);

        set("combat_exp", 8500000);
        set("score", 200000);
        set_skill("force", 370);
        set_skill("unarmed", 300);
        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("hand",370);
        set_skill("staff", 370);
        set_skill("taixuan-gong", 350);
set_skill("huanhe-dao", 350);
set_skill("sata-shenfa", 350);
set_skill("sumi-jian", 380);
set_skill("wuyu-quan", 350);
set_skill("xiuli-qiankun", 350);
set_skill("strike", 250);
set_skill("cuff", 250);
set_skill("unarmed", 250);
set_skill("blade", 350);
set_skill("sword", 350);
set_skill("club", 380);
set_skill("bawang-qiang", 380);
map_skill("sword", "sumi-jian");
//map_skill("blade", "huanhe-dao");
map_skill("strike", "xiuli-qiankun");
map_skill("cuff", "wuyu-quan");
      map_skill("force", "taixuan-gong");
        map_skill("dodge", "sata-shenfa");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
set_skill("club", 380);
set_skill("bawang-qiang", 380);

    	prepare_skill("strike", "xiuli-qiankun");
	prepare_skill("cuff", "wuyu-quan");

        
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "sword.dieying" :),
                (: perform_action, "sword.feiwu" :),
                (: perform_action, "sword.jiushi" :),
                (: perform_action, "sword.jiushi" :),                	
                (: perform_action, "sword.ruhe" :),
                (: perform_action, "sword.shenfeng" :),                	
                (: perform_action, "sword.wuyun" :),                	                	                	                	
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
                
        }) );


	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 600);
        create_family("侠客岛",1, "岛主");
        set("inquiry", ([
            "腊八粥" : (: ask_zhou :),
            "侠客岛" :  "\n这个岛是我和木兄弟无意中发现的。\n",
        "挑战" : (: ask_me :),
        ]));
        set("chat_msg", ({
"龙岛主忽然一怕脑袋，说：腊八粥可是好东西哇！\n",
"龙岛主说道：怎么这么多的英雄也不能领悟太玄经呢。\n",
        }) );

        setup();
        carry_object(__DIR__"mujian")->wield();
        add_money("gold",5);
}

void attempt_apprentice(object ob)
{
  if((int)ob->query_skill("taixuan-gong",1)<100)
        {
          message_vision("龙岛主拍拍$N的头，微微摇了摇头。\n",ob);
	return ;
         }

        message_vision("龙岛主拍拍$N的头，微微点了点头。\n",ob);
        command("recruit " + ob->query("id"));
        return;
}


void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( ob->query("combat_exp")< 10000)
              say ("龙岛主抬头望了你一眼，说道：经验尚浅。\n");
        return;
}

int ask_zhou()
{
        say("\n龙岛主对你说：这是本岛特有的东西，它主要由一味'断肠独骨腐心草'构成，\n"
"要开花后效力方著，但这种草每十年才开一次花，所以腊八粥很名贵，\n"
"一般人很难得到的，小兄弟想要就要看你的缘分了！\n");
        return 1;
}

int accept_object(object who, object ob)
{
        object obn;

        if (  ob->query("id") != "shane bu" && ob->query("id") != "fuxin cao")
        {
                message_vision("\n龙岛主摇头道：这不是我想要的呀！\n",who);
                return 0;
        }
        if ( ob->query("id") == "shane bu" )
        {
                if (random((int)who->query("kar")) <=25 )
                {
                        message_vision("龙岛主摇头道：我看小兄弟今生于此无缘。\n",who);
                        return 1;
                }
                else
                {
                        remove_call_out("destroy");
                        call_out("destroy", 1, who, ob);

                        if(query_temp("cao"))
                        {
                                message_vision("\n龙岛主见是赏善罚恶簿，大喜道：恭喜这位小兄弟了!\n",who);
                                obn=new("/d/xiakedao/obj/zhou");
                                obn->move(who);
                                delete_temp("bu");
                                delete_temp("cao");
                                return 1;
                        }
                        else if(query_temp("bu"))
                        {
                                message_vision("\n龙岛主见是赏善罚恶簿，对$N摇头道：赏善罚恶簿我有了。\n",who);
                                return 0;
                        }
                        else
                        {
                                message("vision","龙岛主看见赏善罚恶簿，大喜道：现在只差腐心草了。\n",environment(who));
                                set_temp("bu",1);
                                return 1;
                        }
                }
        }
        if ( ob->query("id") == "fuxin cao")
        {
                if (random((int)who->query("kar")) <=25 )
                {
                        message_vision("龙岛主摇头道：我看小兄弟今生于此无缘。\n",who);
                        return 1;
                }
                else
                {
                        remove_call_out("destroy");
                        call_out("destroy", 1, who, ob);

                        if(query_temp("bu"))
                        {
                                message_vision("\n龙岛主见是腐心草，大喜道：恭喜这位小兄弟了!\n",who);
                                obn=new("/d/xiakedao/obj/zhou");
                                obn->move(who);
                                delete_temp("cao");
                                delete_temp("bu");
                                return 1;
                        }
                        else if(query_temp("cao"))
                        {
                                message_vision("\n龙岛主见是腐心草，对$N摇头道：腐心草我已经有了。\n",who);
                                return 0;
                        }
                        else
                        {
                                message("vision","龙岛主看见腐心草，大喜道：现在只差赏善罚恶簿了。\n",environment(who));
                                set_temp("cao",1);
                                return 1;
                        }
                }
        }
        return 1;
}




int ask_me()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	if(!who->query_temp("book115"))
	{
		message_vision("$N对$n说道： 要挑战我？先帮石破天找到玄冰碧火酒吧。\n",this_object(),who);
  
		return 1;	
	}

	if(!who->query_temp("book1152"))
	{
		message_vision("$N对$n说道： 要挑战我？先和木岛主比比吧。\n",this_object(),who);
  
		return 1;	
	}
message_vision("$N对$n即然你想挑战我，就如你所愿吧。\n",this_object(),who);
who->set_temp("book1153",1);
kill_ob(who);                    
	return 1;
}

void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	if(((int)who->query("jinyong/book11")>=5))
	{
//::die();	
	}
        else if(who) {
  	if(((int)who->query("jinyong/book11")==4) && who->query_temp("book1153"))
{
		message_vision("$N说道：不错，不错。\n" NOR,this_object());
		i = 1900+random(3000);
		who->set("jinyong/book11",5);
		who->add("combat_exp",i+28000);
		who->add("potential",i*28);
		who->add("mpgx",20);
		who->add("expmax",2);
		tell_object (who,"你赢得了"+chinese_number(i+28000)+"点经验"+
		           chinese_number(i*28)+"点潜能"+"二十点门派贡献 二点成长上限！！\n");
		message("channel:chat", HIB"【海洋III】听说"+who->name() + "完成了侠客行的所有任务!"NOR"\n", users());
		who->save();
}
        }
	::die();
}                