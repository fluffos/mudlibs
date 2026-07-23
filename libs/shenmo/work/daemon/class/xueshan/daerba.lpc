// /kungfu/class/xueshan/daerba.c  达而巴
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("达而巴", ({ "daerba huofo", "huofo" }));
        set("long",@LONG
他是金轮法王座下的大弟子。深得法王的真传。
身穿一件黄色袈裟，头带僧帽。
LONG
        );
        set("title", HIY "活佛" NOR);
        set("gender", "男性");
        set("age", 45);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 6500);
        set("max_jing", 6200);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 50);
        set("combat_exp", 300000);
        set("score", 150000);

        set_skill("lamaism", 80);
        set_skill("literate", 80);
        set_skill("force", 120);
        set_skill("xiaowuxiang", 220);
        set_skill("dashou-yin", 220);
                set_skill("longxiang", 220);
        set_skill("dodge", 100);
        set_skill("shenkong-xing", 200);
        set_skill("unarmed", 100);
        set_skill("yujiamu-quan", 280);
        set_skill("parry", 100);
        set_skill("sword", 70);
        set_skill("mingwang-jian", 60);
        set_skill("staff", 380);
        set_skill("xiangmo-chu", 380);
        set_skill("magic", 180);
        set_skill("kwan-yin-spells", 180);
        
        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "xiangmo-chu");
        map_skill("staff", "xiangmo-chu");
        map_skill("sword", "mingwang-jian");
map_skill("magic", "kwan-yin-spells");
map_skill("cuff", "yujiamu-quan");
map_skill("hand", "dashou-yin");
prepare_skill("cuff", "yujiamu-quan");
prepare_skill("hand", "dashou-yin");
	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
                (: perform_action, "staff.zhen" :),
                (: perform_action, "staff.zhen" :),
                (: perform_action, "staff.zhen" :),
                (: perform_action, "staff.zhen" :),			
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );
        create_family("雪山寺", 3, "活佛");
        set("class", "bonze");

        setup();
        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();

        add_money("gold",1);
}

void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") != "男性") {
                command("say 修习密宗内功需要纯阳之体。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
        }

         if ((string)ob->query("class") != "bonze") {
                command("say 我佛门的清规戒律甚多。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
        }

        if ((string)ob->query("family/family_name") != "雪山寺")        {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "既非本寺弟子，还是请回吧！");
                return;
        }

        if ((int)ob->query_skill("lamaism", 1) < 60) {
                command("say 入我雪山寺，修习密宗心法是首要的。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "是否还应该多多钻研本门的心法？");
                return;
        }

        command("say 你就是我的弟子了！");
        command("recruit " + ob->query("id"));

        ob->set("title", HIY "大喇嘛" NOR);
}
