// shan.c 张翠山

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("张翠山", ({ "zhang cuishan", "zhang" }));
        set("nickname", "武当五侠");
        set("long",
                "他就是张三丰的最聪明的弟子、武当七侠之五的张翠山。\n"
                "身穿一件干干净净的青布长衫。\n"
                "他不过二十出头年纪，潇洒英俊，一副白马王子派头。\n");
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("class", "scholar");
        set("shen_type", 1);
        set("str", 28);
        set("int", 30);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 12000);
        set("max_jing", 11000);
        set("neili", 11500);
        set("max_neili", 12000);
        set("jingli", 11000);
        set("max_jingli", 11000);
        set("jiali", 50);
        set("combat_exp", 1500000);
        set("score", 60000);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ren" :),
        }) );
        set_skill("force", 100);
        set_skill("taiji-shengong", 200);
        set_skill("dodge", 100);
        set_skill("tiyunzong", 200);
        set_skill("unarmed", 100);
        set_skill("taiji-quan", 200);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("liangyi-jian", 200);
        set_skill("taiji-jian", 100);
        set_skill("literate", 100);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),                
        }) );
        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "taiji-jian");
	set("chat_chance", 20);
        set("chat_msg", ({
            "张翠山恶狠狠地说道：没有两把刷子，我敢来解剑岩？",
            "张翠山仰天叹道：哪个巫师帮我找到素素，我请鸭庄一顿。"
        }));

        create_family("武当派", 2, "弟子");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/bluecloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",2 , ob);
        }
}

void greeting(object ob)
{
        if ((int)ob->query("shen") < 0)
        {
    if (environment(ob)->query("short")=="解剑岩"){
            say(CYN"\n\n张翠山脸现怒容：“邪魔外道，吃了豹子胆了，敢强闯武当！”\n\n");
            message_vision("张翠山居高临下，起手一掌，$N只得硬接，身子晃了一下。\n",ob);
            message_vision("对方右手长剑随即递出，$N无法招架，退了一步。\n\n\n"NOR,ob);
            ob->move("/d/wudang/slxl2");
}
        }
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 1) {
                command("say " + RANK_D->query_respect(ob) +
                        "你对我武当派尽了多少心力，有几分忠心呢？");
                return;
        }
        if (ob->query_int() < 30)
        {
                command("say 你的资质将来到不了铁划银钩的境界，收你也是白搭。\n");
                return;
        }
        if ((int)ob->query("shen") < 0) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
}
