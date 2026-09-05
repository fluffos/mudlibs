// shengdi.c 胜谛
// by iceland

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("胜谛", ({ "sheng di", "shengdi" ,"sheng","di"}));
        set("long",@LONG
他是血刀老祖座下的大弟子，在几个弟子中武功最为精深。
他身材甚高，形貌枯槁。
LONG
        );
        set("title", HIR "大轮寺血刀老祖座下弟子" NOR);
        set("gender", "男性");
        set("class", "huanxi");
        set("age", 45);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 1200);
        set("eff_jing", 500);
        set("max_jing",500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
        set("combat_exp", 500000);
        set("score", 50000);
        set("unique", 1);

        set_skill("huanxi-chan", 120);
        set_skill("literate", 80);
        set_skill("force", 120);
        set_skill("longxiang-boruo", 120);
        set_skill("dodge", 120);
        set_skill("yuxue-dunxing", 120);
        set_skill("tianwang-zhua", 120);
        set_skill("parry", 120);
        set_skill("xuedao-jing", 120);
        set_skill("blade", 120);
        set_skill("claw", 120 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("claw", "tianwang-zhua");
        map_skill("parry", "xuedao-jing");
        map_skill("blade", "xuedao-jing");

        prepare_skill("claw","tianwang-zhua");

        create_family("大轮寺",12, "弟子");
        set("class", "huanxi");

        setup();
        carry_object("/d/dalunsi/npc/obj/gongdejiasha")->wear();
        carry_object("/d/dalunsi/npc/obj/xingyuedao")->wield();        

}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name") != "大轮寺") {
                command("say"+ RANK_D->query_respect(ob) +
                        "不是本寺弟子，在这里捣什么乱？！");
                return;
        }

        if ((int)ob->query_skill("huanxi-chan", 1) < 100) {
                command("say 欢喜禅是各项武功之本，你再勤加修炼吧。");
                command("say"+ RANK_D->query_respect(ob) +
                        "再熬几个通宵，多多钻研钻研本门的心法吧。");
                return;
        }

        command("say 好吧，以后你就好好侍奉佛爷我吧。");
        command("recruit " + ob->query("id"));

        ob->set("title", HIR "大轮寺血刀门第六代弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
}

