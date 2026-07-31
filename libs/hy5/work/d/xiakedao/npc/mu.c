//mu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_zhou();

void create()
{
        set_name("木丹凤", ({ "mu", "wood" }));
        set("long", "他就是天下闻之色变的侠客岛岛主，号称“叶上秋露”。\n"
                   +"只见他长须稀稀落落，兀自黑多白少，但一张脸却满是皱纹。\n"
                   +"看不出他的实际年纪。\n"
                   );
        set("title", "侠客岛主");
        set("gender", "男性");
        set("age", 75);
        set("nickname", HIB "叶上秋露" NOR);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 60);
        set("int", 69);
        set("con", 60);
        set("dex", 68);

        set("qi", 33900);
        set("max_qi", 33900);
        set("jing", 33900);
        set("max_jing", 33900);
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

set_skill("huanhe-dao", 380);
set_skill("sata-shenfa", 350);
set_skill("sumi-jian", 350);
set_skill("wuyu-quan", 350);
set_skill("xiuli-qiankun", 350);
set_skill("strike", 250);
set_skill("cuff", 250);
set_skill("unarmed", 250);
set_skill("blade", 350);
set_skill("sword", 350);
set_skill("club", 380);
set_skill("bawang-qiang", 380);
//map_skill("sword", "sumi-jian");
map_skill("blade", "huanhe-dao");
map_skill("strike", "xiuli-qiankun");
map_skill("cuff", "wuyu-quan");
      map_skill("force", "taixuan-gong");
        map_skill("dodge", "sata-shenfa");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
    	prepare_skill("strike", "xiuli-qiankun");
	prepare_skill("cuff", "wuyu-quan");

        
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "blade.huan" :),
                	(: perform_action, "blade.kuang" :),
                		(: perform_action, "blade.leitingpili" :),
                			(: perform_action, "blade.shiwanshenmo" :),
                				(: perform_action, "blade.tiandirenmo" :),
                					(: perform_action, "blade.xueyu" :),
                						(: perform_action, "blade.baoxue" :),
                						(: perform_action, "blade.baoxue" :),                							
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
        set("chat_chance", 3);
        set("chat_msg", ({
            "木岛主忽然一怕脑袋，说：腊八粥可是好东西哇！\n",
            "木岛主说道：怎么这么多的英雄也不能领悟太玄经呢。\n",
        }) );
        set("inquiry", ([
            "腊八粥" : (: ask_zhou :),
            "侠客岛" :  "\n这个岛是我和龙兄弟无意中发现的。\n",
        ]));
        setup();
        carry_object(__DIR__"longdao")->wield();
        add_money("gold",3);
}

void attempt_apprentice(object ob)
{
  if((int)ob->query_skill("taixuan-gong",1)<100)
        {
          message_vision("木岛主拍拍$N的头，微微摇了摇头。\n",ob);
	return ;
         }

        message_vision("木岛主拍拍$N的头，微微点了点头。\n",ob);
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
        if(ob->query_skill("literate",1)>50)
              say ("木岛主看着你摇了摇头，说道：读书太多。\n");
        return;
}

int ask_zhou()
{
        say(
"\n木岛主对你说：这是本岛特有的东西，它主要由一味'断肠独骨腐心草'构成，\n"
"要开花后效力方著，但这种草每十年才开一次花，所以腊八粥很名贵，\n"
"一般人很难得到的，小兄弟想要就要看你的缘分了！\n");
        return 1;
}

int accept_object(object who, object ob)
{
        object obn;

        if (  ob->query("id") != "shane bu" && ob->query("id") != "fuxin cao")
        {
                message_vision("\n木岛主摇头道：这不是我想要的呀！\n",who);
                return 0;
        }
        if ( ob->query("id") == "shane bu" )
        {
                if (random((int)who->query("kar")) <=25 )
                {
                        message_vision("木岛主摇头道：我看小兄弟今生于此无缘。\n",who);
                        return 1;
                }
                else
                {
                        remove_call_out("destroy");
                        call_out("destroy", 1, who, ob);

                        if(query_temp("cao"))
                        {
                                message_vision("\n木岛主见是赏善罚恶簿，大喜道：恭喜这位小兄弟了!\n",who);
                                obn=new("/d/xiakedao/obj/zhou");
                                obn->move(who);
                                delete_temp("bu");
                                delete_temp("cao");
                                return 1;
                        }
                        else if(query_temp("bu"))
                        {
                                message_vision("\n木岛主见是赏善罚恶簿，对$N摇头道：赏善罚恶簿我有了。\n",who);
                                return 0;
                        }
                        else
                        {
                                message("vision","木岛主看见赏善罚恶簿，大喜道：现在只差腐心草了。\n",environment(who));
                                set_temp("bu",1);
                                return 1;
                        }
                }
        }
        if ( ob->query("id") == "fuxin cao")
        {
                if (random((int)who->query("kar")) <=25 )
                {
                        message_vision("木岛主摇头道：我看小兄弟今生于此无缘。\n",who);
                        return 1;
                }
                else
                {
                        remove_call_out("destroy");
                        call_out("destroy", 1, who, ob);

                        if(query_temp("bu"))
                        {
                                message_vision("\n木岛主见是腐心草，大喜道：恭喜这位小兄弟了!\n",who);
                                obn=new("/d/xiakedao/obj/zhou");
                                obn->move(who);
                                delete_temp("cao");
                                delete_temp("bu");
                                return 1;
                        }
                        else if(query_temp("cao"))
                        {
                                message_vision("\n木岛主见是腐心草，对$N摇头道：腐心草我已经有了。\n",who);
                                return 0;
                        }
                        else
                        {
                                message("vision","木岛主看见腐心草，大喜道：现在只差赏善罚恶簿了。\n",environment(who));
                                set_temp("cao",1);
                                return 1;
                        }
                }
        }
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


who->set_temp("book1152",1);
		
		

		
		
	::die();

}  