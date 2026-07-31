// hehongyao.c
// 何红药
// by victori
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("何红药", ({ "he hongyao", "he" }));
        set("nickname", HIG "疤面丐婆" NOR);
        set("long",@LONG
他就是五毒教的长老，教主的姑姑何红药。随然是教主的长辈，但功夫却是一块跟
上代教主学的。据说她曾经被立为教主继承人，但后来犯下大错，所以被罚到此处
看守圣地，以赎前罪。她穿着一身破旧的衣衫，满脸疤痕，长得骨瘦如柴，双目中
满是怨毒之色。
LONG
        );
        set("title","五毒教长老");
        set("gender", "女性");
        set("age", 45);
        set("shen_type", -1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 7000);
        set("max_jing", 4000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);
        set("combat_exp", 15000000);
        set("score", 500000);

        set_skill("force", 470);
        set_skill("wudu-shengong", 460);
        set_skill("dodge", 460);
        set_skill("wudu-yanluobu", 440);
        set_skill("unarmed", 460);
        set_skill("qianzhu-wandushou", 470);
        set_skill("parry", 460);
        set_skill("sword", 470);
        set_skill("wudu-goufa", 480);
        set_skill("duji", 460);
        set_skill("literate", 180);




        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");


        create_family("五毒教", 11, "长老");

        setup();

        carry_object(__DIR__"obj/jiandao")->wield();
        carry_object("/d/city/obj/cloth")->wear();
        carry_object(__DIR__"obj/wuxing");

        add_money("gold",10);
}

void attempt_apprentice(object ob)
{

                  if ((string)ob->query("gender") == "无性") {
                                 command("say 这位公公不要开玩笑了。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是快去伺候皇上吧！");
                return;
                  }

                  if ((int)ob->query("shen") > -60000) {
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
        if ((int)ob->query_skill("wudu-shengong", 1) < 100) {
                command("say 你的五毒神功还学的不够啊。");
                return;
        }

          command("chat 嘿嘿嘿嘿！！！！！");
          command("chat 该当我五毒教发扬光大，称霸武林指日可待了。");
          command("chat 嘿嘿嘿嘿！！！！！");
          command("recruit " + ob->query("id"));
        ob->set("class", "none");
         ob->set("title",HIY"五毒教护法"NOR);
       return;
}

