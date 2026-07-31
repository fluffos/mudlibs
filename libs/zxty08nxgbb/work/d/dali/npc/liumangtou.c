// liumangtou.c 流氓头
inherit NPC;
void create()
{
        set_name("流氓头", ({ "liumang tou", "liumang", "tou" }));
        set("gender", "男性");
        set("age", 25);
        set("long", "他长得奸嘴猴腮的，一看就不像是个好人。\n");
        
        set("combat_exp", 7000);
        set("shen_type", -1);
        set("attitude", "peaceful");
        
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        setup();
        carry_object("/clone/misc/hic_cloth")->wear();
        add_money("silver", 2);
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
