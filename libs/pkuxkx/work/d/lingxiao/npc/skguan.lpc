inherit NPC;

void create()
{
        set_name("店小二", ({ "xiao er", "xiao" }));
        set("gender", "男性");
        set("age", 19);
        set("long", "他是棺材店的伙计,脸色苍白,可能是在和死人打交道太多的缘故。\n");
        
        set("combat_exp", 100000);
        set("shen_type", -1);

        set("attitude", "peaceful");
        
        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("parry",200);
        set_temp("apply/attack", 1000);
        set_temp("apply/defense", 1000);

        set("inquiry", ([  //add by iszt, 2006-08-14
                "name" : "大爷我姓甚名谁关你什么事？走开，别烦我！",
                                        ]) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

