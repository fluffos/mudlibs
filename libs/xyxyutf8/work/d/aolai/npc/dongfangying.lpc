inherit NPC;

void create()
{
        set_name("东方英", ({ "dongfang ying", "dongfang", "ying"}) );
        set("gender", "女性");
        set_level(19);
        set("age", 22);
	set("per", 35);
        set("long", "东方英是馆主的独生女，武功又高，人又漂亮。\n");
	set("title", "武馆教头");
	set_skill("sword",190);
	set_skill("parry",190);
        set_skill("dodge",190);
        set_skill("unarmed",190);
	set_skill("force",190);
	set("skill_public",1);
	set("env/test",({"HIY","HIB","HIG"})[random(3)]);
        setup();
        add_money("silver", 1+random(20));
	carry_object(0,"cloth",1)->wear();
        carry_object(0,"shoes",1)->wear();
        carry_object(0,"hand",1)->wear();
        carry_object(0,"neck",1)->wear();        
	carry_object(0,"ring",1)->wear();
	carry_object(0,"sword",1)->wield();
        powerup(0,1);
}

int recognize_apprentice(object who)
{
	if( who->query("class") )
		return notify_fail("东方英害羞地一笑："+RANK_D->query_respect(who)+"莫要消遣小女子了。\n");
	if( !who->query_temp("aolai_dongfang") )
		return notify_fail("东方英害羞地一笑：爹要是不同意，我可不敢教。\n");
        return 1;
}