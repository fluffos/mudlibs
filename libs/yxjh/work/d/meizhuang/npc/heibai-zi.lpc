// heibai.c
inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("黑白子", ({ "heibai zi", "zi" }));
        set("title", HIW"梅庄二庄主"NOR);
        set("long",
                "他就是梅庄四位庄主排行第二的秃笔翁。\n"
                "身穿一件干干净净的黑色长袍。\n"
                "他已年愈五旬，身材高大，双眼神光内敛, 一望便知是一位内家的高手。\n");
        set("gender", "男性");
        set("age", 52);
        set("class", "scholar");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 2000);
        set("max_jing", 2000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 80);
        set("combat_exp", 80000000);
        set("shen", 15000);
        set("score", 60000);

        set_skill("force", 920);
        set_skill("wuzheng-xinfa", 920);
        set_skill("dodge", 1000);
        set_skill("piaoyibu", 910);
        set_skill("parry", 920);
        set_skill("throwing", 600);
        set_skill("fenglei-zifa", 600);
        set_skill("xuantian-zhi", 440);
        set_skill("literate", 930);

        map_skill("force", "wuzheng-xinfa");
        map_skill("dodge", "piaoyibu");
        map_skill("parry", "pogu-bifa");
       map_skill("unarmed", "xuantian-zhi");
       map_skill("throwing", "fenglei-zifa");
        prepare_skill("finger", "xuantian-zhi");

        create_family("梅庄", 1, "庄主");

        setup();
        carry_object(__DIR__"obj/heiyi")->wear();

}


int accept_object(object me, object obj)
{       
       int count,i;
       object ob;
       me=this_player();
       ob=this_object();
       if (obj->query("id")!="ouxue pu")
       {command("say 难道这就是我要的东西！？。");return 0;}

       command("thumb "+me->query("id")+"");
       command("say 你帮我办成了这件事，我很高兴，你愿意拜入我门下吗？");
       destruct(obj);
       me->set("meizhuangouxuepu",1);

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
        if ((int)ob->query("meizhuangouxuepu") < 1) {
                command("say 想入我门下，" + RANK_D->query_respect(ob) +
                        "就去帮我把呕血谱找来给我？");
                return;
        }
         message("vision",HIY"〖风云再起〗"NOR+":"+HIR" 听说"HIW+ob->short()+NOR HIB"拜入梅庄二庄主黑白子门下!\n"NOR,users());
        command("say 好吧，在下就收下你了。");
        command("recruit " + ob->query("id"));
}


