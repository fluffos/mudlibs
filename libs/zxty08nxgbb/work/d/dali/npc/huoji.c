// huoji 石辅伙计
 inherit NPC;
void create()
{
        set_name("石铺伙计", ({ "shipu huoji", "huoji" }));
        set("str", 20);
        set("gender", "男性");
        set("age", 18);
        set("long", "长期的石辅工作使看上去十分强壮，好象还会几分武功，\n");
        set("combat_exp", 2500);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear();
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

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
