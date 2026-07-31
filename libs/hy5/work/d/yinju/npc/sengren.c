inherit NPC;
int ask_me();

void create()
{
        set_name("ÌìóÃÉ®ÈË", ({ "seng ren", "seng" }));
        set("gender", "ÄĞĞÔ");
        set("age", 45);

        set("combat_exp", 550000);
        set("shen_type", 1);

        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_temp("apply/attack", 400);
        set_temp("apply/defense", 400);
        set_temp("apply/armor", 400);
        set_temp("apply/damage", 200);
        
        set("inquiry", ([
		"ÁÆ¶¾" : (:ask_me:),
	  ]) );


        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
int ask_me()
{
	object me;
	me=this_player();
                if (me->query_condition("drunk"))
			me->apply_condition("drunk",0);
		if (me->query_condition("flower_poison"))
			me->apply_condition("flower_poison",0);
		if (me->query_condition("ice_poison"))
			me->apply_condition("ice_poison",0);
		if (me->query_condition("iceshock"))
			me->apply_condition("iceshock",0);
		if (me->query_condition("rose_poison"))
			me->apply_condition("rose_poison",0);
		if (me->query_condition("sanxiao_poison"))
			me->apply_condition("sanxiao_poison",0);
		if (me->query_condition("scorpion_poison"))
			me->apply_condition("scorpion_poison",0);
		if (me->query_condition("slumber_drug"))
			me->apply_condition("slumber_drug",0);
		if (me->query_condition("snake_poison"))
			me->apply_condition("snake_poison",0);
		if (me->query_condition("ss_poison"))
			me->apply_condition("ss_poison",0);
		if (me->query_condition("xx_poison"))
			me->apply_condition("xx_poison",0);
		if (me->query_condition("zhua_poison"))
			me->apply_condition("zhua_poison",0);
               me->start_busy(2);
	       return 1;

}




        