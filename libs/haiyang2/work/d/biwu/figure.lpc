inherit NPC;
//inherit F_SKILL;

void create()
{
	set_name("无常", ({ "figure", "wuchang" }));
	set("title", "黑衣人");
	set("gender", "男性");
	set("age", 43);
	set("str", 20);
	set("dex", 20);
	set("long", "一个全身穿黑衣的家伙。\n");
	set("combat_exp", 2000000);
	set("shen_type", 0);
	set("attitude", "heroism");

	set_skill("unarmed", 350);
	set_skill("force", 350);
	set_skill("sword", 350);
	set_skill("dodge", 350);
	set_skill("parry", 350);
	set("max_qi",5500);
	set("qi",5500);
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/armor", 150);
	set_temp("apply/damage", 115);

	set("neili", 5500); 
	set("max_neili", 5500);
	set("jiali", 10);

	setup();
	carry_object(__DIR__"obj/sword")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}



