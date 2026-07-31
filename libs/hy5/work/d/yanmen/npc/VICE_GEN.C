#pragma save_binary
// general.c

inherit NPC;


void create()
{
        set_name("李信", ({ "vice general","general" }));
	set("title","副将");
	set("gender", "男性");
	set("age", 40);
	set("long",
                "原是禁卫军的队长，也因其强大的声望和实力，被先帝调离京师\n"
                "和镇国大将军共同镇守黄石隘口。\n");

	set("attitude", "peaceful");

	set("str", 27);
	set("int", 25);

	set("force", 800);
	set("max_force", 800);
	set("force_factor", 10);
	set("max_gin", 200);
	set("eff_gin", 200);
	set("gin", 200);
	set("max_sen", 200);
	set("eff_sen", 200);
	set("sen", 200);
	
	set("combat_exp", 400000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
	}) );
	
	set_skill("sword", 380);
	set_skill("taiji-jian", 385);
	set_skill("force", 380);
	set_skill("taiji-quan", 380);
	set_skill("parry", 350);
	set_skill("dodge", 360);
	//set_skill("pyrobat-steps", 60);
	set_skill("unarmed", 380);
	//set_skill("celestrike", 85);
	
	map_skill("sword", "taiji-jian");
	map_skill("parry", "taiji-jian");
	map_skill("force", "taiji-shengong");
	map_skill("unarmed", "taiji-quan");
	
	
	setup();

	carry_object("/clone/weapon/gangjian")->wield();
	carry_object( __DIR__"obj/armor")->wear();
}

void init()
{
	object ob;
	
	:: init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
        	remove_call_out("greeting");
        	call_out("greeting",0,ob);
        }
}

void greeting(object ob)
{
        if ( !ob || environment(ob) != environment() ) return;
        if ( !ob->query("marks/军营") )	{
        	command("say 大胆狂徒，竟私闯此地，给我滚出去");
                //ob->move(PATH);

        }
        return;
}
