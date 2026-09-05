inherit NPC;


void create()  
{	set_name("襄阳守将", ({ "shou jiang","jiang" }));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 45);
	set("dex", 26);
	set("long", "他站在那里，浑身杀气,让人心惊胆寒。\n");
	set("combat_exp", 100000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 90);
	set_skill("force", 80);
	set_skill("halberd", 90);
	set_skill("lujia-ji", 90);
	set_skill("dodge", 80);
	set_skill("parry", 80);

	map_skill("halberd", "lujia-ji");
	map_skill("parry", "lujia-ji");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 800); 
	set("max_neili", 800);
	set("jiali", 50);

        set("chat_chance", 10);
        set("chat_msg", ({
       "郭大侠嘱咐,一定要加强防范,不能让鞑子兵混进城里.\n
但对那些立志投军报国的壮士我们可不能怠慢.\n"
        }) );

        setup();
	carry_object("/clone/weapon/fangtianji")->wield();
	carry_object(__DIR__"obj/tiejia")->wear();

}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

