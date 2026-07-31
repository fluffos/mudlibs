 // liangfa.c 梁发

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("梁发", ({ "liang fa", "liang" }));
        set("title",GRN "华山派" NOR + YEL +"剑侠" NOR);
        set("long",
                "他是岳不群的三弟子梁发。\n"
        );
        set("gender", "男性");
        set("age", 27);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 24);
        set("con", 28);
        set("dex", 28);

        set("max_kee", 1000);
        set("max_gin", 1000);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 50);
        set("combat_exp", 15000);
        set("score", 7000);

        set_skill("force", 60);
        set_skill("huashan-neigong", 70);
        set_skill("dodge", 70);
        set_skill("huashan-shenfa", 70);
        set_skill("cuff", 60);
        set_skill("poyu-quan", 60);
        set_skill("parry", 80);
        set_skill("sword", 60);
        set_skill("huashan-jianfa", 60);
//      set_skill("literate", 50);

        map_skill("force", "huashan-neigong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("cuff", "poyu-quan");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");
        prepare_skill("cuff", "poyu-quan");

        create_family("华山派", 19, "弟子");


        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/huishan")->wear();

}

void attempt_apprentice(object ob)
{
        command("say 师傅没让我收徒。");
        return;
}

void init()
{

        object me, ob;
        mapping fam;

        ::init();

        ob = this_player();
        me = this_object();
        if (present("letter paper", this_player()))
        {
                me->set_leader(ob);
        	call_out("kill_ob", 1, this_player());
        	command("say 你擅自拿师傅的书信，还想出华山，拿命来。");
        }
}
