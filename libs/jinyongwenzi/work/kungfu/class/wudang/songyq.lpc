// song.c 宋远桥

inherit NPC;
inherit F_MASTER;

#include <ansi.h>

string* names = ({
        "/d/wudang/sanqingdian",
        "/d/wudang/xiaolu1",
});

string ask_me();

string ask_me1();

string ask_me2();

void create()
{
       set_name("宋远桥", ({ "song yuanqiao", "song" }));
       set("nickname", "武当首侠");
       set("long", 
               "他就是张三丰的大弟子、武当七侠之首的宋远桥。\n"
               "身穿一件干干净净的灰色道袍。\n"
               "他已年过六十，身材瘦长，满脸红光。恬淡冲和，沉默寡言。\n");
       set("gender", "男性");
       set("unique", 1);
       set("age", 61);
       set("attitude", "peaceful");
       set("shen", 10000);
       set("str", 29);
       set("int", 27);
       set("con", 26);
       set("dex", 26);
       
       set("max_qi", 1500);
       set("max_jing", 1000);
       set("neili", 2000);
       set("max_neili", 2000);
       set("jiali", 50);
       set("combat_exp", 1000000);
//     set("score", 60000);
       set_skill("force", 130);
       set_skill("yinyun-ziqi", 130);
       set_skill("dodge", 130);
       set_skill("wudang-quan", 130);
       set_skill("tiyunzong", 130);
       set_skill("strike", 180);
       set_skill("zhenshan-mianzhang", 180);
       set_skill("parry", 130);
       set_skill("literate", 100);
       set_skill("xuanxu-daofa", 140);
       set_skill("wudang-quan", 140);
       map_skill("force", "yinyun-ziqi");
       map_skill("dodge", "tiyunzong");
       map_skill("strike", "zhenshan-mianzhang");
       map_skill("parry", "zhenshan-mianzhang");
       prepare_skill("strike", "zhenshan-mianzhang");
       create_family("武当派", 2, "弟子");

       set("inquiry", ([
               "秘籍" : (: ask_me :),
                "概要" : (: ask_me1 :),
                "工作" : (: ask_me2 :),
                "job" : (: ask_me2 :),
                "巡山" : (: ask_me2 :),
       ]));
       set("book_count1", 1);
       set("book_count2", 1);
       setup();
//     carry_object("/clone/weapon/changjian")->wield();
       carry_object("/d/wudang/obj/white-robe")->wear();

}
void init()
{
        object me, ob;
        ::init();
        ob = this_player();
        me = this_object();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }       
     
}
void greeting(object ob)
{
        int e,p;
        p = 20+random(80);
        e = 20+random(80);
        if(ob->query_temp("wd/wd_job_lost2") )
       {
        command("faint "+ob->query("id"));
        command("say "+ob->name()+"，已经有人帮你把那恶贼给赶跑了！");
        ob->delete_temp("wd/wd_job_lost2");
       }
        if(ob->query_temp("wd/wd_job_lost") )
       {
        command("sigh "+ob->query("id"));
        command("say "+ob->name()+"你怎么搞的，居然让那恶贼给跑了！");
        ob->delete_temp("wd/wd_job_lost");
        ob->apply_condition("job_busy",3+random(4) );
       }
        if(ob->query_temp("wd/wd_jobok") ){
        command("thumb "+ob->query("id"));
        command("say 很好，祝贺你完成了任务，下去休息休息吧！");
        ob->add("combat_exp",e);
        ob->add("potential",p);
        ob->delete_temp("wd/wd_job");
        ob->delete_temp("wd/wd_jobok");
        if ( (int)ob->query("potential", 1) > (int)ob->query("max_pot", 1) )
        ob->set("potential" , ob->query("max_pot", 1) );
        tell_object(ob, GRN"
你获得了"+CHINESE_D->chinese_number(e)+"点经验，"+CHINESE_D->chinese_number(p)+"点潜能！\n"NOR);
        write_file( "/log/wd_job",sprintf("%s %s(%s)为做武当巡山任务获得了%d点经验，%d点潜能。\n",
ctime(time())[4..19],ob->name(),ob->query("id"),e,p));
//        ob->apply_condition("job_busy",1+random(2) );
        }
        return;
}
void kill_ob(object me)
{
        //set("combat_exp", 750000);    
        //set("max_qi", 2500);
        //set("max_neili", 2000);
        //set("neili", 2000);
        //set("jiali", 100);
       set("chat_chance_combat", 20);
       set("chat_msg_combat", ({
               (: perform_action, "strike.bingdi" :),
               (: perform_action, "dodge.zong" :),
        }));
        ::kill_ob(me);       
} 

int accept_fight(object me)
{
        if((int)me->query("shen") < 1) {
           command("say 习武之人应志在锄恶济善，"+RANK_D->query_respect(me)+"目露瘴气，有违武学之本？");
           return 0;
        }
        ::fight_ob(me);
         return 1;
}

void attempt_apprentice(object ob)
{
       if ((int)ob->query("shen") < 10000) {
               command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
               command("say 在德行方面，" + RANK_D->query_respect(ob) +
                       "是否还做得不够？");
               return;
       }
       command("say 好吧，贫道就收下你了。");
       command("recruit " + ob->query("id"));
}

string ask_me()
{
       mapping fam; 
       object ob;
       if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
               return RANK_D->query_respect(this_player()) + 
               "与本派素无来往，不知此话从何谈起？";
       if(query("book_count2") < 1)
         return "你来晚了，本派的内功心法不在此处。";
       add("book_count2",-1);       
       ob = new(__DIR__"force_book");
       ob->move(this_player());
       return "好吧，这本「太极十三式」你拿回去好好钻研。";
}

string ask_me1()
{
        mapping fam; 
        object ob,song;        
        song = this_object();
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
        if (query("book_count1") < 1)
           return "你来晚了，刀法概要已经不在此处了。";
        add("book_count1",-1);         
        ob = new(__DIR__"blade_book");
        ob->move(this_player());
        return "这本书中讲述的刀法要领，你会去好好研究一下。";
}
string ask_me2()
{
        object me, ob;
        string objwhere;
        me=this_player();

        if (me->query_temp("wd/wd_job"))
           return "你似乎还没有完成你的任务吧？";
        if ((int)me->query("combat_exp") < 200000 )
           return "你实战经验不足，还是去俞岱岩那里做看守铜鼎的工作吧！";
        if(me->query_condition("job_busy"))
           return "现在暂时还没有工作让你去做。";

        me->set_temp("wd/wd_job",1);
        command("nod "+me->query("id"));
        ob=new("/d/wudang/npc/attacker");
        ob->set_temp("target", me->query("id") );
        objwhere = names[random(sizeof(names))];
        ob->move(objwhere);
        return "据说有人在"+objwhere->query("short")+CYN"附近捣乱，你马上去给我巡视一圈。";
}