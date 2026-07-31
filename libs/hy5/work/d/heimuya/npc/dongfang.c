// dongfang.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("东方不败", ({"dongfang bubai", "dongfang", "bubai"}));
    set("nickname", HIY "天下无敌" NOR );
    set("title", HIM"日月神教教主"NOR);
    set("gender", "男性");
    set("shen_type", -1);
    set("age", 42);
    set("long",
        "他就是日月神教教主。号称无人可敌，因此有一称号为「东方不败」。\n");
    set("attitude", "peaceful");

    set("per", 21);
    set("str", 61);
    set("int", 60);
    set("con", 66);
    set("dex", 66);

    set("chat_chance", 1);
    set("chat_msg", ({
 "东方不败叹了口气道：“唉 …… 我的杨大哥....他怎么还不回来,我好\n"
 "挂念他 ……东方不败眼中流露无限迷茫。\n",
        }));
    set("inquiry", ([
        "杨莲亭"   : "你敢直称我爱人的名字,想找死呀？ \n",
        "葵花宝典" : "如果你能帮我取得葵花宝典上册，我一定重重谢你。\n",
    ]));

    set("guard/flag", 1);
    set("guard/ok", 1);
    set("qi", 34000);
    set("max_qi", 34000);
    set("jing", 31000);
    set("max_jing", 34000);
    set("neili", 68500);
    set("max_neili", 68500);
    set("jiali", 200);

    set("combat_exp", 24500000);
    set("score", 0);

    set_skill("cuff", 250);
    set_skill("strike", 250);
    set_skill("force", 380);             // 基本内功
    set_skill("finger", 250);            // 基本指法
    set_skill("unarmed", 250);           // 基本拳脚
    set_skill("dodge", 380);             // 基本躲闪
    set_skill("parry", 380);             // 基本招架
    set_skill("sword", 380);             // 基本剑法
    set_skill("pixie-jian", 380);        // 辟邪剑法
    set_skill("changquan", 300);         // 太祖长拳
    set_skill("literate", 100);          // 读书识字
    set_skill("kuihua-xinfa", 380);      // 葵花心法
    set_skill("kuihua-dafa", 380);      // 葵花大法
    set_skill("kuihua-feiying", 380);      // 葵花身法
   set_skill("tmzhang", 180);
        set_skill("staff", 180);
         set_skill("tmjian", 180);
         set_skill("tmdao", 180);
         set_skill("pmshenfa", 180);
          set_skill("cuff",180);
         set_skill("blade", 180);
         set_skill("tmdafa", 180);
set_skill("tmquan", 180);       
    map_skill("force", "kuihua-xinfa");
    map_skill("sword", "kuihua-dafa");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "kuihua-feiying");
    map_skill("parry", "pixie-jian");
    create_family("日月神教", 1, "教主");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tonggui" :),
                (: perform_action, "sword.pi" :),
                	(: perform_action, "sword.yinrou" :),
                (: perform_action, "sword.po" :),
                (: perform_action, "sword.gui" :),
                (: perform_action, "parry.cimu" :),
                (: perform_action, "dodge.kuihuashenzhang" :),
                (: perform_action, "dodge.feiying" :),
                (: perform_action, "dodge.jue" :),
                (: perform_action, "unarmed.yuhuan" :),
                (: exert_function, "powerup" :),
                (: exert_function, "kuihuawudi" :),
                (: exert_function, "powerup" :),                
        }) );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 900);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
    setup();
    carry_object("/d/heimuya/npc/obj/qijue")->wield();
    carry_object("/d/wanjiegu/npc/obj/qi-dress")->wear();

}

void attempt_apprentice(object ob)
{
    if (ob->query_int() < 30) {
        command("say 我不收资质差的弟子，您请回吧！\n");
                return;
    }
    if (ob->query("gender") !="无性" ) {
        command("say 要练神功，必须自宫。");
              return;
    }
    if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000 ) {
        command("say 我黑木崖与世隔绝，向来不与您这种成名人物打交道，您请回吧！;\n");
                return;
        }
    command("say 很好，很好。\n");
    command("recruit " + ob->query("id"));
}
int recognize_apprentice(object ob)
{
        mapping myfam;
        myfam = (mapping)ob->query("family");
        if ( myfam["family_name"] == "黑木崖") return 1 ;
        if ((int)ob->query_temp("tmark/东") == 1 )
        message_vision("东方不败看了看$N，说道：咱们现在是谁也不欠谁,\n"
                          "你不要再找我学习技艺了。\n", ob);
        if (!(int)ob->query_temp("tmark/东"))
                return 0;
        ob->add_temp("tmark/东", -1);
        return 1;
}



int accept_object(object who, object ob)
{

        if ( (string) ob->query("id") =="kuihua baodian1" ) {
                if (!(int)who->query_temp("tmark/东",)) who->set_temp("tmark/东",100);
                message_vision("东方不败看了看$N送来的秘籍，点了点头，说道：\n"
                               "难得你将宝典送回。你送我的东西我就收下了。\n"
                               "作为补偿,你可以从我这里学点功夫。\n", who);
                who->add_temp("tmark/东", 100);
                return 1;

        }
        return 0;
}
