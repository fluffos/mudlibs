// panxiuda.c
// 潘秀达
// by victori
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("潘秀达", ({ "pan xiuda", "pan" }));
        set("nickname", HIG "笑面阎罗" NOR);
        set("long",@LONG
他就是五毒教的左护法，人称笑面阎罗的潘秀达。别看他一脸笑眯眯的
，但是常常杀人于弹指之间，一手五毒钩法也已达到登峰造极的境界。
LONG
        );
        set("title","五毒教护法");
        set("gender", "男性");
        set("age", 38);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30+random(50));
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 2000);
        set("max_neili", 3000);
        set("jiali", 180);
        set("combat_exp", 8000000);
        set("score", 50000);

        set_skill("force", 350);
        set_skill("wudu-shengong", 350);
        set_skill("dodge", 350);
        set_skill("wudu-yanluobu", 340);
        set_skill("unarmed", 350);
        set_skill("qianzhu-wandushou", 350);
        set_skill("parry", 350);
        set_skill("sword", 340);
        set_skill("wudu-goufa", 370);
        set_skill("duji", 340);
        set_skill("literate", 180);

 


        map_skill("force", "wudu-goufa");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");
//        map_skill("hammer", "jinshe-chui");
 
        create_family("五毒教", 12, "护法");

        setup();

        carry_object(__DIR__"obj/ganggou")->wield();
        carry_object("/d/city/obj/cloth")->wear();

        add_money("gold",20);
}

void attempt_apprentice(object ob)
{

                  if ((string)ob->query("gender") == "无性") {
                                 command("say 这位公公不要开玩笑了。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是快去伺候皇上吧！");
                return;
                  }

                  if ((int)ob->query("shen") > -10000) {
                                 command("say 做我五毒教弟子必须心狠手辣。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "心慈手软，可惜与我教没有缘分啊！");
                return;
                  }

        if ((string)ob->query("family/family_name") != "五毒教")        {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "不是本教弟子，还是请回吧！");
                return;
                  }

        if ((int)ob->query_skill("duji", 1) < 100) {
                command("say 我五毒教弟子以毒杀人，修习毒技是首要的。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "是否还应该多多钻研本门的绝学？");
                return;
        }
        if ((int)ob->query_skill("wudu-shengong", 1) < 150) {
                command("say 你的五毒神功还学的不够啊。");
                return;
        }

          command("chat 嘿嘿嘿嘿！！！！！");
          command("chat 该当我五毒教发扬光大，称霸武林指日可待了。");
          command("chat 嘿嘿嘿嘿！！！！！");
        command("recruit " + ob->query("id"));
        ob->set("class", "none");

         ob->set("title",HIY"五毒教弟子"NOR);
         return;
}

