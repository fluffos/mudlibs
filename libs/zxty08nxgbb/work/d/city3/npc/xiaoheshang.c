// Npc: /chengdu/npc/xiaoheshang.c
// Date: oooc 1998/06/26

inherit NPC;


void create()
{
        set_name("小和尚", ({
                "xiao heshang",
                "xiao",
                "heshang",
	}));
	set("long",
                "这是位年轻的和尚,看他虔诚的样子,长大后肯定是位得道高僧。\n"
	);


	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

        set("age", 14);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
        set("max_qi", 100);
        set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
        set("combat_exp", 1000);
        set("score", 50);

        set_skill("force", 8);
        set_skill("dodge", 8);
        set_skill("unarmed", 8);
        set_skill("parry", 8);

	setup();

}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
            say( "小和尚双手合什说道：这位施主，你来进香?\n");
			break;
		case 1:
            say( "小和尚摸了摸自己的光头，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
	}
}

