#include <ansi.h>

inherit "/inherit/char/punisher";

void create()
{
        set_name("明教波斯使者", ({ "bosi shizhe", "bosi", "shizhe"}));
        set("long",  "他看上去不像是中土人氏。\n");
        set("gender", "男性");
        set("age", 34);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 999);
        set("int", 999);
        set("con", 999);
        set("dex", 999);

        set("max_qi", 60000);
        set("max_jing", 4000);
        set("neili", 7500);
        set("max_neili", 7500);
        set("jiali", 150);
        set("combat_exp", 2500000);
        set("score", 10000000);

        set_skill("force", 5000);
        set_skill("unarmed", 5000);
        set_skill("dodge", 5000);
        set_skill("parry", 5000);
        set_skill("cuff", 5000);
        set_skill("sword", 5000);
        set_skill("tiandaojian", 5000);
        set_skill("tiandaoquan", 5000);
        set_skill("jiuyang-shengong", 5000);
        set_skill("shenghuo-shengong", 5000);
        set_skill("shenghuo-xinfa", 5000);
        set_skill("qiankun-danuoyi", 5000);
        set_skill("shenghuo-bu", 5000);
        set_skill("qishang-quan", 5000);
        set_skill("taiji-quan", 5000);
        set_skill("taiji-jian", 5000);
        set_skill("shenghuo-ling", 5000);
        set_skill("literate", 280);
        set_skill("martial-cognize", 5000);

        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qiankun-danuoyi");
        map_skill("unarmed", "tiandaoquan");
        map_skill("cuff", "qishang-quan");
        map_skill("sword", "tiandaojian");
        map_skill("parry", "qiankun-danuoyi");

        prepare_skill("cuff", "qishang-quan");

        create_family("明教", 0, "使者");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: command("perform sword.tianjian") :),
                (: command("perform sword.tianyi") :),
                (: command("perform sword.weishe") :),
                (: command("perform sword.can") :),
                (: command("perform cuff.shang") :),
                (: command("perform cuff.fei") :),
                (: command("yun shield") :),
                (: command("yun powerup") :),
                (: command("yun recover") :),
        }) );

        setup();
        carry_object("/d/mingjiao/obj/baipao")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}
