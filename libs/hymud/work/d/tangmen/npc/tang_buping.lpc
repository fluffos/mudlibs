// tang buping.c 唐不平

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("唐不平", ({ "tang buping", "tang" }));
        set("nickname", HIW "闪电手" NOR);
        set("long",
                "他是唐门第八代弟子，是江湖新一辈中颇有名气的人物。\n"
                "他大约二十有余，脸上还带着一股孩子气。\n");
        set("gender", "男性");
        set("age", 22);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 25);
        set("int", 30);
        set("con", 30);
        set("dex", 25);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 30);
        set("combat_exp", 100000);
        set("score", 10000);

        set_skill("force", 70);
        set_skill("biyun-xinfa",70);
        set_skill("dodge", 70);
        set_skill("qiulinshiye", 70);
        set_skill("strike", 60);
        set_skill("unarmed",60);
        set_skill("biye-wu", 60);
        set_skill("parry", 70);
        set_skill("throwing", 70);
        set_skill("zhuihun-biao", 70);
        set_skill("literate", 80);

        map_skill("force", "biyun-xinfa");
        map_skill("dodge", "qiulinshiye");
        map_skill("strike", "biye-wu");
        map_skill("unarmed","biye-wu");
        map_skill("parry", "zhuihun-biao");
        map_skill("throwing", "zhuihun-biao");

        create_family("唐门", 8, "弟子");
        set("class", "tangmen");

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({

                (: perform_action, "strike.meng" :),
                (: exert_function, "recover" :),
        }) );

        setup();
        add_money("gangbiao",300);
	carry_object("/d/tangmen/obj/zhuyebiao")->wield();
        carry_object("/d/tangmen/obj/qingduan")->wear();
}

void attempt_apprentice(object ob)
{
        command("say 好吧，我就收下你。");
        command("recruit " + ob->query("id"));
}
