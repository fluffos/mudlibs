
// flower_worker.c

inherit NPC;

void create()
{
        set_name("花匠", ({ "flower worker", "worker" }) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "花匠正在忙碌着。\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
          set("str",15);
          set("con",30);
          set("cor",30);
          set("max_kee",300);
          set("max_force",500);
          set("force",500);
          set("kee",300);
        set_skill("unarmed", 20);
        set_skill("parry", 20);
	set_skill("dodge", 30);
	set_skill("throwing", 10);

        set("inquiry", ([
		"碧海银针" : "这要到香茗坊去问。", 
        ]) );

	setup();
	add_money("coin", 15);
        carry_object("/clone/misc/cloth")->wear();
}

