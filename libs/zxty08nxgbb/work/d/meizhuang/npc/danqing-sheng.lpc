// danqing-sheng.c 
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("丹青生", ({ "danqing sheng", "sheng" }));
        set("title", HIY"梅庄四庄主"NOR);
        set("long",
                "他就是梅庄四位庄主排行第四的丹青生。\n"
                "身穿一件干干净净的青色长袍。\n"
                "他已年愈四旬，身材瘦长，满脸红光。恬淡冲和，沉默寡言。\n");
        set("gender", "男性");
        set("age", 40);
        set("class", "scholar");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 60000000);
        set("shen", 15000);
        set("score", 60000);

        set_skill("force", 900);
        set_skill("wuzheng-xinfa", 900);
        set_skill("dodge", 900);
        set_skill("piaoyibu", 900);
        set_skill("parry", 900);
        set_skill("sword", 900);
        set_skill("pomo-jianfa", 500);
        set_skill("literate", 900);

        map_skill("force", "wuzheng-xinfa");
        map_skill("dodge", "piaoyibu");
        map_skill("parry", "pomo-jianfa");
        map_skill("sword", "pomo-jianfa");

        create_family("梅庄", 1, "庄主");

        set("item_count", 1);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/heiyi")->wear();

}

int accept_object(object me, object obj)
{       
       int count,i;
       object ob;
       me=this_player();
       ob=this_object();
       if (obj->query("id")!="xinglv tu")
       {command("say 难道这就是我要的东西！？。");return 0;}

       command("thumb "+me->query("id")+"");
       command("say 你帮我办成了这件事，我很高兴，你愿意拜入我门下吗？");
       destruct(obj);
       me->set("meizhuangxinglvtu",1);

       call_out("destroying", 1, ob, obj);
       return 1;}

void destroying(object ob, object obj)
{
       destruct(obj);return;}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_skill("wuzheng-xinfa") < 120) {
                command("say 在我梅庄的内功上，" + RANK_D->query_respect(ob) +
                        "是否还应该多下点功夫？");
                return;
        }
        if ((int)ob->query("meizhuangxinglvtu") < 1) {
                command("say 想入我门下，" + RANK_D->query_respect(ob) +
                        "就去帮我把溪山行旅图找来给我？");
                return;
        }
         message("vision",HIY"〖风云再起〗"NOR+":"+HIR" 听说"HIW+ob->short()+NOR HIB"拜入梅庄四庄主丹青生门下!\n"NOR,users());
        command("say 好吧，在下就收下你了。");
        command("recruit " + ob->query("id"));
}


