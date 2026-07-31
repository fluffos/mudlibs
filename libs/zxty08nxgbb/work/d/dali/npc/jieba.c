//jieba.c 大理街霸

inherit NPC;

void create()
{
        set_name("大理街霸",({"jie ba","jie","ba" }));
        set("gender", "男性");
        set("age",24);
        set("long",
"这个家伙就大理臭名远扬的街霸，武功不高就会人多欺人少. \n");
        set_skill("blade", 80);
        set_skill("force", 80);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_temp("apply/damage", 15);
        set("combat_exp", 55000);
        set("attitude", "friendly");
        set("chat_chance_combat", 10);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();

}
void init()
{
        ::init();
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
}

int accept_fight(object me)
{
        command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
        me->apply_condition("killer", 500);
        kill_ob(me);
        return 1;
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
