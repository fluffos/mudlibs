// shanyong.c 善勇
// by iceland

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("善勇", ({ "shan yong", "shanyong" ,"shan","yong"}));
        set("long",@LONG
他是血刀老祖座下二弟子，身材瘦高，脸色灰仆仆的，加上一对死鱼眼睛
看起来有些吓人。
LONG
        );
        set("title", HIR "大轮寺血刀老祖座下弟子" NOR);
        set("gender", "男性");
        set("class", "huanxi");
        set("age", 42);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 28);
        set("int", 15);
        set("con", 28);
        set("dex", 28);
        set("max_qi", 1000);
        set("eff_jing", 400);
        set("max_jing",400);
        set("neili", 1300);
        set("max_neili", 1300);
        set("jiali", 40);
        set("combat_exp", 400000);
        set("score", 40000);
        set("unique", 1);

        set_skill("huanxi-chan", 100);
        set_skill("literate", 80);
        set_skill("force", 100);
        set_skill("longxiang-boruo", 100);
        set_skill("dodge", 100);
        set_skill("yuxue-dunxing", 100);
        set_skill("hand", 100);
        set_skill("dashou-yin", 100);
        set_skill("staff", 100);
        set_skill("wushang-dali", 100);
        set_skill("parry", 100 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "wushang-dali");
        map_skill("staff", "wushang-dali");

        prepare_skill("hand","dashou-yin");

        create_family("大轮寺", 12, "弟子");
        set("class", "huanxi");

        setup();
        carry_object("/d/dalunsi/npc/obj/gongdejiasha")->wear();
        carry_object("/d/dalunsi/npc/obj/jingang")->wield();      

}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name") != "大轮寺") {
               command("say"+ RANK_D->query_respect(ob) +
                        "不是本寺弟子，在这里捣什么乱？！");
                return;
        }

        if ((int)ob->query_skill("huanxi-chan", 1) < 80) {
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
