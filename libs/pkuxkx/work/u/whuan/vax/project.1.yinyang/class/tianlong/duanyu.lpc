// duanyu.c 段誉
// by paladin

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

// int ask_me();

void create()
{
        set_name("段誉", ({ "duan yu", "duan" }));
        set("nickname", HIR "风流浪子" NOR);
        set("long",
                "他就是段誉\n");
	
        set("title",RED "大理" NOR + GRN  "王子" NOR);
        set("gender", "男性");
        set("age", 18);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("dex", 30);
        set("max_qi", 10000);
        set("max_jing", 10000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 100);
        set("combat_exp", 2500000);
        set("score", 1000000);

        set("chat_chance", 100);

//        set("inquiry", ([
//                "六脉神剑剑谱" : (: ask_me :),
//        ]));
//        set("book_count", 1);


        set_skill("force", 250);
        set_skill("dodge", 250);
        set_skill("finger", 250);
        set_skill("parry", 250);
        set_skill("liumai-shenjian", 250);
        set_skill("literate", 250);
        set_skill("yiyang-zhi", 250);
          set_skill("beiming-shengong", 300);
        set_skill("lingbo-weibu", 250);

        map_skill("finger", "liumai-shenjian");
        map_skill("force", "beiming-shengong");
        map_skill("parry", "liumai-shenjian");
        prepare_skill("finger","liumai-shenjian");
        create_family("天龙寺", 1, "俗家第子");
//        set("class", "bonze");

        setup();

}


void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/master_name")!="枯荣大师" ) {

     command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜枯荣大师.\n");
                return;
        }


        if((int)ob->query("betrayer")>=1)
        {
command("say "+RANK_D->query_respect(ob)+"你多次叛师，背信弃义。我怎会收你。\n");
                return;
        }

        if ((int)ob->query("score")<1000){
        command("sigh"+ob->query("id"));
             command("say 你还是回去吧.我是不会收一个对大理国不忠之人的\n");
             return;
       }


        if ((int)ob->query("shen") < 20000) {
        command("say 学武之人，德义为先");
        command("say 在德行方面，" + RANK_D->query_respect(ob) +
                    "是否还做得不够？");
              return;
        }

        if ((int)this_player()->query_int() < 40 )
        {
   command("say 学习秘技要有好的悟性，"+RANK_D->query_respect(ob)+"资质不够\n");
                return;
        }

        command("chat 想不到我段誉又觅得一个可塑之才，真是可喜可贺。");
        command("recruit " + ob->query("id"));

        ob->set("title", GRN "天龙寺" NOR + YEL "使者" NOR);
}

//string ask_me()
//{
//        mapping fam;
//        object ob;
//            if (!(fam = this_player()->query("family"))
//            || fam["family_name"] != "天龙寺")
//                return RANK_D->query_respect(this_player()) +
//                "与本派素无来往，不知此话从何谈起？";
//        if (query("book_count") < 1)
//                return "你来晚了，本派的「六脉神剑剑谱」不在此处。";
//        add("book_count", -1);
//        ob = new("/d/dali/obj/lmsj");
//        ob->move(this_player());
//        return "好吧，这本「六脉神剑剑谱」你拿回去好好钻研。";
//}

