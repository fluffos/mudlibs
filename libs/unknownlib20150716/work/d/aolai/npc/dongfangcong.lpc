inherit NPC;

void create()
{
        set_name("东方聪", ({ "dongfang cong", "dongfang", "cong"}) );
        set("gender", "男性" );
        set_level(15);
        set("age", 22);
        set("long", "东方聪是馆主的大儿子，正教一些徒弟武艺。\n");
	set("title", "武馆教头");
	set_skill("stick", 150);
	set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("unarmed", 150);
	set_skill("force", 150);
	set("skill_public",1);
        setup();
        add_money("silver", 1+random(20));
        carry_object(0,"cloth",random(2))->wear();
        carry_object(0,"shoes",random(2))->wear();
        carry_object(0,"hand",random(2))->wear();
        powerup(1,1);
}

int recognize_apprentice(object who)
{
	if( !who || !userp(who) )
		return 0;
	if( who->query("class") )
		return notify_fail("东方聪笑道："+RANK_D->query_respect(who)+"莫要消遣小的了。\n");
	if( !who->query_temp("aolai_dongfang") )
		return notify_fail("东方聪笑道：教不教你，你去问爹。\n");
	return 1;
}
