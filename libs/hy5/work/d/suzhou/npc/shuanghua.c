inherit NPC;
int ask_me();

void create()
{
        set_name("凌秋华", ({ "ling qiuhua", "ling", "qiuhua" }));
        set("long", "她长得清秀脱俗，真是人淡如菊。\n");
        set("gender", "女性");
        set("age", 18);

        set("attitude", "friendly");
        set("inquiry", ([
            "凌退之" : "他是我爹爹，你问这干吗？",
       ]) );
	set("max_qi",1000);
	set("max_jing",1000);
	set("max_neili",3000);
	set("qi",1000);
	set("jing",1000);
	set("neili",3000);
        set("combat_exp", 2000);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 5);

        set("combat_exp", 2000);
        set("shen_type", 1);
        setup();
           carry_object(__DIR__"obj/necklace")->wear();
          carry_object("/d/city/obj/pink_cloth")->wear();
}

