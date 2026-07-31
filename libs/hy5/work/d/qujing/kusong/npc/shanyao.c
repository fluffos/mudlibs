//Cracked by Roath
inherit NPC;
void create()
{
        set_name("É½Ñı", ({"shan yao", "yao"}));
        set("long", "Ò»¸öĞ×Éñ¶ñÉ·°ãµÄÉ½Ñı¡£\n");
        set("age", 30);
        set("attitude", "herosim");
        set("gender", "ÄĞĞÔ");
        set("class", "yaomo");
        set("per", 10);
        set("max_qi",800);
        set("max_jing", 800);
        set_temp("apply/damage", 15);
        set_temp("apply/armor", 15);
        set("combat_exp", 50000);
  set("combat_exp", 40000);


        set("eff_dx", -20000);
        set("nkgain", 200);

        set("neili", 2000);
        set("max_neili", 2000);
        set("neili",1000);
        set("max_neili", 1000);
        set("force_factor", 20);
        set("mana_factor", 10);
        set_skill("unarmed", 40);
        set_skill("force", 40);
        set_skill("spells", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("blade", 40);
        set_skill("wind-blade", 340);
        map_skill("blade", "wind-blade");
        map_skill("parry", "wind-blade");
        setup();
        carry_object("/d/obj/armor/shoupi")->wear();
        carry_object("/d/obj/weapon/blade/kandao")->wield();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 30, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;

        command("look " + ob->query("id") );
        command("say ÓÖ°×ÓÖÅÖ£¬¸ÕºÃÈÃÀÏ×ÓÏÂ¾Æ£¡");
        command("chan " + ob->query("id") );
	command("kill " + ob->query("id") );

        return;
}

ÿ