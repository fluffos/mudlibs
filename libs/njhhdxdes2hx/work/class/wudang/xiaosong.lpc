// xiaosong.c 宋青书
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("宋青书", ({ "song qingshu", "song" }));
	set("title",RED "武当" NOR + GRN "侠客" NOR);
        set("long",
                "他就是宋远桥的儿子宋青书。\n"
                "他今年二十岁，乃是武当第三代中出类拔萃的人物。\n");
        set("gender", "男性");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 28);
        set("con", 25);
        set("dex", 25);

        set("max_kee", 1000);
        set("max_gin", 500);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 30);
        set("combat_exp", 80000);
        set("score", 10000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: exert_function , "powerup" :)
        }) );

        set_skill("force", 60);
        set_skill("taiji-shengong", 40);
        set_skill("dodge", 70);
        set_skill("tiyunzong", 40);
        set_skill("cuff", 70);
        set_skill("taiji-quan", 50);
        set_skill("parry", 70);
        set_skill("sword", 70);
        set_skill("taiji-jian", 50);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");

        create_family("武当派", 3, "弟子");

        setup();
        carry_object("/obj/weapon/changjian")->wield();
}
void init()
{
        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();

        if (interactive(ob)
        && !environment(ob)->query("no_fight")
        && ( (fam = ob->query("family")) 
	&& fam["family_name"] == "武当派" 
	&& ob->query("shen")< -100))
        {
                command("say 你身为武当弟子，确杀了无数好人，纳命来吧！！！\n");
                me->set_leader(ob);
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}
