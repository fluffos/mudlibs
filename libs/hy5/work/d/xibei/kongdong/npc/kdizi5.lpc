inherit NPC;


void create()
{
        set_name("烧火小道士", ({ "shaohuo daoshi","daoshi" }) );
        set("title","崆峒弟子");
        set("gender", "男性" );
        set("class","taoist");
        set("age",16);
	create_family("崆峒派", 2, "弟子");
	   set("combat_exp", 1000000);
        set("str", 55);
        set("max_qi",5000);
        set("max_jing",5000);
        set("max_sen",5000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("atman", 10000);
        set("max_atman", 50000);
        set("mana", 50000);
        set("max_mana", 50000);
        set("force_factor", 350);




set_skill("jinshe-jian",380);
set_skill("liancheng-jian",380);
set_skill("hujia-daofa",380);
set_skill("demon-strike",380);
set_skill("nine-moon-claw",380);
set_skill("ill-quan",380);
set_skill("doomstrike",380);
set_skill("luoriquan",380);
set_skill("qinnashou",380);
set_skill("taixuan-gong",380);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);
        set_skill("jingyiforce",380);
        set_skill("demon-blade",280);
        set_skill("literate",380);
        set_skill("unarmed",380);
        set_skill("dodge",290);
        set_skill("parry",280);
	set_skill("force",380);
	set_skill("blade",280);
	set_skill("changquan",380);
        //set_skill("doomsword",380);
        //set_skill("chilian-shenzhang",380);
        //set_skill("softsword",280);
        //set_skill("nine-moon-sword",380);
        set_skill("luohua-jian",380);
        set_skill("sword",380);
        set_skill("feixian-sword",380);
        set_skill("bat-blade",380);
        set_skill("fengyu-piaoxiang",390);

        map_skill("unarmed","changquan");
        map_skill("sword","jinshe-jian");
        map_skill("force","taixuan-gong");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("parry","liancheng-jian");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "hun" :),
                (: exert_function, "jing" :),
                (: exert_function, "po" :),
                (: exert_function, "taixuan" :),		
                (: exert_function, "xuan" :),			
                (: perform_action, "unarmed.yuhuan" :),
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.wan" :),
                (: perform_action, "sword.kun" :),	
                (: perform_action, "sword.shi" :),	
                (: perform_action, "sword.suo" :),	                	
                (: perform_action, "parry.ci" :),
                (: perform_action, "parry.erguang" :),
(: perform_action, "parry.gan" :),
(: perform_action, "parry.qian" :),
(: perform_action, "parry.qu" :),		             
(: perform_action, "parry.zhai" :),		             
(: perform_action, "parry.zhu" :),		             	             
(: perform_action, "dodge.zonghengsihai" :),		             	             
(: perform_action, "dodge.zonghengsihai" :),		             	              
        }) );
	set("food_apply",15);
        setup();
        carry_object(__DIR__"obj/cloth3")->wear();
}

void init()
{
        object ob;
        if(interactive(ob=this_player()) && !is_fighting()){
		remove_call_out("show_msg");
            call_out("show_msg",1,ob);
            }
        add_action("do_yao","yao");
}

void show_msg(object ob)
{
        if(!ob||!present(ob,environment(this_object())))return;
        say("这几个小道士正手忙脚乱地引火做饭，没有注意到你。\n");
}
int do_yao()
{
    object who = this_player();
    object me = this_object();

    if( who->query("family/family_name")!="崆峒派" || query("food_apply") < 0 )
        {
               message_vision("小道士对着$N摇了摇头说：这位施主，实在对不起，\n"
                        "斋饭还没有做好，烦请多等一会儿。\n",who);  
               return 1;
        }
    if ( (who->query("water") >= who->max_water_capacity()/2)
        &&(who->query("food") >= who->max_food_capacity()/2) ){
        return notify_fail("你吃得饱饱的，喝得足足来这里添什么乱？！\n");
        }

    message_vision("$N揉着肚子可怜兮兮得对$n说：\n"
        "“小师兄，还有剩饭吗？实在是饿得不行了。”\n\n",who,me);
        printf("小道士忙说：这位%s，饭还没好，我先找给你点东西充饥吧。\n",
                (who->query("gender")=="男性") ? "师兄" : "师姐" );
    who->set("food" ,who->max_food_capacity());
    who->set("water",who->max_water_capacity());

    return 1;
}

int accept_object(object who, object ob)
{
        if(ob->value() >= 1000)
        {
                message_vision("小道士迟疑地看着"+ob->name()+"，嘴里嘟囔着：\n"
                "这怎么好意思呢？\n",who);
                message_vision("小道士想了想，从食橱里拿给$N一块素饼和一个葫"
                        "芦，\n说：要有人问起，你可别说是我拿给你的。\n",who);
                message_vision("小道士转过身去，继续引火。\n",who);
                new(__DIR__"obj/subing")->move(who);
                new(__DIR__"obj/hulu")->move(who);
                return 1;
        }
        else 
        {
                message_vision("小道士摇摇头：师傅说过，不能随便要别人的东西。\n",who);
                return 0;
        }
}

                
