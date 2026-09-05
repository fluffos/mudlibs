// 大汉 zine Oct 6 2010

inherit NPC;

void create()
{
        set_name("大汉", ({ "da han", "han", "man" }));
        set("gender", "男性");
        set("age", 30+ random(20));
        set("str", 10);
        set("dex", 100);
        set("long", "他浑身肌肉虬结，一看就不是善茬。\n");
        set("combat_exp", 75000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("strike", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("banruo-zhang",60);
        map_skill("strike", "banruo-zhang");
        prepare_skill("strike", "banruo-zhang");
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 30);
		set("qi",1000000);
		set("max_qi",1000000);
        set("neili", 400); 
        set("max_neili", 400);
        set("jiali", 10);

        setup();
        
		carry_object(__DIR__"items/cloth2")->wear();
}

void init()
{
	if(interactive(this_player()))
	{
		command("fight hongyi nvzi");
	}
}
