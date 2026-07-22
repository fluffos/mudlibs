// fang.c
inherit NPC;

int ask_help();

void create()
{
        set_name("方评", ({ "fang ping", "fang",}));
        set("long",
                "他就是河南开封金瓜锤方评方老英雄，一神青色布衣，显的仙风傲骨。平时种田读书，从不和人交往。\n"
        );
        set("gender", "男性");
        set("attitude", "friendly");
        set("age", 57);
        set("shen_type", 100000);
        set("str", 42);
        set("int", 42);
        set("con", 42);
        set("dex", 42);
        set("per", 40);
        set("max_qi", 6000);
        set("max_jing", 6000);
        set("neili", 9000);
        set("max_neili", 9000);
        set("jiali", 50);
        set("combat_exp", 3000000);
        set("score", 100);

        set("chat_chance", 30);
        set("chat_msg", ({
                (: random_move :)
        }) );
        set_skill("linji-zhuang", 280);
        set_skill("literate", 180);
        set_skill("parry", 280);
        set_skill("taizu-quan", 280);
        set_skill("dodge", 280);
        set_skill("force", 280);
        set_skill("cuff", 280);
        set_skill("anying-fuxiang", 280);

        set("apply/attack", 50);
        set("apply/dexerity", 50);

        map_skill("force", "linji-zhuang");
        map_skill("parry", "taizu-quan");
        map_skill("cuff", "taizu-quan");
        map_skill("dodge", "anying-fuxiang");
        prepare_skill("cuff", "taizu-quan");
        set("inquiry",([
          "帮忙" : (: ask_help :),
          "助阵" : (: ask_help :),
          "help" : (: ask_help :),
        ]) );
        create_family("峨嵋派", 3, "弟子");

        setup();
        carry_object("/clone/armor/cloth")->wear();

}

int ask_help()
{
    object me=this_player();
    object ob = this_object();
    object here = environment(me);
    object bing1, bing2;

    if( ob->query("pl") != me ) return 0;
    if( !me->query_temp("em_job1/killed") ) {
        command("l "+me->query("id"));
        command("say 我怎么才能相信你？\n");
        command("say 那边来了两个元兵，你把他们杀了，我就找人帮你。\n");
        bing1 = new("/d/emei/npc/yuanbing");
        bing1->move(here);
        bing1->setskill(me, bing1);
        bing1->set_leader(me);
        bing1->kill_ob(me);
        me->set_temp("em_job1/bing1", bing1); 
        bing2 = new("/d/emei/npc/yuanbing");
        bing2->move(here);
        bing2->setskill(me, bing2);
        bing2->set_leader(me);
        bing2->kill_ob(me);
        me->set_temp("em_job1/bing2", bing2); 
        me->set_temp("em_job1/killing", 1); 
        me->set_temp("em_job1/bing3", me); 
        me->set_temp("em_job1/bing4", me); 
        me->set_temp("em_job1/bing5", me); 
    }
    else if( me->query_temp("em_job1/killed") < 2 ) {
        command("say 这两个家伙你还没干掉呢。\n");
    }
    else {
        me->delete_temp("eme_job1/killed");
        me->delete_temp("eme_job1/killing");
        me->delete_temp("eme_job1/bing1");
        me->delete_temp("eme_job1/bing2");
        me->delete_temp("eme_job1/bing3");
        me->delete_temp("eme_job1/bing4");
        me->delete_temp("eme_job1/bing5");
        command("say 好吧，你先回到灭绝师太那里等我，我这就召集人马帮你助阵。\n");
        move("/d/emei/houdian");
        ob->apply_condition("em_job1", 3);
        set("job_ok", 1);
    }
    return 1;
}

void delay_dest()
{
     remove_call_out("dest");
     call_out("dest", 60);
}

void dest()
{
       object me = this_object();
       object here;
       here = find_object("/d/emei/houdian");
       here->delete("fighting");
       here = find_object("fang ping");
       tell_room(here, me->query("name")+"道：敌人已经撤了，后会有期！\n");  
       tell_room(here, me->query("name")+"转身离开。\n");  
       destruct(me);
}

