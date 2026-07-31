// guinu.c ¹êÅ«

inherit NPC;

void create()
{
	set_name("¹êÅ«", ({ "guinu" }));
	set("gender", "ÄĞĞÔ");
	set("age", 35);

	set("combat_exp", 4000);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
	set("shen_type", -1);
	setup();

	add_money("silver",3);
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
	
