// cheng-buyou.c  成不忧
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("成不忧", ({ "cheng buyou", "cheng" }) );
        set("gender", "男性");
        set("class", "swordsman");
        set("title", "华山剑宗第十三代弟子");
        set("age", 41);
        set("long",
                "一个白净面皮的矮子，可也不能小看他。\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 14000);
        set("max_neili", 12400);
        set("jiali", 30);
        set("max_qi",12000);
        set("max_jing",11200);

        set("combat_exp", 5000000);
        set("shen", -200000);
        set("apprentice_available", 3);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
              (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jie" :),
                (: perform_action, "sword.xian" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),   
                (: perform_action, "sword.feilong" :),
                (: exert_function, "powerup" :),
        }) );
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        set_skill("unarmed", 80);
        set_skill("sword", 250);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("literate", 100);
        set_skill("huashan-sword", 350);
        set_skill("huashan-neigong", 150);
        set_skill("huashan-ken", 80);
        set_skill("huashan-zhangfa", 180);
        set_skill("huashan-shenfa", 120);
        set_skill("zhengqijue",200);
        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "huashan-neigong");
        map_skill("unarmed", "huashan-zhangfa");
        map_skill("dodge", "huashan-shenfa");

        create_family("华山派剑宗", 13, "弟子");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if(ob->query("family/master_id") != "yue buqun")
              say ("成不忧说：这位"+RANK_D->query_respect(ob) + "，来投我剑宗吧。\n");
        else
        {
              message_vision("成不忧一见$N就大怒：我最讨厌伪君子的徒弟了。\n", ob);
              this_object()->kill_ob(ob);
        }
        return;
}

void attempt_apprentice(object ob)
{
        command("say 老夫从不收徒，你找我封师兄好了。");
}

