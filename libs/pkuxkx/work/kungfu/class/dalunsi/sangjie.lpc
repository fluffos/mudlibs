// sangjie.c 桑结
// by iceland

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("桑结", ({ "sang jie", "sangjie" ,"sang","jie"}));
        set("long",@LONG
他身体高瘦，脸颊深陷，面色黑黄，似乎虚弱不堪。双臂很长，手上骨节暴起，
看来空手功夫十分了得。
LONG
        );
        set("title", HIY "大轮寺佛前总护法" NOR);
        set("gender", "男性");
        set("class", "huanxi");
        set("age", 45);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 35);
        set("int", 30);
        set("con", 35);
        set("dex", 35);
        set("max_qi", 1800);
        set("eff_jing", 500);
        set("max_jing",500);
        set("neili", 2100);
        set("max_neili", 2100);
        set("jiali", 50);
        set("combat_exp", 800000);
        set("score", 400000);
        set("unique", 1);

        set_skill("huanxi-chan", 160);
        set_skill("literate", 100);
        set_skill("force", 160);
        set_skill("longxiang-boruo", 160);
        set_skill("dodge", 160);
        set_skill("yuxue-dunxing", 160);
        set_skill("claw", 160);
        set_skill("tianwang-zhua", 160);
        set_skill("hand", 160);
        set_skill("dashou-yin", 160);
        set_skill("parry", 160 );
        set_skill("staff",160);
        set_skill("wushang-dali",160);
        set_skill("poison",100);

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "wushang-dali");
        map_skill("claw", "tianwang-zhua");
        map_skill("staff","wushang-dali");

        prepare_skill("hand","dashou-yin");
        prepare_skill("claw","tianwang-zhua");

        create_family("大轮寺", 11, "弟子");
        set("class", "huanxi");

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: exert_function, "shield sang jie" :),
                (: perform_action, "hand.tianyin" :),
        }));

        setup();
        carry_object("/d/dalunsi/npc/obj/changsheng-jiasha")->wear();

}

void attempt_apprentice(object ob)
{
        if( (string)ob->query("gender") == "无性" ) {
                command("say 施主身体残缺，虽说佛祖普渡众生，可是...\n");
                return;
}
        if ((string)ob->query("family/family_name") != "大轮寺") {
                command("say"+ RANK_D->query_respect(ob) +
                        "不是本寺弟子，在这里捣什么乱？！");
                return;
        }

        if ((int)ob->query_skill("longxiang-boruo", 1) < 120) {
                command("say 我大轮寺各种武功均和内功相辅相成。");
                command("say"+ RANK_D->query_respect(ob) +
                        "再熬几个通宵，多多钻研钻研本门的内功吧。");
                return;

        }
        command("say 你的功夫已经不错了，以后就跟我学吧。");
        command("recruit " + ob->query("id"));
        ob->set("title", HIY "大轮寺第十二代弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
}


