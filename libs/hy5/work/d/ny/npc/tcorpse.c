
// tao_2.c

inherit NPC;

void create()
{
        set_name("吸血僵尸", ({ "tcorpse" }) );
        set("gender", "男性");
        set("age", 32);
        set("long",
                
"吸血僵尸浑身散发着一股腐烂的尸臭味儿，正向你扑来。。。\n"
);
        set("combat_exp", 8000);
        set("score", 300);

        set("str", 30);
        set("int", 10);
        set("cor", 30);
        set("cps", 30);
        set("spi", 20);
	set("per", 1);
	set("con", 30);
        set("pursuer", 1);

        set("force", 150);
        set("max_force", 150);
        set("force_factor", 5);

        set("atman", 150);
        set("max_atman", 150);

        set("mana", 400);
        set("max_mana", 400);
        set("mana_factor", 10);
	set("attitude","aggressive");
        set("chat_chance", 25);

        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: command("say 好久没有吃到这么新鲜的人肉了！你来的正好！"):),
             	(: command("say 看来想吃这人肉还真不容易。。"):),
		(: command("吸血僵尸发出一阵怪叫：ソ々。～ぃ"):),
		(: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
                (: command("cast animate on corpse") :),
                (: command("cast animate on corpse") :),         
        }) );

        set_skill("magic", 50);
        set_skill("force", 30);

        set_skill("unarmed", 60);
        set_skill("parry", 30);
        set_skill("dodge", 30);


        set_skill("taoism", 50);
        set_skill("necromancy", 30);    



        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);

        setup();



}
