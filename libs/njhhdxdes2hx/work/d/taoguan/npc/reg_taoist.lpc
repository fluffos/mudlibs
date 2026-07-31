inherit NPC;

void create()
{
        set_name("道士", ({ "taoist" }) );
        set("gender", "男性");
        set("age", 32);
        set("long",
"茅山派的道士，着一身黑色的道袍\n"
);
        set("combat_exp", 10000);
        set("score", 200);

        set("class", "taoist");

        set("int", 30);
        set("cps", 30);
        set("spi", 30);

        set("force", 150);
        set("max_force", 150);
        set("force_factor", 5);

        set("atman", 150);
        set("max_atman", 150);

        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5);

        set("inquiry", ([
                "谷衣心法": 
"谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
                "茅山派": 
"我茅山派自张天师开山立派至今，世世代代皆以降妖伏魔为己任。\n"
        ]) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) );

        create_family("茅山派", 6, "弟子");

        set_skill("literate", 40);
        set_skill("magic", 20);
        set_skill("force", 20);
        set_skill("spells", 50);
        set_skill("unarmed", 40);
        set_skill("sword", 40);
        set_skill("parry", 50);
        set_skill("dodge", 30);
        set_skill("gouyee", 50);

        map_skill("force", "gouyee");

        set_skill("taoism", 60);
        set_skill("necromancy", 50);    

        map_skill("spells", "necromancy");

        set_temp("apply/dodge", 25);
        set_temp("apply/armor", 25);

        setup();

        add_money("silver", 10);
        carry_object("/d/taoguan/obj/sword1")->wield();

}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="茅山派" ) {
                command("nod");
                command("say 进招吧。");
                return 1;
        }
        command("say 茅山派不和别派的人过招。");
        return 0;
}
 
