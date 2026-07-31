// /kungfu/class/xueshan/shengdi.c  胜谛
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("胜谛", ({ "sheng di", "sheng", "di" }));
        set("long",@LONG
这是一个身形魁梧的西藏僧人，神色冷漠。武功是同门中最高的一人。
LONG
        );
        set("title",HIR"血刀门第五代弟子"NOR);
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
       set("max_qi", 10000);
        set("max_jing", 5000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 50);
        set("combat_exp", 950000);
        set("score", 35000);

        set_skill("lamaism", 150);
        set_skill("literate", 180);
        set_skill("force", 180);
        set_skill("parry", 180);
        set_skill("blade", 180);
        set_skill("dodge", 180);
        set_skill("longxiang", 180);
        set_skill("shenkong-xing", 180);
        set_skill("hand", 180);
        set_skill("dashou-yin", 280);
        set_skill("xue-dao", 190);
set_skill("yujiamu-quan", 280);
        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
map_skill("cuff", "yujiamu-quan");
map_skill("hand", "dashou-yin");
prepare_skill("cuff", "yujiamu-quan");
prepare_skill("hand", "dashou-yin");
	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
                                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.xueyu" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );

        create_family("雪山寺", 5, "弟子");
        set("class", "bonze");

        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/clone/weapon/gangdao")->wield();

        add_money("gold",1);
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("gender") != "男性")
        {
                command("say 我不收女徒弟。\n");
                return;
        }
        if (ob->query("shen") > -50000)
        {
                command("say 看来我还要先教你如何心狠杀人。\n");
                return;
        }
        if ((int)ob->query_skill("longxiang", 1) < 45)
        {
                command("say 入我血刀门，修习龙象功法是首要的。\n");
                return;
        }
        command("haha");
        command("recruit " + ob->query("id"));

        ob->set("title", HIR "血刀门第六代弟子" NOR);
}
