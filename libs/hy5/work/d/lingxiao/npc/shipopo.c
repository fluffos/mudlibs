//LUCAS 2000-6-18
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void consider();
string ask_book();
void create()
{
        set_name("史婆婆",({"shi popo","popo"}));
        set("gender", "女性");
        set("age", 50);
        set("long", "她是雪山派掌门人白自在的妻子，虽说现在人已显得苍老，\n"
        "但几十年前提起“江湖一枝花”史小翠来，武林中却是无人不知。\n");
        set("attitude", "friendly"); 

        set("str", 30);
        set("con", 30);
        set("int", 30);
        set("dex", 30);
        set("per", 30);
        set("neili", 22000);
        set("max_neili", 22000);
        set("jing", 13500);
        set("max_jing", 13500);
        set("qi", 15000);
        set("max_qi", 15000);
        set("jiali", 50);

        set("combat_exp", 6000000);
        set("inquiry", ([
                "金乌刀谱":(:ask_book:),
        ]) );
        set("shen_type", 0);
        set("score", 50000);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.yanxue" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.zhe" :),
                (: perform_action, "unarmed.lang" :),
                (: perform_action, "strike.zhangjian" :),
                (: perform_action, "strike.siji" :),
	               (: perform_action, "hand.hantian" :),   
(: perform_action, "blade.jinwu" :),
(: perform_action, "dodge.snowfly" :),

                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) ); 
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );

        create_family("凌霄城", 5, "弟子");
        set_skill("force", 200);
        set_skill("dodge", 250);
        set_skill("blade", 380);
        set_skill("parry", 220);
        set_skill("unarmed", 200);
        set_skill("strike", 280);
        set_skill("jinwu-blade", 380);
        set_skill("snowstep", 250); 
        set_skill("bingxue-xinfa", 320); 
        set_skill("snow-zhang",220);
set_skill("kuangfeng-blade", 380);
set_skill("liujue-dao", 380);
set_skill("fanyun-zhang", 380);

         set_skill("doom-hand", 300);
        set_skill("hanshan-strike", 300);
        set_skill("snowwhip", 300);
        set_skill("hand", 250);
        set_skill("whip", 250);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        set("count", 1);

        map_skill("strike", "hanshan-strike");
        map_skill("hand", "doom-hand");
	prepare_skill("strike", "hanshan-strike");
	prepare_skill("hand", "doom-hand");
        map_skill("blade", "jinwu-blade"); 
        map_skill("force", "bingxue-xinfa"); 
        map_skill("unarmed", "snow-zhang");
        map_skill("parry", "jinwu-blade");
        map_skill("dodge", "snowstep");

        setup();

        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/money/gold");
}

string ask_book()
{
        object me,ob;
        ob=this_player(); 
        
        if(ob->query("family/master_id")=="bai wanjian")
        {
                if (query("count") == 1) {
                command("say 你是万剑的弟子吗?那就给你吧。");
                message_vision(HIG"史婆婆掏出一本小册子,交给$N \n\n"NOR,ob);
                me=new("/d/lingxiao/obj/jinwu-book");
                me->move(ob);
                add("count", -1);
                return "你好好读读，比老鬼的剑法好多了。\n";
                }
                else return"你来晚啦，刀谱已经让人拿走了。\n";
        }
        if(ob->query("family/master_id")=="bai zizai")
        {
                if (query("count") == 1) {
                command("say 你是老鬼的弟子吗?那就给你吧。");
                message_vision(HIG"史婆婆掏出一本小册子,交给$N \n\n"NOR,ob);
                me=new("/d/lingxiao/obj/jinwu-book");
                me->move(ob);
                add("count", -1);
                return "你好好读读，比老鬼的剑法好多了。\n";
                }
                else return "你来晚啦，刀谱已经让人拿走了。\n";
        }

        command("say 走开，不然老太婆要发火了？");
        message_vision(HIG"史婆婆哼了一声，不理$N \n\n"NOR,ob);

        return "我虽离开了凌霄城,却也不会乱传人武功\n";
}

int recognize_apprentice(object ob)
{
        mapping myfam;
        myfam = (mapping)ob->query("family");
//        if ( myfam["family_name"] == "凌霄城") return 1 ;
        if ((int)ob->query_temp("tmark/shi") == 1 )
        message_vision("史婆婆哼了一声，对$N说道：老身今天不想再教了，你下次再来吧。\n", ob);
        if (!(int)ob->query_temp("tmark/shi"))
                return 0; 
        ob->add_temp("tmark/shi", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        
        if ( (string) ob->query("id") =="jinwu-staff" ) {
                if (!(int)who->query_temp("tmark/shi")) who->set_temp("tmark/shi", 0);
                message_vision("史婆婆接过金乌杖，“呵呵”笑了两声，摸摸杖身，说道：\n"
                               "好！好！好！难得你帮我乖孙女办事，真不错，好吧！\n"
                               "老身今天正好有空，就教你一会工夫吧。\n", who);
                who->add_temp("tmark/shi", 900);
                return 1;
        }
        return 0;
}

void attempt_apprentice(object ob)
{
    if (ob->query_int() < 30) {
        command("say 你这种资质,一边去吧！");
                return;
    }
    if ((int)ob->query_skill("bingxue-xinfa",1) < 80 ) {
        command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
                return;
    } 
    if ((int)ob->query("shen") < 0 ) {
         command("say 你这种人，再不滚，我马上宰了你。"); 
                return;
    } 
    if ((int)ob->query("max_neili") < 800 ) {
         command("say 你内力不足，先去打熬打熬内力吧。"); 
                return;
    }
    if ((int)ob->query_skill("xueshan-sword",1) < 100 ) { 
        command("say 你的本门剑法太低了,还是先找你原来的师父提高吧!"); 
                return;
    }
    if ((int)ob->query_skill("sword",1) < 100 ) {  
        command("say 你的基本剑法太低了,还是先提高基本功吧!"); 
                return; 
    }
    command("say 很好，很好,老身就收你为徒吧。");
    command("recruit " + ob->query("id"));
} 

