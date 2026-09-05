// guanchai.c 官差
// write by www

inherit NPC;

void create()
{
        set_name("官差", ({ "guan chai", "chai" }));
        set("age", 22);
        set("gender", "男性");
        set("long", "官差是奉命追杀杀害比自己很弱玩家的玩家的。\n");
        set("attitude", "peaceful");
//      set("vendetta_mark", "authority");
//      set("pursuer", 1);

        set("str", 24);
        set("dex", 16);
	set("max_neili", 1000);
	set("neili", 1000);
        set("combat_exp", 10000);
        set("shen_type", 1);

        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("blade", 40);
  	set_skill("force", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);

        setup();

        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object me, ob;
	int exp,skill;

        me = this_player();
     	ob = this_object();

        ::init();
        if( interactive(me) && me->query_temp("pk_exp") > 0 && !me->query_temp("be_killed"))
        {
		ob->set("killer_id", me->query("id"));
		me->set_temp("be_killed",1);
		ob->set("kill_id", me->query("id"));
		exp=me->query_temp("pk_exp")*1.5;
		ob->set("combat_exp", exp);
		skill=10;
		while (skill * skill * skill < exp * 10)
			skill+=5;
		if ( skill > 200 ) skill=200;
		ob->set_skill("dodge", skill);
		ob->set_skill("parry", skill);
		ob->set_skill("tiyunzong", skill);
		ob->set_skill("taiji-jian", skill);
		ob->set_skill("sword", skill);
		ob->set_skill("force", skill);
		ob->set_skill("taiji-shengong", skill);

		ob->map_skill("sword", "taiji-jian");
		ob->map_skill("parry", "taiji-jian");
		ob->map_skill("dodge", "tiyunzong");
		ob->map_skill("force", "taiji-shengong");		

		kill_ob(me);
        }

        return;
}

